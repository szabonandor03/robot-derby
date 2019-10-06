#pragma once
#include "Piece.h"
#include "Direction.h"
#include <string>
class Robot: public Piece
{
public:
	explicit Robot(std::string name);
	~Robot();
	std::string name() const;
	Direction direction() const;
	void setDirection(Direction direction);
private:
	std::string name_;
	Direction direction_;
};

