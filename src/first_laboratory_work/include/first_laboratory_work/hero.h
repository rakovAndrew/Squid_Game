#ifndef first_laboratory_work_HERO_H
#define first_laboratory_work_HERO_H

#include "first_laboratory_work/hero.h"

class Hero
{
public:
    Hero(void);

    bool getLifeInfo();

    void setLifeInfo(bool isAlive);

    char getStep();

    void setStep(char step);

    int getStepQuantity();

    void setStepQuantity(int stepQuantity);

private:
    bool isAlive;
    char step;
    int stepQuantity;
};


#endif //first_laboratory_work_HERO_H
