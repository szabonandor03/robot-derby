#include "pch.h"
#include "Cell.h"
#include <iostream>


Cell::Cell(): walls_({{Direction::LEFT, false}, {Direction::RIGHT, false}, {Direction::UP, false}, {Direction::DOWN, false}}),
		      floor_(true)
{
	
}


Cell::~Cell()
{
}

bool Cell::isDirectionFree(Direction direction) const
{
	return !walls_.at(direction);
}

void Cell::blockDirection(Direction direction)
{
	walls_[direction] = true;
}

void Cell::addRobot(std::weak_ptr<Robot> robot)
{
	robot_ = robot;
}

void Cell::removeRobot()
{
	robot_.reset();
}

bool Cell::hasFloor() const
{
	return floor_;
}

void Cell::removeFloor()
{
	floor_ = false;
}

std::weak_ptr<Robot> Cell::myRobot() const
{
	return robot_;
}
