#pragma once


enum class Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

Direction oppositeDirection(Direction direction);
Direction clockwiseDirection(Direction direction);
Direction counterClockwiseDirection(Direction direction);