#include "first_laboratory_work/game.h"

using namespace ros;

Game::Game(class Hero* hero, class Path* path)
{
    NodeHandle handler;
    this->hero = hero;
    this->path = path;
    this->publisher = handler.advertise<String>("game_topic", 100);
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

bool Game::isGameEnd()
{
    return this->path->checkPathEnd(this->path->getPathLength(), this->hero->getStepQuantity());
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
        if (isGameEnd())
        {
            return "You won, little peace of shit!..";
        }

        String message;
        message.data = side;
        this->publisher.publish(message);

        return string("Good choice... Let's go to the next one! ") +
               "You have made this way: " +
               this->path->getHolePath().substr(0, this->hero->getStepQuantity());
    }

    this->hero->setLifeInfo(false);
    return "You're dead";
}