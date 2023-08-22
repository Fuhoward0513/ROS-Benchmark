# ROS-Benchmark
Benchmark for ROS's performance

## Build docker
### pull docker image
    docker pull osrf/ros:noetic-desktop

### create container
    docker run -it -d --name ros-container --rm -v $PWD/ros_ws/:/root/ros_ws osrf/ros:noetic-desktop
