#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

def get_twist(data):
    speed=data.linear.x;
    turn=data.angular.z;
    rospy.loginfo("Speed: [%f], Turn:[%f]", speed, turn)
    
def listener():
    rospy.init_node('monitor', anonymous=True)

    rospy.Subscriber("/jackal_velocity_controller/cmd_vel", Twist, get_twist)

    rospy.spin()

if __name__ == '__main__':
    listener()
