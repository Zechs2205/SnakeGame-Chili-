#include "Board.h"



Board::Board(Graphics& gfx)
	: 
	gfx(gfx)
{
}

void Board::DrawCell(Location& loc, Color Framc, Color Boxc)
{
	gfx.FrameRect(loc.x*dimension, loc.y*dimension,
		dimension, dimension, Framc, Boxc);
}

bool Board::insideBoard(Location & loc)
{
	bool result = loc.x >= 0 && loc.y >= 0 && 
		loc.x <= width - 1 && loc.y <= height - 1;
	return result;
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}
