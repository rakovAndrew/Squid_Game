#include "first_laboratory_work/game.h"
#include "ros/ros.h"

Game::Game(class Hero* hero, class Path* path)
{
    this->hero = hero;
    this->path = path;
}

bool Game::makeStep(first_laboratory_work::choose_path::Request &req, first_laboratory_work::choose_path::Response &res)
{
    if (req.turn != "l" &&
        req.turn != "left" &&
        req.turn != "r" &&
        req.turn != "right")
    {
        res.status = "You have to use \'l\' / \'left\' or \'r\' / \'right\'!!!!!";
        return true;
    }

    if (req.turn == "l" || req.turn == "left")
    {
        res.status = turn('l');
        return true;
    }

    if (req.turn == "r" || req.turn == "right")
    {
        res.status = turn('r');
        return true;
    }
}

bool Game::isHeroAlive()
{
    return this->hero->getLifeInfo();
}

bool Game::checkPossibilityToContinueGame(int position_to_check)
{
    char currentPathStep = this->path->getPositionToCheck(position_to_check);
    char currentHeroStep = this->hero->getStep();

    if (currentPathStep == currentHeroStep)
    {
        this->hero->setStepQuantity(this->hero->getStepQuantity() + 1);
        return true;
    }

    return false;
}

string Game::turn(char side)
{
    this->hero->setStep(side);

    if (this->checkPossibilityToContinueGame(this->hero->getStepQuantity()))
    {
        return "Good choice... Let's go to the next one!";
    }

    this->hero->setLifeInfo(false);
    return "You're dead";
}