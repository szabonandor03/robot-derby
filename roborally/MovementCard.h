#pragma once
#include "Card.h"
class MovementCard :
	public Card
{
public:
	MovementCard(int cell_number, int number_of_steps);
	~MovementCard();
	void execute() override;


private:
	int number_of_steps_;
};

