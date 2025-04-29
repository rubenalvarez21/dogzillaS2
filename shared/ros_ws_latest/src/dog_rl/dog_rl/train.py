import rclpy
from rclpy.node import Node
import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
from stable_baselines3 import DDPG
from stable_baselines3.common.noise import NormalActionNoise
from stable_baselines3.common.callbacks import BaseCallback
import csv
import os
from dog_rl.env import env

class RewardLogger(BaseCallback):
	def __init__(self, logger=None, csv_path="/shared/ep_rewards.csv", stop_reward_threshold=None, verbose=0):
		super().__init__(verbose)
		self.episode_reward = 0.0
		self.episode_step = 0
		self.episode_count = 0
		self.rl_logger = logger
		self.csv_path = csv_path
		self.stop_reward_threshold = stop_reward_threshold
		self.recent_rewards = []
		
		os.makedirs(os.path.dirname(csv_path), exist_ok=True)
		if not os.path.exists(csv_path):
			with open(csv_path, 'w', newline='') as f:
				writer = csv.writer(f)
				writer.writerow(["Episode", "Reward", "Steps"])

	def _on_step(self) -> bool:
		reward = self.locals["rewards"][0]
		done = self.locals["dones"][0]
		
		self.episode_reward += reward
		self.episode_step += 1
		
		if done:
			if self.rl_logger:
				self.rl_logger.info(f"Episode {self.episode_count} | Reward: {self.episode_reward:.3f} | Steps: {self.episode_step}")
				
			with open(self.csv_path, 'a', newline='') as f:
				writer = csv.writer(f)
				writer.writerow([self.episode_count, self.episode_reward, self.episode_step])
				
			self.recent_rewards.append(self.episode_reward)
			
			if len(self.recent_rewards) > 50:
				self.recent_rewards.pop(0)
				
			if self.stop_reward_threshold is not None:
				avg_reward = sum(self.recent_rewards) / len(self.recent_rewards)
				if avg_reward >= self.stop_reward_threshold:
					if self.rl_logger:
						self.rl_logger.info(f"Early Stopping, avg reward over last 50 eps: {avg_reward:.2f}")
					return False
		
			self.episode_count += 1
			self.episode_reward = 0.0
			self.episode_step = 0
			
		return True
		
class InitialPolicy(nn.Module):
	def __init__(self, inputs=37, h1=120, h2=120, h3=120, output=12):
		super().__init__()
		self.fc1 = nn.Linear(inputs, h1)
		self.fc2 = nn.Linear(h1, h2)
		self.fc3 = nn.Linear(h2, h3)
		self.out = nn.Linear(h3, output)
		
	def forward(self, x):
		x = F.relu(self.fc1(x))
		x = F.relu(self.fc2(x))
		x = F.relu(self.fc3(x))
		x = self.out(x)
		
		return x
		
class DDPGTrain(Node):
	def __init__(self, name):
		super().__init__(name)
		
		self.env = env()
		
		n_actions = self.env.action_space.shape[-1]
		action_noise = NormalActionNoise(mean=np.zeros(n_actions), sigma=0.1*np.ones(n_actions))
		
		self.model_path = '/shared/ddpg_finetuned.zip'
		pretrained_path = '/shared/final_initial_policy.pth'

		policy_kwargs = dict(net_arch=[120, 120, 120])
		
		if os.path.exists(self.model_path):
			self.get_logger().info("Resuming training")
			self.model = DDPG.load(self.model_path, self.env)
			self.model.action_noise = action_noise
			
		else:
			self.get_logger().info("Creating new agent")
			self.model = DDPG('MlpPolicy', self.env, action_noise=action_noise, policy_kwargs=policy_kwargs, verbose=1)
		
			try:
				pretrained = InitialPolicy()
				pretrained.load_state_dict(torch.load(pretrained_path, weights_only=True))
				pretrained.eval()
				
				with torch.no_grad():
					for sb3_param, pt_param in zip(self.model.actor.mu.parameters(), pretrained.parameters()):
						sb3_param.data.copy_(pt_param.data)				
				self.get_logger().info("Weights transferred to SB3 actor")
				print(pretrained)
				print(self.model.actor.mu)
			
			except Exception as e:
			
				self.get_logger().warn(f"Could not load pretrained model: {e}")
			
		self.train_agent()
		
	def train_agent(self):
		
		self.get_logger().info('Starting training')
		callback = RewardLogger(logger=self.get_logger(), csv_path="/shared/ep_rewards.csv", stop_reward_threshold=500)
		
		try:

			self.model.learn(total_timesteps=100000, callback=callback)
			
		except KeyboardInterrupt:
		
			self.get_logger().warn("Training interrupted manually")
			
		finally:

			self.model.save(self.model_path)
			self.get_logger().info(f"Model saved to {self.model_path}")
			self.env.close()
			rclpy.shutdown()
		
def main():
	rclpy.init()
	training_node = DDPGTrain('training_node')
	rclpy.spin(training_node)
	training_node.destroy_node()
	rclpy.shutdown()
