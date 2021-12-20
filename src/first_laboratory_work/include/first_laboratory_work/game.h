#ifndef first_laboratory_work_GAME_H
#define first_laboratory_work_GAME_H

#include "first_laboratory_work/hero.h"
#include "first_laboratory_work/choose_path.h"
#include "first_laboratory_work/path.h"

class Game
{
public:

    Game(class Hero *hero, class Path *path);

    bool makeStep(first_laboratory_work::choose_path::Request &req, first_laboratory_work::choose_path::Response &res);

    bool isHeroAlive();

private:
    Hero* hero;
    Path* path;

    bool checkPossibilityToContinueGame(int position_to_check);

    string turn(char side);
};


#endif //first_laboratory_work_GAME_H
