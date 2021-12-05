#include <tiff.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "../include/first_laboratory_work/Hero.h"
#include "../include/first_laboratory_work/Path.h"
#include "../include/first_laboratory_work/Game.h"

using namespace ros;
using namespace std_msgs;

int main(int argc, char **argv)
{
    init(argc, argv, "subscriber");
    NodeHandle handler;
    Game game{18};
    ServiceServer subscriber = handler.advertiseService("path_to_win", &Game::makeStep, &game);
    //subscriber = handler.advertise<String>("game_topic", 100);
    ROS_INFO("I'm ready");
    spin();
    return 0;
}