// roborally.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Board.h"
#include "Robot.h"
#include <iostream>
#include <memory>

int main()
{
	Board board(5, 5);
	board.addRobot("Honkey");
	board.placeRobot(11, "Honkey");
	board.newWall(2, Direction::RIGHT);
	board.newWall(12, Direction::DOWN);
	board.newWall(9, Direction::RIGHT);
	board.newWall(14, Direction::RIGHT);
	board.newWall(20, Direction::DOWN);
	board.newWall(20, Direction::LEFT);
	board.removeFloor(1);
	board.dump();
	board.stepCommandRobot(11, 2);
	board.dump();
	board.turnCommandRobot(1, true);
	board.stepCommandRobot(1, 3);
	board.dump();
}

