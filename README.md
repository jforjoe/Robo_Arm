# ROBO_ARM
The ROBO_ARM project is a robotic arm system designed to integrate hardware and software components using ROS (Robot Operating System), MoveIt, URDF, and Gazebo. The arm is controlled by an Arduino Nano and powered by SG90 servo motors with efficient power management via a buck converter.
Key Features
- Control Stack: ROS Melodic with MoveIt for motion planning and Gazebo for simulation.
- Hardware: 4-DOF arm with SG90 servo motors, Arduino Nano for PWM control, and power management using a buck converter.
- Current Functionality: The arm mimics movements programmed in MoveIt through URDF-defined kinematics.

Future Enhancements
- Implementing inverse kinematics for autonomous Cartesian position control.
- Enhancing the system for advanced robotics applications requiring closed-loop control and sensor integration.

Learning Outcomes
- ROS ecosystem integration (URDF→MoveIt→Gazebo).
- Microcontroller-ROS communication patterns.
- Mechatronic system design with torque/power constraints.
