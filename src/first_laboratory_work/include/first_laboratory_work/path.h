#ifndef first_laboratory_work_PATH_H
#define first_laboratory_work_PATH_H

#include <string>
#include <ctime>
#include <cassert>
using namespace std;
#include "first_laboratory_work/hero.h"
#include "first_laboratory_work/game.h"

class Path
{
public:
    Path(unsigned int path_length);

    string getHolePath();

    int getPathLength();

    char getPositionToCheck(int step);

    bool checkPossibilityToContinueGame(int position_to_check);

    string checkPathEnd(int path_length, int stepQuantity);

private:
    unsigned int path_length;
    string path;
};

#endif //first_laboratory_work_PATH_H