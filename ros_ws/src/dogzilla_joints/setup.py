from setuptools import find_packages, setup

package_name = 'dogzilla_joints'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yahboom',
    maintainer_email='rubenalvarez02@icloud.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
	'joints_sub = dogzilla_joints.joints_sub:main',
	'joints_pub = dogzilla_joints.joints_pub:main'
        ],
    },
)
