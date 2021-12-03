#include <tiff.h>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "../../../devel/include/first_laboratory_work/ChoosePath.h"

using namespace ros;
using namespace std_msgs;
using namespace std;

static int pathLength = 1;
static int currentPosition = 0;
static string path = "";

static void generatePath(int pathLength)
{
    srand(time(0));
    int step;
    while (path.length() < pathLength) {
        step = rand() % 2;
        if (step == 0)
        {
            path += 'l';
        }
        else
        {
            path += 'r';
        }
    }
}

string checkPathToWin(char side)
{
    if(side == path[currentPosition])
    {
        currentPosition++;
        if(currentPosition == pathLength)
        {
            currentPosition = 0;
            shutdown();
            return "You won, little peace of shit!..";
        }
        return "Good choice... Let's go to the next one!";
    }

    cout << "It was the right path... HAHA: " << path << endl;
    currentPosition = 0;
    path = "";
    shutdown();
    return "Ohh... YOU'RE DEAD!";
}

bool add(first_laboratory_work::ChoosePath::Request &req, first_laboratory_work::ChoosePath::Response &res)
{
    if(req.path != "l" && req.path != "r")
    {
        ROS_INFO("You have to use \"l\" or \"r\"!!!!!");
        return false;
    }

    if(req.path == "l")
    {
        ROS_INFO("You have taken the left side");
        res.biPath = checkPathToWin('l');
        return true;
    }

    if(req.path == "r")
    {
        ROS_INFO("You have taken the right side");
        res.biPath = checkPathToWin('r');
        return true;
    }
}

int main(int argc, char **argv)
{
    init(argc, argv, "subscriber");
    NodeHandle handler;
    generatePath(pathLength);
    ServiceServer subscriber = handler.advertiseService("path_to_win", add);
    ROS_INFO("I'm ready");
    spin();
    return 0;
}