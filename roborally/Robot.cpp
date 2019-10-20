#include "pch.h"
#include "Robot.h"


Robot::Robot(std::string name) :
	Piece(),
	name_(std::move(name)),
	direction_(Direction::UP),
	my_cell_(0)
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

void Robot::moveMe(std::size_t new_cell_index)
{
	my_cell_ = new_cell_index;
}

std::size_t Robot::cell() const
{
	return my_cell_;
}
