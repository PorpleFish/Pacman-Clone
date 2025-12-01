#include "Map.h"

Map::Map(int level)
{
	nodes.push_back(new Node(Coord(1, 4)));

	nodes.push_back(new Node(Coord(1, 9)));
	nodes[0]->neighbours.push_back(nodes[1]);
	nodes[1]->neighbours.push_back(nodes[0]);

	nodes.push_back(new Node(Coord(6, 4)));
	nodes[0]->neighbours.push_back(nodes[2]);
	nodes[2]->neighbours.push_back(nodes[0]);

	nodes.push_back(new Node(Coord(1, 12)));
	nodes[1]->neighbours.push_back(nodes[3]);
	nodes[3]->neighbours.push_back(nodes[1]);

	nodes.push_back(new Node(Coord(12, 4)));
	nodes[2]->neighbours.push_back(nodes[4]);
	nodes[4]->neighbours.push_back(nodes[2]);

	nodes.push_back(new Node(Coord(6, 9)));
	nodes[1]->neighbours.push_back(nodes[5]);
	nodes[5]->neighbours.push_back(nodes[1]);

	nodes[2]->neighbours.push_back(nodes[5]);
	nodes[5]->neighbours.push_back(nodes[2]);

	nodes.push_back(new Node(Coord(6, 12)));
	nodes[6]->neighbours.push_back(nodes[5]);
	nodes[5]->neighbours.push_back(nodes[6]);

	nodes[6]->neighbours.push_back(nodes[3]);
	nodes[3]->neighbours.push_back(nodes[6]);

	nodes.push_back(new Node(Coord(6, 18)));
	nodes[6]->neighbours.push_back(nodes[7]);
	nodes[7]->neighbours.push_back(nodes[6]);

	nodes.push_back(new Node(Coord(9, 18)));
	nodes[8]->neighbours.push_back(nodes[7]);
	nodes[7]->neighbours.push_back(nodes[8]);

	nodes.push_back(new Node(Coord(9, 15)));
	nodes[8]->neighbours.push_back(nodes[9]);
	nodes[9]->neighbours.push_back(nodes[8]);

	nodes.push_back(new Node(Coord(12, 15)));
	nodes[10]->neighbours.push_back(nodes[9]);
	nodes[9]->neighbours.push_back(nodes[10]);

	nodes.push_back(new Node(Coord(12, 12)));
	nodes[10]->neighbours.push_back(nodes[11]);
	nodes[11]->neighbours.push_back(nodes[10]);

	nodes.push_back(new Node(Coord(9, 12)));
	nodes[12]->neighbours.push_back(nodes[11]);
	nodes[11]->neighbours.push_back(nodes[12]);

	nodes.push_back(new Node(Coord(9, 9)));
	nodes[12]->neighbours.push_back(nodes[13]);
	nodes[13]->neighbours.push_back(nodes[12]);

	return;
}

void Map::draw() 
{
	for (Node* node : nodes) {
		for (Node* neighbour : node->neighbours)
		{
			DrawLineV(
				coordToScreenSpace(node->coord),
				coordToScreenSpace(neighbour->coord),
				DARKPURPLE
			);
		}
		DrawCircleV(coordToScreenSpace(node->coord), 3, GREEN);
	}
}

Node* Map::getNodeFromScreenspace(Vector2 screenPosition)
{
	Coord coordToCheck = Coord(
		(int)screenPosition.x / GRID_UNIT_SIZE,
		(int)screenPosition.y / GRID_UNIT_SIZE
	);

	for (Node* node : nodes)
	{
		if (node->coord == coordToCheck) return node;
	}
	return nullptr;
}

Vector2 Map::coordToScreenSpace(Coord coord)
{
	return {
		(float) coord.x * GRID_UNIT_SIZE,
		(float) coord.y * GRID_UNIT_SIZE
	};
};