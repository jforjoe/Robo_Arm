#!/usr/bin/env python3


import rospy
from std_msgs.msg import Int16

def talker():
    pub = rospy.Publisher('num', Int16, queue_size=10)
    rospy.init_node('num_pub', anonymous=False)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        num = 24
        rospy.loginfo(num)
        pub.publish(num)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
rospy.Publisher('chatter', Int16, queue_size=10)