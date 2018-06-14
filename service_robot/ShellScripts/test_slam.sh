#!/bin/sh
xterm  -e  "source ~/catkin_ws/devel/setup.bash; roslaunch service_robot turtlebot_world.launch " &
sleep 5

xterm  -e  " roslaunch service_robot gmapping.launch  " &
sleep 5


xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5

xterm  -e  " roslaunch turtlebot_teleop keyboard_teleop.launch " &