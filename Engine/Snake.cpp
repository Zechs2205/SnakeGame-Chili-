#include "Snake.h"

Snake::Snake(std::mt19937& rng, Board& brd)
{
	std::uniform_int_distribution<int> randx(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> randy(0, brd.GetHeight() - 1);
	Location loc = { randx(rng),randy(rng) };
	Segment[0].initiate(loc, HeadColor, FrameColor);
}


void Snake::SnakeDraw(Board& brd)
{
	for (int i = 0; i <= iniSegment; i++) {
		Segment[i].draw(brd);
	}
}

void Snake::Moveby(Location& delta_loc, bool isinside)
{
	if (isinside) {
		for (int i = iniSegment; i > 0; i--) {
			Segment[i].follow(Segment[i - 1]);
		}
		Segment[0].Move(delta_loc);
	}
}

void Snake::Grow()
{
	if (iniSegment < maxSegment) {
		iniSegment++;
		Segment[iniSegment].initiate(Segment[iniSegment - 1].loc, 
			BodyColor, FrameColor);		
	}
}

Location Snake::Getlocation(Location& delta)
{
	Location loc = Segment[0].loc; 
	loc.Add(delta);
	return loc;
}

bool Snake::Touch()
{
	for (int i = 1; i <= iniSegment; i++) {
		if (Segment[0].loc == Segment[i].loc) {
			return true;
		}
	}
	return false;
}


bool Snake::Eat(Location & G_loc)
{
	for (int i = 0; i <= iniSegment; i++) {
		if (G_loc == Segment[i].loc) {
			return true;
		}
	}
	return false;
}

void Snake::Segment::initiate(Location& inloc, Color in_boxc, Color in_framc)
{
	loc = inloc;
	Boxc = in_boxc;
	Framec = in_framc;
}

void Snake::Segment::Move(Location& delta_loc)
{
	loc.Add(delta_loc);
}

void Snake::Segment::draw(Board& brd)
{
	brd.DrawCell(loc, Boxc, Framec);
}

void Snake::Segment::follow(Segment& nextsegment)
{
	loc = nextsegment.loc;
}

Location Snake::Segment::location()
{
	return loc;
}
