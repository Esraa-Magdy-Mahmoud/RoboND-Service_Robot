#!/bin/sh
xterm  -e  "source ~/catkin_ws/devel/setup.bash; roslaunch service_robot turtlebot_world.launch " &
sleep 5

xterm  -e  " roslaunch pick_objects launch_params.launch  " &
sleep 5


xterm  -e  " roslaunch service_robot amcl_demo.launch  " &
sleep 5

xterm  -e  " rosrun pick_objects pick_objects  " &
sleep 5


xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " 


