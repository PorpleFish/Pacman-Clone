#pragma once

#include "raylib.h"

#include "Node.h"

class Map {
public:
	Map() {};
	Map(int level);

	void draw();
	Node* getNodeFromScreenspace(Vector2 screenPosition);
private:
	std::vector<Node*> nodes;
	Vector2 coordToScreenSpace(Coord coord);
};