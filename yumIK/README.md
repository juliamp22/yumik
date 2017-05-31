## Run dialbox with yumi (ROS_CONTROL)
Author:  Isiah Zaplana, Aliakbar Akbari, Muhayyudin, Josep-Arnau Claret,Júlia Marsal Perendreu

To prove kinematiks inverse you need to:

1-Build the code in a catkin workspace: ~/catkin_ws$  catkin_make --only-pkg-with-deps yumik
2-Initialize roscore: make roscore in a terminal:  ~/catkin_ws$  roscore
4-Run the inverse kinematiks node: ~/catkin_ws$ rosrun yumik yumik-node
5-Run the inverse kinematiks client: ~/catkin_ws$ rosrun yumik yumik-client (change the values from the ik_client file)
