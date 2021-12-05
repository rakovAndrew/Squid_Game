#ifndef first_laboratory_work_GAME_H
#define first_laboratory_work_GAME_H

#include "first_laboratory_work/Hero.h"
#include "first_laboratory_work/Path.h"
#include "../../../../devel/include/first_laboratory_work/choose_path.h"

class Game
{
    public:
        Game(unsigned int gameSteps);

        bool makeStep(first_laboratory_work::choose_path::Request &req, first_laboratory_work::choose_path::Response &res);

    private:
        Path path;
};


#endif //first_laboratory_work_GAME_H
