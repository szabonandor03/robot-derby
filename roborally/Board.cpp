#include "pch.h"
#include "Board.h"
#include "Direction.h"

Board::Board(std::size_t size_x, std::size_t size_y): size_x_(size_x), size_y_(size_y), cells_(size_x_ * size_y_)
{
}


Board::~Board()
{
}



std::size_t Board::neighbor(std::size_t cell_index, Direction direction) const
{

	if ((direction == Direction::UP) && (cell_index >= size_x_)) 
		return cell_index - size_x_;

	if ((direction == Direction::DOWN) && (cell_index < size_x_ * (size_y_ - 1)))
		return cell_index + size_x_;

	if ((direction == Direction::LEFT) && (cell_index % size_x_ != 0))
		return cell_index - 1;

	if ((direction == Direction::RIGHT) && ((cell_index + 1) % size_x_ != 0))
		return cell_index + 1;
	
	return cells_.size();
}

void Board::newWall(std::size_t cell_index, Direction direction)
{
	
	cells_[cell_index].blockDirection(direction);

	std::size_t neighbor_index = neighbor(cell_index, direction);
	if (neighbor_index < cells_.size())
		cells_[neighbor_index].blockDirection(oppositeDirection(direction));

}

void Board::addRobot(std::string robot_name)
{	
	if (robots_.find(robot_name) != robots_.cend())
	{
		return;
	}

	robots_[robot_name] = std::make_shared<Robot>(robot_name); 

}

void Board::placeRobot(size_t cell_index, const std::string& robot_name)
{	
	if (robots_.find(robot_name) == robots_.cend())
	{
		return;
	}

	cells_[cell_index].addRobot(robots_.at(robot_name));
}

std::size_t Board::moveRobot(std::size_t cell_index, Direction direction)
{
	std::size_t neighbor_index = neighbor(cell_index, direction);
	if ((cell_index >= cells_.size()) || 
		(!cells_[cell_index].isDirectionFree(direction)) ||
		(cells_[cell_index].myRobot().expired()) ||
		(neighbor_index == cells_.size()))
	{
		return cell_index;
	}

	
	cells_[cell_index].removeRobot();
	if (cells_[neighbor_index].hasFloor())
	{
		cells_[neighbor_index].addRobot(cells_[cell_index].myRobot());
	}

	return neighbor_index;
}


void Board::stepCommandRobot(std::size_t cell_index, int number_of_steps)
{
	std::shared_ptr<Robot> robot = cells_[cell_index].myRobot().lock();
	if (!robot)
	{
		return;
	}
	std::size_t starting_index = cell_index;
	for (int i = 0; i < number_of_steps; ++i)
	{
		starting_index = moveRobot(starting_index, robot->direction());
	}
}

void Board::turnCommandRobot(std::size_t cell_index, bool clockwise)
{
	if ((cell_index >= cells_.size()) ||
		(cells_[cell_index].myRobot().expired()))
	{
		return;
	}
	if (clockwise)
	{
		turnRobot(cell_index, clockwiseDirection(cells_[cell_index].myRobot().lock()->direction()));
	}
	else
	{
		turnRobot(cell_index, counterClockwiseDirection(cells_[cell_index].myRobot().lock()->direction()));
	}
}

void Board::removeFloor(std::size_t cell_index)
{
	if (cell_index >= cells_.size())
	{
		return;
	}

	cells_[cell_index].removeFloor();
}

void Board::turnRobot(std::size_t cell_index, Direction direction)
{
	if ((cell_index >= cells_.size()) ||
		(cells_[cell_index].myRobot().expired()))
	{
		return;
	}

	cells_[cell_index].myRobot().lock()->setDirection(direction);

}

void Board::dump() const
{
	std::cout << "size: x = " << size_x_ << " y = " << size_y_ << std::endl;
	for (std::size_t i = 0 ; i < cells_.size(); ++i)
	{
		std::cout << i << ". cell walls: ";

		if (!cells_[i].isDirectionFree(Direction::UP))
		{
			std::cout << "up ";
		}

		if (!cells_[i].isDirectionFree(Direction::DOWN))
		{
			std::cout << "down ";
		}

		if (!cells_[i].isDirectionFree(Direction::LEFT))
		{
			std::cout << "left ";
		}

		if (!cells_[i].isDirectionFree(Direction::RIGHT))
		{
			std::cout << "right ";
		}
		
		
		auto robot = cells_[i].myRobot().lock();
		std::cout << "; robot: ";
		if (robot)
			std::cout << robot->name();
		std::cout << "; floor: " << cells_[i].hasFloor();
		std::cout << std::endl;	
	}

	
}
