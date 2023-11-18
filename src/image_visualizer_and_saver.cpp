#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/highgui/highgui.hpp>

void imageCallback(const sensor_msgs::Image::ConstPtr& msg) {
    // Convert the sensor_msgs/Image to an OpenCV image
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    // Display the OpenCV image
    cv::imshow("Image Viewer", cv_ptr->image);

    // Save the OpenCV image to a file
    std::string image_filename = "/home/david/Documents/catkin_ws/src/object_detection_pkg/temp_files/image.png";  // Replace with your desired file path
    if (cv::imwrite(image_filename, cv_ptr->image)) {
        ROS_INFO("Saved image to %s", image_filename.c_str());
    } else {
        ROS_ERROR("Failed to save image to %s", image_filename.c_str());
    }

    cv::waitKey(1);  // Wait for a short time to allow the image to be displayed
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "image_viewer");
    ros::NodeHandle nh;

    ros::Subscriber sub_img = nh.subscribe("/camera/color/image_raw", 1, imageCallback);

    ros::spin();

    return 0;
}
