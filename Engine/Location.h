#pragma once

struct Location
{
	void Add(Location& loc) {
		x = x + loc.x;
		y = y + loc.y;
	}
	bool operator== (Location& loc) {
		return x == loc.x && y == loc.y;
	}

	int x;
	int y;
};

