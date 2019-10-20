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

void Board::placeRobot(const std::string& robot_name, std::size_t cell_index)
{	
	if (robots_.find(robot_name) == robots_.cend())
	{
		return;
	}

	robots_[robot_name]->moveMe(cell_index);
}

void Board::moveRobot(const std::string& robot_name, Direction direction)
{
	std::size_t neighbor_index = neighbor(robots_[robot_name]->cell(), direction);
	if ((cells_[robots_[robot_name]->cell()].isDirectionFree(direction)) &&
		(neighbor_index != cells_.size()) &&
		(cells_[neighbor_index].hasFloor()))
	{
		robots_[robot_name]->moveMe(neighbor_index);
	}

}


void Board::stepCommandRobot(const std::string& robot_name, int number_of_steps)
{
	std::shared_ptr<Robot> robot = robots_[robot_name];
	for (int i = 0; i < number_of_steps; ++i)
	{
		moveRobot(robot_name, robot->direction());
	}
}

void Board::turnCommandRobot(const std::string& robot_name, bool clockwise)
{
	std::shared_ptr<Robot> robot = robots_[robot_name];
	if (clockwise)
	{
		turnRobot(robot_name, clockwiseDirection(robot->direction()));
	}
	else
	{
		turnRobot(robot_name, counterClockwiseDirection(robot->direction()));
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

void Board::turnRobot(const std::string& robot_name, Direction direction)
{
	std::shared_ptr<Robot> robot = robots_[robot_name];

	robot->setDirection(direction);

}

void Board::dump(const std::string& robot_name) const
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
		
		std::shared_ptr<Robot> robot = robots_.at(robot_name);
		std::cout << "; robot: ";
		if (robot)
			std::cout << robot->name();
		std::cout << "; floor: " << cells_[i].hasFloor();
		std::cout << std::endl;	
	}

	
}
