#pragma once
#include "Card.h"
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
	void placeRobot(const std::string& robot_name, std::size_t cell_index);
	void stepCommandRobot(const std::string& robot_name, int number_of_steps);
	void turnCommandRobot(const std::string& robot_name, bool clockwise);

	void removeFloor(std::size_t cell_index);

	void dump(const std::string& robot_name) const;
private:
	std::size_t size_x_;
	std::size_t size_y_;
	std::vector<Cell> cells_;
	std::map<std::string, std::shared_ptr<Robot>> robots_;

	void moveRobot(const std::string& robot_name, Direction direction);
	void turnRobot(const std::string& robot_name, Direction direction);
};

