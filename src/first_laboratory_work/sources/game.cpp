#include "first_laboratory_work/game.h"
#include "ros/ros.h"

Game::Game(class Hero *hero, class Path * path)
{
    this->hero = hero;
    this->path = path;
}

bool Game::makeStep(first_laboratory_work::choose_path::Request &req, first_laboratory_work::choose_path::Response &res)
{
    if (req.turn != 'l' && req.turn != 'r')
    {
        ROS_INFO("You have to use \'l\' or \'r\'!!!!!");
        return false;
    }

    if (req.turn == 'l')
    {
        ROS_INFO("You have taken the left side");
        this->hero->setStep('l');
        res.condition = this->checkPossibilityToContinueGame(this->hero->getStepQuantity());
        return true;
    }

    if (req.turn == 'r')
    {
        ROS_INFO("You have taken the right side");
        this->hero->setStep('r');
        res.condition = this->checkPossibilityToContinueGame(this->hero->getStepQuantity());
        return true;
    }
}

bool Game::checkPossibilityToContinueGame(int position_to_check)
{
    char currentPathStep = this->path->getPositionToCheck(position_to_check);
    char currentHeroStep = this->hero->getStep();
    cout << currentPathStep << endl;
    cout << currentHeroStep << endl;
    cout << this->hero->getStepQuantity() << endl;
    cout << this->path->getHolePath() << endl;
    if (currentPathStep == currentHeroStep)
    {
        this->hero->setStepQuantity(this->hero->getStepQuantity() + 1);
        cout << this->path->checkPathEnd(this->path->getPathLength(), this->hero->getStepQuantity()) << endl;
        return true;
    }

    cout << "It was the right path... HAHA: " + this->path->getHolePath() << endl;
    cout << "Ohh... YOU'RE DEAD!" << endl;
    return false;
}