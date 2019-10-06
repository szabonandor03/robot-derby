#pragma once
#include "Cell.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
class Board
{
public:
	Board(std::size_t size_x, std::size_t size_y);
	~Board();
	std::size_t neighbor(std::size_t cell_index, Direction direction) const;

	void newWall(std::size_t cell_index, Direction direction);

	void addRobot(std::string robot_name);
	void placeRobot(std::size_t cell_index, const std::string& robot_name);
	void stepCommandRobot(std::size_t cell_index, int number_of_steps);
	void turnCommandRobot(std::size_t cell_index, bool clockwise);

	void removeFloor(std::size_t cell_index);

	void dump() const;
private:
	std::size_t size_x_;
	std::size_t size_y_;
	std::vector<Cell> cells_;
	std::map<std::string, std::shared_ptr<Robot>> robots_;
	std::size_t moveRobot(std::size_t cell_index, Direction direction);
	void turnRobot(std::size_t cell_index, Direction direction);
};

