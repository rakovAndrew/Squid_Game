#include "first_laboratory_work/Hero.h"

Hero::Hero()
{
    isAlive = true;
    step = ' ';
    stepQuantity = 0;
}

bool Hero::getLifeInfo()
{
    return isAlive;
}

void Hero::setLifeInfo(bool isAlive)
{
    this->isAlive = isAlive;
}

char Hero::getStep()
{
    return step;
}

void Hero::setStep(char step)
{
    this->step = step;
}

int Hero::getStepQuantity()
{
    return stepQuantity;
}

void Hero::setStepQuantity(int stepQuantity)
{
    this->stepQuantity = stepQuantity;
}