#ifndef first_laboratory_work_HERO_H
#define first_laboratory_work_HERO_H

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
