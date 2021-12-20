#ifndef first_laboratory_work_GAME_H
#define first_laboratory_work_GAME_H

#include "first_laboratory_work/hero.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "first_laboratory_work/choose_path.h"
#include "first_laboratory_work/path.h"

using namespace ros;
using namespace std_msgs;

class Game
{
public:

    Game(class Hero *hero, class Path *path);

    bool makeStep(first_laboratory_work::choose_path::Request &req, first_laboratory_work::choose_path::Response &res);

    bool isHeroAlive();

    bool isGameEnd();

private:
    Hero* hero;
    Path* path;
    Publisher publisher;

    bool checkPossibilityToContinueGame(int position_to_check);

    string turn(char side);
};


#endif //first_laboratory_work_GAME_H
