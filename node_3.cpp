#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <iostream>

void finalOutput(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("Subscribed: %d", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter2", 1000, finalOutput);

  ros::spin();

  return 0;
}
