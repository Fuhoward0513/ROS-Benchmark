# ROS-Benchmark
This is a ROS package using ros-noetic to benchmarking and comparing the performance between different middlewares.

## Build docker
### pull docker image
    docker pull osrf/ros:noetic-desktop

### create container
    docker run -it -d --name ros-container --rm -v $PWD/ros_ws/:/root/ros_ws osrf/ros:noetic-desktop


## Run test
### Build packages
    ~# source /opt/ros/noetic/setup.bash 
    ~/ros_ws# catkin_make
    ~/ros_ws# source /devel/setup.bash 

### Run  benchmark test
    roscore
    ~/ros_ws/src/benchmark/launch# bash run.sh
