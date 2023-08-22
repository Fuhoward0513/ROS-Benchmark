#include "ros/ros.h"
#include "std_msgs/String.h"
#include "benchmark/payload.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// global 2d array to record latency
int dataNum = 10;
int cnt = 0;
std::string filename;
int32_t* DATA;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const benchmark::payload::ConstPtr& msg)
{
  ros::Time sub_t = ros::Time::now();
  // ROS_INFO("pub time: [sec: %d, nsec: %d]", msg->header.stamp.sec, msg->header.stamp.nsec);
  // ROS_INFO("sub time: [sec: %d, nsec: %d]", sub_t.sec, sub_t.nsec);
  int32_t latency = (sub_t.sec - msg->header.stamp.sec)*1000000 + (sub_t.nsec - msg->header.stamp.nsec)/1000;  // microsecond
  ROS_INFO("Subscriber: data: [%d], payloadsize: [%ld], latency: [%d us]", msg->header.seq, msg->data.size(), latency);
  DATA[msg->header.seq] = latency;

  cnt++;
  if(cnt==dataNum){  // write file
    std::cout << "------write file--------\n";
    std::cout << filename << "\n";
    std::ofstream csvFile;
    csvFile.open(filename);
    for (int i = 0; i < dataNum; ++i) {
      csvFile << std::to_string(DATA[i]);
      
      if (i < dataNum - 1) {
        csvFile << ",";
      }
    }
    csvFile << "\n";

    csvFile.close();
  }
  
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle n("~");

    std::string pub_id; // message publish from which publisher
    std::string sub_id; // subscriber id

    n.param("pub_id", pub_id, std::string("53"));
    n.param("sub_id", sub_id, std::string("53"));
    ROS_INFO("pub_id: %s", pub_id.c_str());
    ROS_INFO("sub_id: %s", sub_id.c_str());

    // filename = "sub" + sub_id + "_pub" + pub_id + ".csv";
    filename = "/root/ros_ws/src/benchmark/tmp/sub=" + sub_id + "_pub=" + pub_id + ".csv";
    DATA = new int32_t[dataNum]; // array to recording latency
    for(int i=0; i<dataNum; i++){
      DATA[i] = -1;
    }

    std::string topic_base = "/topic"; // define topic
    std::string topic = topic_base + pub_id;
    ROS_INFO("topic: %s", topic.c_str());

    int buffer_size = 1000; // define buffer size
    
    ros::Subscriber sub = n.subscribe(topic, buffer_size, chatterCallback); // start subsrcibe

    /**
     * ros::spin() will enter a loop, pumping callbacks.  With this version, all
     * callbacks will be called from within this thread (the main one).  ros::spin()
     * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
     */
    ros::spin();

    delete[] DATA;

    return 0;
}