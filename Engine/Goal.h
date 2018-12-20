#pragma once
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd);
	void Draw(Board& brd);
	Location GetLocation(); 

	void Respawn(std::mt19937& rng, Board& brd, bool isEatten);

private:
	Location loc;
	Color c = Colors::Red;
};

