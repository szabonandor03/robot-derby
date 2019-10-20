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
	void moveMe(std::size_t new_cell_index);
	std::size_t cell() const;
private:
	std::string name_;
	Direction direction_;
	std::size_t my_cell_;
};

