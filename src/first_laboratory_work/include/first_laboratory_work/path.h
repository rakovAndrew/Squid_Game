#ifndef first_laboratory_work_PATH_H
#define first_laboratory_work_PATH_H

#include <string>
#include <ctime>
#include <cassert>

class Path
{
public:
    Path(unsigned int path_length);

    char getPositionToCheck(unsigned step);

    bool checkPathCorrectness(int position_to_check);

    std::string checkGameEnd(int path_length, int stepQuantity);

    Hero hero;
private:
    unsigned int path_length;
    std::string path;
};

#endif //first_laboratory_work_PATH_H
