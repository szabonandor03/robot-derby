#pragma once
class Card
{
public:
	Card();
	virtual ~Card();
	virtual void execute() = 0;
};

