#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_1");

  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);

  ros::Rate loop_rate(1);

  int no = 0;
  std_msgs::Int32 num;


  while (ros::ok())
  { 
    num.data = no;
    ROS_INFO("Published: %d", num.data);
    chatter_pub.publish(num);

    ros::spinOnce();
    loop_rate.sleep();

    ++no;
  }
  return 0;
}
