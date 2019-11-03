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




	bool hasFloor() const;
	void removeFloor();


private:
	std::map<Direction, bool> walls_;
	bool floor_;
};

