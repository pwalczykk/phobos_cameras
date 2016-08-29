#include <ros/ros.h>

// #include "ov2640_driver.hpp"
#include "ImagePublisher.hpp"


int main(int argc, char** argv){

    ros::init(argc, argv, "ov2640_driver");
    ros::NodeHandle nh;
    ros::Rate loop_rate(10);

    ImagePublisher cam1("/nanopi/cam1", &nh);

    cam1.Init();

    while(ros::ok()){
        cam1.PublishImage();
        loop_rate.sleep();
    }

    return 0;
}
