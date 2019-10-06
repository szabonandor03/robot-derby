#pragma once
#include "Direction.h"
#include "Piece.h"
#include "Robot.h"
#include <map>
#include <memory>
#include <vector>

class Cell
{
public:
	Cell();
	~Cell();
	bool isDirectionFree(Direction direction) const;
	void blockDirection(Direction direction);

	void addRobot(std::weak_ptr<Robot> robot);
	void removeRobot();

	bool hasFloor() const;
	void removeFloor();

	std::weak_ptr<Robot> myRobot() const;
private:
	std::map<Direction, bool> walls_;
	bool floor_;
	std::weak_ptr<Robot> robot_;
};

