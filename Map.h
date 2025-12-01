#pragma once

#include "raylib.h"

#include "Node.h"

class Map {
public:
	Map() {};
	Map(int level);

	void draw(Vector2 drawOffset);
	Node* getNodeFromScreenspace(Vector2 screenPosition, Vector2 drawOffset);
	Node* getNode(int index) { return nodes[index]; };
	int getNodeIndex(Node* node);
private:
	std::vector<Node*> nodes;
	Vector2 coordToScreenSpace(Coord coord);
	void connectNodes(int index_a, int index_b);
};