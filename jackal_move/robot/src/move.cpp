#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <sstream>

/**
 * This gives you the ability to alter the robot's linear and angular velocity
 */
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "move");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/jackal_velocity_controller/cmd_vel", 1000);

  ros::Rate loop_rate(1); //Edit for how frequent you want to change 

  while (ros::ok())
  {

    geometry_msgs::Twist new_Twist;

    new_Twist.linear.x=0.5;//Change how fast the robot moves, maximum x is 1
    new_Twist.angular.z=0.5;// Change how fast the robot turns, set to between -2.2 and 2.2

    chatter_pub.publish(new_Twist);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
