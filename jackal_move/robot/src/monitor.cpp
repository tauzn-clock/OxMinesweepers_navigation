#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/**
 * This tutorial is basic subsriber that outputs the robot's linear and angular speed
 */
void get_twist(const geometry_msgs::Twist::ConstPtr& msg)
{
  float speed=msg->linear.x;
  float turn=msg->angular.z;
  ROS_INFO("Speed: [%f], Turn:[%f]", speed, turn);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "monitor");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/jackal_velocity_controller/cmd_vel", 1000, get_twist);

  ros::spin();

  return 0;
}
