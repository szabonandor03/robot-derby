#pragma once
#include "Card.h"
class MovementCard :
	public Card
{
public:
	MovementCard(Board board, int number_of_steps);
	~MovementCard();
	void execute() override;


private:
	Board board_;
	int number_of_steps_;
};

