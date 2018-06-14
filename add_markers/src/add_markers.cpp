#include <ros/ros.h>
#include <visualization_msgs/Marker.h>


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

 
  
  while (ros::ok())
  {
       
        
        visualization_msgs::Marker marker;
        marker.header.frame_id = "map";
        marker.header.stamp =  ros::Time();
        marker.type   =  visualization_msgs::Marker::CUBE;
       
        marker.scale.x = 0.3;
        marker.scale.y = 0.3;
        marker.scale.z = 0.1;
        marker.color.a = 1.0;
        marker.ns = "target";
        marker.id = 0;
        marker.pose.position.x = -0.8;
        marker.pose.position.y = -5;
       
        marker.color.r = 0.0f;
        marker.color.g = 1.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;
        marker.lifetime = ros::Duration();
         int status;
         ros::param::get("/robot_status", status);
         if (status == 0)
         {
           marker.action =  visualization_msgs::Marker::ADD;
         }
         else if(status == 1)

         {
            marker.action =  visualization_msgs::Marker::DELETE;
         }
         else
         {
           marker.pose.position.x = 4.7;
           marker.pose.position.y = -7;
           marker.action =  visualization_msgs::Marker::ADD;

         }

        marker_pub.publish(marker);


      r.sleep();
  }
}

