#pragma once

#include <vector>

#include "raylib.h"
#include "raymath.h"

#include "Constants.h"

struct Coord {
	Coord(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}

	Coord() {}

	int x;
	int y;

	bool operator==(const Coord& lhs) {
		return x == lhs.x && y == lhs.y;
	}
};

struct Node {
	Node() {}
	Node(Coord placement) : 
		coord(placement) {};

	Coord coord;
	std::vector<Node*> neighbours;

	void draw(bool hovered, Vector2 drawOffset);
private:
	Vector2 coordToScreenSpace(Coord coord);
};