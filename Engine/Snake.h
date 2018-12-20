#pragma once
#include "Board.h"
#include <random>

class Snake
{
public:
	Snake(std::mt19937& rng, Board& brd);
	void SnakeDraw(Board& brd);
	void Moveby(Location& delta_loc, bool isinside);
	void Grow();
	Location Getlocation(Location& delta);
	bool Touch();
	bool Eat(Location& G_loc);
private:
	class Segment
	{
	public:
		void initiate(Location& inloc, Color in_boxc,
			Color in_framc);
		void Move(Location& delta_loc);
		void draw(Board& brd);
		void follow(Segment& nextsegment);
		Location location();
	public:
		Location loc;
		Color Boxc;
		Color Framec;
	};
private:
	static constexpr Color HeadColor = Colors::Blue;
	static constexpr Color BodyColor = Colors::Green;
	static constexpr Color FrameColor = Colors::Gray;
	static constexpr int maxSegment = 1000;
	int iniSegment = 0;
	Segment Segment[maxSegment];
	
	

};

