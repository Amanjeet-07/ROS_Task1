#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <iostream>

ros::Publisher pub;

void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  int num = msg->data;
  std_msgs::Int32 msg2;
  msg2.data = num*num;
  ROS_INFO("Subscribed: %d & Published: %d", msg->data,msg2.data);
  pub.publish(msg2);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_2");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  pub = n.advertise<std_msgs::Int32>("chatter2", 1000);

  ros::spin();

  return 0;
}
