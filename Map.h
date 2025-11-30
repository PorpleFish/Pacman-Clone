#pragma once

#include "Node.h"

class Map {
public:
	Map();
	Map(int level);

	void draw();
private:
	std::vector<Node*> nodes;
};