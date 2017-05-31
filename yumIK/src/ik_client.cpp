
/*************************************************************************\
   Copyright 2017 Institute of Industrial and Control Engineering (IOC)
                 Universitat Politecnica de Catalunya
                 BarcelonaTech
    All Rights Reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the
    Free Software Foundation, Inc.,
    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 \*************************************************************************/

/* Author: Muhayyuddin, Aliakbar Akbari*/

#include <ros/ros.h>
#include <iostream>
#include "yumik/YumIK.h"

int main (int argc, char **argv)
{

    ros::init(argc, argv, "YumIK_client");
    ROS_INFO("Starting YumIK_client");

    ros::NodeHandle n;
    ros::service::waitForService("Yumi/IKSolver");
    ros::ServiceClient Yumi_client = n.serviceClient<yumik::YumIK>("Yumi/IKSolver");
    yumik::YumIK Yumi_srv;

    Yumi_srv.request.theta3 = 0;
    Yumi_srv.request.pose.position.x = -0.18;
    Yumi_srv.request.pose.position.y = 0.14;
    Yumi_srv.request.pose.position.z = 0.39;

    Yumi_srv.request.pose.orientation.x = 1.0 ;
    Yumi_srv.request.pose.orientation.y = 1.0;
    Yumi_srv.request.pose.orientation.z = 1.0;
    Yumi_srv.request.pose.orientation.w = 1.0;



    Yumi_client.call(Yumi_srv);
    ROS_INFO("YumIK service has been set!");


    std::cout<<" Inverse kinematic value is : "<<std::endl;
    for(int i=0; i<Yumi_srv.response.ikSolutions.size(); i++)
    {
        for(int j=0; j<Yumi_srv.response.ikSolutions[i].ik.size(); j++)
        {
            std::cout<<Yumi_srv.response.ikSolutions[i].ik[j]<<" ";
        }
        std::cout<<std::endl;
    }


    ros::spin();

    return 0;
}
