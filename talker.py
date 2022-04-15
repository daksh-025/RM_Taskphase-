#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    #create a new publisher. we specify the topic name, then type of message then the queue size
    pub = rospy.Publisher('chatter', String, queue_size=10)
  

  
    #set the loop rate
    rate = rospy.Rate(1) # 1hz
    
    i = 0
    while (i<2):
        hello_str = raw_input()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
        i=i+1
def chatter_callback(message):
    print("call back entered")


	
    #get_caller_id(): Get fully resolved name of local node
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", message.data)

rospy.init_node('talker', anonymous=True)
rospy.Subscriber("chatting", String, chatter_callback)

    

while True:
        talker()
     
	
