#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def chatter_callback(message):
    #get_caller_id(): Get fully resolved name of local node
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", message.data)
def talker():
		
    print("talker entered")
    
    pub = rospy.Publisher('chatting', String, queue_size=10)
  

    
    #set the loop rate
    rate = rospy.Rate(1) # 1hz
    
    i = 0
    while (i<2):
	
        hello_str = raw_input()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
        i=i+1

    

rospy.init_node('listener', anonymous=True)

    
    

rospy.Subscriber("chatter", String, chatter_callback)

    
 

while True:
        talker()
	
	



		
