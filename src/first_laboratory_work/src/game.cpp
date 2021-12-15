#include "first_laboratory_work/Game.h"
#include "ros/ros.h"

Game::Game(unsigned int gameSteps)
{
    Path path;
    this->path = path;
}

bool Game::makeStep(first_laboratory_work::choose_path::Request &req, first_laboratory_work::choose_path::Response &res)
{
    if (req.turn != "l" && req.turn != "r")
    {
        ROS_INFO("You have to use \"l\" or \"r\"!!!!!");
        return false;
    }

    if (req.turn == "l")
    {
        ROS_INFO("You have taken the left side");
        this->path.hero.setStep('l');
        res.condition = this->path.checkPathCorrectness(this->path.hero.getStepQuantity());
        return true;
    }

    if (req.turn == "r")
    {
        ROS_INFO("You have taken the right side");
        this->path.hero.setStep('r');
        res.condition = this->path.checkPathCorrectness(this->path.hero.getStepQuantity());
        return true;
    }
}
