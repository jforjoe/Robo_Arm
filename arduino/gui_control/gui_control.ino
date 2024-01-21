#include <ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include <Servo.h>

ros::NodeHandle nh;
Servo servo_1;
Servo servo_2;
Servo servo_3;

void jointStateCallback(const sensor_msgs::JointState& msg) {
  // Assuming that joint names are known and in the same order as expected

  // Scale and convert joint angles for servo_1
  double servoPosition_1 = (msg.position[0]) * (180.0 / (M_PI));
  servo_1.write(int(servoPosition_1));

  // Scale and convert joint angles for servo_2
  double servoPosition_2 = (msg.position[1]) * (180.0 / (M_PI));
  servo_2.write(int(servoPosition_2));

  // Scale and convert joint angles for servo_3
  double servoPosition_3 = (msg.position[2]) * (180.0 / (M_PI));
  servo_3.write(int(servoPosition_3));
}

ros::Subscriber<sensor_msgs::JointState> jointStateSub("/joint_states", &jointStateCallback);

void setup() {
  nh.initNode();
  nh.subscribe(jointStateSub);


  servo_1.attach(9);  // Attach it to pin 9 or your desired pin for joint 1
  servo_2.attach(10); // Attach it to pin 10 or your desired pin for joint 2
  servo_3.attach(11); // Attach it to pin 11 or your desired pin for joint 3

  servo_1.write(0);
  servo_2.write(0);
  servo_3.write(0);

  
}

void loop() {
  nh.spinOnce();
  delay(1);
}
