#include <ros.h>
#include <std_msgs/Int16MultiArray.h>

ros::NodeHandle nh;

std_msgs::Int16MultiArray data_msg;
ros::Publisher pub("/analog_data", &data_msg);

void setup() {
  nh.initNode();
  nh.advertise(pub);
}

void loop() {
  // Read analog values from A0, A1, and A2
  int sensor_A0 = analogRead(A0);
  int sensor_A1 = analogRead(A1);
  int sensor_A2 = analogRead(A2);

  // Store values in an array
  int analog_values[] = {sensor_A0, sensor_A1, sensor_A2};

  // Publish array on the topic
  data_msg.data_length = 3;
  data_msg.data = analog_values;
  pub.publish(&data_msg);

  nh.spinOnce();
  delay(1);  // Adjust the delay based on your desired publishing frequency
}
