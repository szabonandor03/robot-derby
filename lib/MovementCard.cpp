#include "pch.h"
#include "Board.h"
#include "MovementCard.h"


MovementCard::MovementCard(Board board, int number_of_steps) : Card(), board_(board), number_of_steps_(number_of_steps)
{
	
}


MovementCard::~MovementCard()
{
}

void MovementCard::execute()
{

}
