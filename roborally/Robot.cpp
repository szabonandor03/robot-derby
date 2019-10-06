#include "pch.h"
#include "Robot.h"


Robot::Robot(std::string name):
	Piece(),
	name_(std::move(name)),
	direction_(Direction::UP)
{
}


Robot::~Robot()
{
}

std::string Robot::name() const
{
	return name_;
}

Direction Robot::direction() const
{
	return direction_;
}

void Robot::setDirection(Direction direction)
{
	direction_ = direction;
}
