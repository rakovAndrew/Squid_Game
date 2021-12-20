#include <tiff.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "../include/first_laboratory_work/hero.h"
#include "../include/first_laboratory_work/path.h"
#include "../include/first_laboratory_work/game.h"


using namespace ros;
using namespace std_msgs;

int main(int argc, char **argv)
{
    init(argc, argv, "subscriber");
    NodeHandle handler;
    Hero hero;
    Path path(18);
    Game game(&hero, &path);
    ServiceServer server = handler.advertiseService("path_to_win", &Game::makeStep, (Game*) &game);
    Publisher publisher = handler.advertise<String>("game_topic", 100);
    ROS_INFO("I'm ready");
    cout << "The right path is: " + path.getHolePath() << endl;
    //spin();
    first_laboratory_work::choose_path srv;
    Rate loop_rate(100);
    while(ok())
    {
        spinOnce();
        loop_rate.sleep();
        if (!game.isHeroAlive())
        {
            srv.request.turn = "dead";
            srv.response.status = "dead";
            publisher.call(srv);
            ROS_INFO("shut");
            shutdown();
        }
    }
    ROS_INFO("end");
    return 0;
}