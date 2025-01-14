from setuptools import find_packages
from setuptools import setup

setup(
    name='dog_joint_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('dog_joint_interfaces', 'dog_joint_interfaces.*')),
)
