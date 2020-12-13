#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

def inject_twist():
    pub = rospy.Publisher('/jackal_velocity_controller/cmd_vel', Twist, queue_size=10)
    rospy.init_node('custom_jackal_movement', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        custom_twist=Twist()
	custom_twist.linear.x=-0.5
	custom_twist.angular.z=-0.5        
	
        pub.publish(custom_twist)
        rate.sleep()

if __name__ == '__main__':
    try:
        inject_twist()
    except rospy.ROSInterruptException:
        pass
