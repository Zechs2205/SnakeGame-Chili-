#include "Goal.h"



Goal::Goal(std::mt19937& rng, Board& brd)
{
	std::uniform_int_distribution<int> randx(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> randy(0, brd.GetHeight() - 1);
	loc = { randx(rng),randy(rng) };
}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, c, c);
}
 
Location Goal::GetLocation()
{
	return loc;
}

void Goal::Respawn(std::mt19937& rng, Board& brd, bool isEatten)
{
	if (isEatten) {
		std::uniform_int_distribution<int> randx(0, brd.GetWidth() - 1);
		std::uniform_int_distribution<int> randy(0, brd.GetHeight() - 1);
		loc = { randx(rng),randy(rng) };
	}

	
}


