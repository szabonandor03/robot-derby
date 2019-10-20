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
	board.placeRobot("Honkey", 11);
	board.newWall(2, Direction::RIGHT);
	board.newWall(12, Direction::DOWN);
	board.newWall(9, Direction::RIGHT);
	board.newWall(14, Direction::RIGHT);
	board.newWall(20, Direction::DOWN);
	board.newWall(20, Direction::LEFT);
	board.removeFloor(1);
	board.dump("Honkey");
	board.stepCommandRobot("Honkey", 2);
	board.dump("Honkey");
	board.turnCommandRobot("Honkey", true);
	board.stepCommandRobot("Honkey", 3);
	board.dump("Honkey");
}

