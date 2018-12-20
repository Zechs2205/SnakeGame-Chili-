#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{

public:
	Board(Graphics& gfx);
	void DrawCell(Location& loc, Color Framec, Color Boxc);
	bool insideBoard(Location& loc);
	int GetWidth();
	int GetHeight();
	
private:
	static constexpr int dimension = 20;
	static constexpr int width = 6;
	static constexpr int height = 6;
	Graphics& gfx;




};

