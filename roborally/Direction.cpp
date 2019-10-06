#include "pch.h"
#include "Direction.h"


Direction oppositeDirection(Direction direction)
{
	switch (direction)
	{
	case Direction::UP:
		return Direction::DOWN;

	case Direction::DOWN:
		return Direction::UP;

	case Direction::LEFT:
		return Direction::RIGHT;

	case Direction::RIGHT:
		return Direction::LEFT;
	}
	return Direction::UP;
}

Direction clockwiseDirection(Direction direction)
{
	switch (direction)
	{
	case Direction::UP:
		return Direction::RIGHT;

	case Direction::DOWN:
		return Direction::LEFT;

	case Direction::LEFT:
		return Direction::UP;

	case Direction::RIGHT:
		return Direction::DOWN;
	}
	return Direction::UP;
}

Direction counterClockwiseDirection(Direction direction)
{
	return clockwiseDirection(oppositeDirection(direction));
}