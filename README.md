# camera_display_and_save_pkg

## Description
This ROS (Robot Operating System) package is designed to subscribe to a camera feed topic, display the image using OpenCV, and save the image to a file. It utilizes ROS publishers and subscribers, OpenCV for image handling, and cv_bridge for converting between ROS image messages and OpenCV image representation.

## Features
- **ROS Integration**: Seamlessly integrates with the ROS ecosystem.
- **Image Display**: Utilizes OpenCV to display images from a camera feed in real-time.
- **Image Saving**: Saves the camera feed images to the file system.

## Requirements
- ROS (compatible with the version you are using, e.g., ROS Noetic)
- OpenCV (compatible with the version included in your ROS distribution)
- cv_bridge (typically included with ROS distributions)

## Installation
1. Clone this repository into your catkin workspace's `src` directory:
   ```bash
   cd ~/catkin_ws/src
   git clone <repository-url>

2. From the root of your catkin workspace, compile the package:
   ```bash
   cd ~/catkin_ws
   catkin_make
3. Source your environment:
    ```bash
    source ~/catkin_ws/devel/setup.bash

## Usage
There are two ways to run the node within this package:

### Using rosrun
Run the node directly using `rosrun`:
```bash
rosrun camera_display_and_save_pkg image_viewer
```
Ensure your camera or image publisher is running and publishing to the */camera/color/image_raw* topic.
### Using roslaunch
Alternatively, you can use the included launch file to start the node. This method may be preferred if there are multiple nodes to run or if there are specific parameters set in the launch file.

To start the node with the launch file, use:
```bash
roslaunch camera_display_and_save_pkg image_visualizer_and_saver.launch
```
This will launch the image_viewer node and any other nodes or configurations specified within the launch file.

## Configuration
To change the saved image file path or the image topic, you can edit the *image_visualizer_and_saver.launch* file or the *image_viewer.cpp* source file before compiling the package. If you edit the launch file, you can specify the topic and file path as arguments.
