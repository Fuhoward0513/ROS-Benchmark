#include "ros/ros.h"
#include "std_msgs/String.h"
#include "benchmark/payload.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{   
    // std::string cString = argv[1];
    // std::string node_name = "talker_" + cString;
    ros::init(argc, argv, "talker");
    ros::NodeHandle n("~");

    std::string pub_id;
    std::string fre_str;
    std::string payloadSize;
    std::string sub_num;
    n.param("pub_id", pub_id, std::string("53"));
    n.param("fre_str", fre_str, std::string("53"));
    n.param("payload", payloadSize, std::string("53"));
    n.param("sub_num", sub_num, std::string("53"));

    std::string topic_base = "/topic";
    std::string topic = topic_base + pub_id;
    ROS_INFO("topic: %s", topic.c_str());

    int buffer_size = 10000000;
    bool latch = true;
    
    ROS_INFO("pub_id: %s", pub_id.c_str());
    ROS_INFO("fre_str: %s", fre_str.c_str());
    ROS_INFO("payload size: %s", payloadSize.c_str());
    ROS_INFO("sub_num: %s", sub_num.c_str());

    
    ros::Publisher chatter_pub = n.advertise<benchmark::payload>(topic, buffer_size);    // (topic, buffer_size, latch)
    ros::Rate loop_rate(stoi(fre_str));  // frequency Hz

    uint8_t *payload = new uint8_t[stoi(payloadSize)];
    for(int i=0; i<stoi(payloadSize); i++){
        payload[i] = 1;
    }

    ros::Duration(5).sleep();
    int dataNum = 505;
    for(int i=0; i<dataNum; i++)
    {
        /**
         * This is a message object. You stuff it with data, and then publish it.
         */
        benchmark::payload msg; // define payload
        msg.header.seq = i;
        msg.header.stamp = ros::Time::now();
        msg.header.frame_id = payloadSize;
        msg.data.assign(payload, payload + stoi(payloadSize));
        ROS_INFO("publish data: [%d], payloadsize: [%ld]", i, msg.data.size());

        /**
         * The publish() function is how you send messages. The parameter
         * is the message object. The type of this object must agree with the type
         * given as a template parameter to the advertise<>() call, as was done
         * in the constructor above.
         */

        while (chatter_pub.getNumSubscribers() == 0)
            loop_rate.sleep();
        
        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }
    delete[] payload;

    return 0;
}