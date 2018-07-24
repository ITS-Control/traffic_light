#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
//#include <geometry_msgs/PoseStamped.h>
//using namespace std;
#include<std_msgs/ColorRGBA.h>

visualization_msgs::Marker marker;

std_msgs::ColorRGBA color;
int count;

/*
void poseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    marker.pose.position.x = msg->pose.position.x;
    marker.pose.position.y = msg->pose.position.y;
    marker.pose.position.z = msg->pose.position.z + 5;
}

*/



int main( int argc, char** argv )
{
    ros::init(argc, argv, "TRAFFIC_LIGHT");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher markerPub = n.advertise<visualization_msgs::Marker>("marker", 1);
    //ros::Subscriber sub = n.subscribe("/poseidon_0/localization/pose", 1000, poseCallback);
    color.r=1;
    color.g=0;
    color.b=0;
    count=1;

    while (ros::ok())
    {
        marker.header.frame_id="map";
        marker.header.stamp = ros::Time::now();
        marker.ns = "simulation_viz";
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;
        marker.id =0;
        marker.type = visualization_msgs::Marker::SPHERE;
        marker.scale.x = 0.8;
        marker.scale.y = 0.8;
        marker.scale.z = 0.8;
        marker.color.b =color.b;
        marker.color.g =color.g;
        marker.color.r =color.r;
        marker.color.a =1;
        marker.pose.position.x=5;
        marker.pose.position.y=5;
        marker.pose.position.z=5;


        marker.lifetime = ros::Duration();
        markerPub.publish(marker);
        //ros::spinOnce();

        

        switch (count)
      {
        case 1:
            color.r=0;
            color.g=1;
            color.b=0;
            break;
        case 2:
            color.r=1;
            color.g=1;
            color.b=0;
            break;
        case 3:
            color.r=1;
            color.g=0;
            color.b=0;
            count=0;
            break;
        default:
            color.r=1;
            color.g=0;
            color.b=0;
            count=0;
        }
        count=count+1;
     r.sleep(); 
    }
}


