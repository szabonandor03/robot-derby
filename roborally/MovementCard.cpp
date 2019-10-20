#include "pch.h"
#include "board.h"
#include "MovementCard.h"


MovementCard::MovementCard(int cell_index, int number_of_steps) : Card(), number_of_steps_(number_of_steps)
{
	
}


MovementCard::~MovementCard()
{
}

void MovementCard::execute()
{

}
