#include "first_laboratory_work/path.h"

using namespace std;

Path::Path(unsigned int path_length)
{
    this->path_length = path_length;
    srand(time(0));

    int step;
    while (this->path.length() < this->path_length)
    {
        step = rand() % 2;
        if (step == 0)
        {
            this->path += "l";
        }
        else
        {
            this->path += "r";
        }
    }
}

string Path::getHolePath()
{
    return this->path;
}

int Path::getPathLength()
{
    return this->path_length;
}

char Path::getPositionToCheck(int step)
{
    char position = this->path[step];
    return position;
}

bool Path::checkPathEnd(int path_length, int step_quantity)
{
    if(step_quantity < path_length)
    {
        return false;
    }
    else
    {
        return true;
    }
}