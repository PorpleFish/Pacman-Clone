#pragma once

#include <vector>

#include "raymath.h"

struct Node {
	Vector2 pos;
	std::vector<Node*> neighbours;

	Node() { pos = Vector2(); }
	Node(Vector2 _pos, Node** _neighbours);
};