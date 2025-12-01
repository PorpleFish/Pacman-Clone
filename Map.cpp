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

	nodes[5]->neighbours.push_back(nodes[13]);
	nodes[13]->neighbours.push_back(nodes[5]);

	nodes.push_back(new Node(Coord(12, 9)));
	nodes[14]->neighbours.push_back(nodes[13]);
	nodes[13]->neighbours.push_back(nodes[14]);

	nodes[14]->neighbours.push_back(nodes[4]);
	nodes[4]->neighbours.push_back(nodes[14]);

	nodes.push_back(new Node(Coord(15, 9)));
	nodes[14]->neighbours.push_back(nodes[15]);
	nodes[15]->neighbours.push_back(nodes[14]);

	nodes.push_back(new Node(Coord(15, 4)));
	nodes[16]->neighbours.push_back(nodes[15]);
	nodes[15]->neighbours.push_back(nodes[16]);

	nodes.push_back(new Node(Coord(21, 4)));
	nodes[16]->neighbours.push_back(nodes[17]);
	nodes[17]->neighbours.push_back(nodes[16]);

	nodes.push_back(new Node(Coord(27, 4)));
	nodes[18]->neighbours.push_back(nodes[17]);
	nodes[17]->neighbours.push_back(nodes[18]);

	nodes.push_back(new Node(Coord(21, 9)));
	nodes[17]->neighbours.push_back(nodes[19]);
	nodes[19]->neighbours.push_back(nodes[17]);

	nodes.push_back(new Node(Coord(27, 9)));
	nodes[20]->neighbours.push_back(nodes[19]);
	nodes[19]->neighbours.push_back(nodes[20]);

	nodes[20]->neighbours.push_back(nodes[18]);
	nodes[18]->neighbours.push_back(nodes[20]);

	nodes.push_back(new Node(Coord(18, 9)));
	nodes[19]->neighbours.push_back(nodes[21]);
	nodes[21]->neighbours.push_back(nodes[19]);

	nodes[15]->neighbours.push_back(nodes[21]);
	nodes[21]->neighbours.push_back(nodes[15]);

	nodes.push_back(new Node(Coord(18, 12)));
	nodes[22]->neighbours.push_back(nodes[21]);
	nodes[21]->neighbours.push_back(nodes[22]);

	nodes.push_back(new Node(Coord(15, 12)));
	nodes[22]->neighbours.push_back(nodes[23]);
	nodes[23]->neighbours.push_back(nodes[22]);

	nodes.push_back(new Node(Coord(15, 15)));
	nodes[24]->neighbours.push_back(nodes[23]);
	nodes[23]->neighbours.push_back(nodes[24]);

	nodes[24]->neighbours.push_back(nodes[10]);
	nodes[10]->neighbours.push_back(nodes[24]);

	nodes.push_back(new Node(Coord(18, 15)));
	nodes[24]->neighbours.push_back(nodes[25]);
	nodes[25]->neighbours.push_back(nodes[24]);

	nodes.push_back(new Node(Coord(18, 18)));
	nodes[26]->neighbours.push_back(nodes[25]);
	nodes[25]->neighbours.push_back(nodes[26]);

	nodes.push_back(new Node(Coord(21, 18)));
	nodes[26]->neighbours.push_back(nodes[27]);
	nodes[27]->neighbours.push_back(nodes[26]);

	nodes.push_back(new Node(Coord(27, 18)));
	nodes[28]->neighbours.push_back(nodes[27]);
	nodes[27]->neighbours.push_back(nodes[28]);

	nodes.push_back(new Node(Coord(21, 12)));
	nodes[27]->neighbours.push_back(nodes[29]);
	nodes[29]->neighbours.push_back(nodes[27]);

	nodes[19]->neighbours.push_back(nodes[29]);
	nodes[29]->neighbours.push_back(nodes[19]);

	nodes.push_back(new Node(Coord(27, 12)));
	nodes[30]->neighbours.push_back(nodes[29]);
	nodes[29]->neighbours.push_back(nodes[30]);

	nodes[30]->neighbours.push_back(nodes[20]);
	nodes[20]->neighbours.push_back(nodes[30]);

	return;
}

void Map::draw(Vector2 drawOffset)
{
	for (Node* node : nodes) {
		node->draw(false, drawOffset);
	}
}

Node* Map::getNodeFromScreenspace(Vector2 screenPosition, Vector2 drawOffset)
{
	Coord coordToCheck = Coord(
		((int)screenPosition.x - drawOffset.x) / GRID_UNIT_SIZE,
		((int)screenPosition.y - drawOffset.y) / GRID_UNIT_SIZE
	);

	for (Node* node : nodes)
	{
		if (node->coord == coordToCheck) return node;
	}
	return nullptr;
}

int Map::getNodeIndex(Node* node)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (node == nodes[i]) return i;
	}
	return -1;
}

Vector2 Map::coordToScreenSpace(Coord coord)
{
	return {
		(float) coord.x * GRID_UNIT_SIZE,
		(float) coord.y * GRID_UNIT_SIZE
	};
};