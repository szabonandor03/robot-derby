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


bool Cell::hasFloor() const
{
	return floor_;
}

void Cell::removeFloor()
{
	floor_ = false;
}

