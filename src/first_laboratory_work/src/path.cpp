#include "first_laboratory_work/Hero.h"
#include "first_laboratory_work/Path.h"
#include <iostream>

using namespace std;

Path::Path(unsigned int path_length)
{
    Hero hero;
    this->path_length = path_length;
    srand(time(0));

    int step;
    while (this->path.length() < this->path_length)
    {
        step = rand() % 2;
        if (step == 0)
        {
            this->path += 'l';
        }
        else
        {
            this->path += 'r';
        }
    }
}

char Path::getPositionToCheck(unsigned int step)
{
    assert(step >= 0 &&
           step < path_length &&
           "You can't check the negative path position or check the position outside the path");
    return this->path[step];
}

bool Path::checkPathCorrectness(int position_to_check)
{
    if (this->getPositionToCheck(position_to_check) == this->hero.getStep())
    {
        this->hero.setStepQuantity(this->hero.getStepQuantity() + 1);
        cout << checkGameEnd(this->path_length, this->hero.getStepQuantity()) << endl;
        return true;
    }

    cout << "It was the right path... HAHA: " << this->path << endl;
    cout << "Ohh... YOU'RE DEAD!" << endl;
    return false;
}

string Path::checkGameEnd(int path_length, int step_quantity)
{
    if(step_quantity < path_length)
    {
        return "Good choice... Let's go to the next one!";
    }
    else
    {
        return "You won, little peace of shit!..";
    }
}
