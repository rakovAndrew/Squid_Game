#ifndef first_laboratory_work_PATH_H
#define first_laboratory_work_PATH_H

#include <string>
#include <ctime>
#include <cassert>
#include <iostream>
#include "first_laboratory_work/hero.h"

using namespace std;

class Path
{
public:
    Path(unsigned int path_length);

    string getHolePath();

    int getPathLength();

    char getPositionToCheck(int step);

    bool checkPossibilityToContinueGame(int position_to_check);

    bool checkPathEnd(int path_length, int stepQuantity);

private:
    unsigned int path_length;
    string path;
};

#endif //first_laboratory_work_PATH_H