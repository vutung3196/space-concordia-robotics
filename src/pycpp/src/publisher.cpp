#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "publisher_test");
    ros::NodeHandle nodeHandle;
    ros::Publisher chatter = nodeHandle.advertise<std_msgs::String>("publisher", 1000);
    ros::Rate loop_rate(2);
    std_msgs::String msg;
    msg.data = "Hello from C++";
    while (ros::ok()) {
        chatter.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}