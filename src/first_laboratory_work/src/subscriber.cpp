#include <tiff.h>
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

    ROS_INFO("I'm ready");
    Rate loop_rate(100);

    while(ok())
    {
        spinOnce();
        loop_rate.sleep();
        if (!game.isHeroAlive() || game.isGameEnd())
        {
            ROS_INFO("I've ended my work");
            shutdown();
        }
    }
    return 0;
}