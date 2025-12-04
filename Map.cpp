#include "Map.h"

Map::Map(int level)
{
	mapSprite = LoadTexture("./Sprites/Map.png");

	{
		nodes.push_back(new Node(Coord(1, 5)));

		nodes.push_back(new Node(Coord(1, 9)));
		connectNodes(0, 1);

		nodes.push_back(new Node(Coord(6, 5)));
		connectNodes(0, 2);

		nodes.push_back(new Node(Coord(1, 12)));
		connectNodes(1, 3);

		nodes.push_back(new Node(Coord(12, 5)));
		connectNodes(2, 4);

		nodes.push_back(new Node(Coord(6, 9)));
		connectNodes(1, 5);
		connectNodes(2, 5);

		nodes.push_back(new Node(Coord(6, 12)));
		connectNodes(5, 6);
		connectNodes(3, 6);

		nodes.push_back(new Node(Coord(6, 18)));
		connectNodes(6, 7);

		nodes.push_back(new Node(Coord(9, 18)));
		connectNodes(7, 8);

		nodes.push_back(new Node(Coord(9, 15)));
		connectNodes(8, 9);

		nodes.push_back(new Node(Coord(12, 15)));
		connectNodes(9, 10);

		nodes.push_back(new Node(Coord(12, 12)));
		connectNodes(10, 11);

		nodes.push_back(new Node(Coord(9, 12)));
		connectNodes(11, 12);

		nodes.push_back(new Node(Coord(9, 9)));
		connectNodes(12, 13);
		connectNodes(5, 13);

		nodes.push_back(new Node(Coord(12, 9)));
		connectNodes(13, 14);
		connectNodes(4, 14);

		nodes.push_back(new Node(Coord(15, 9)));
		connectNodes(14, 15);

		nodes.push_back(new Node(Coord(15, 5)));
		connectNodes(15, 16);

		nodes.push_back(new Node(Coord(21, 5)));
		connectNodes(16, 17);

		nodes.push_back(new Node(Coord(26, 5)));
		connectNodes(17, 18);

		nodes.push_back(new Node(Coord(21, 9)));
		connectNodes(17, 19);

		nodes.push_back(new Node(Coord(26, 9)));
		connectNodes(19, 20);
		connectNodes(18, 20);

		nodes.push_back(new Node(Coord(18, 9)));
		connectNodes(19, 21);
		connectNodes(15, 21);

		nodes.push_back(new Node(Coord(18, 12)));
		connectNodes(21, 22);

		nodes.push_back(new Node(Coord(15, 12)));
		connectNodes(22, 23);

		nodes.push_back(new Node(Coord(15, 15)));
		connectNodes(23, 24);
		connectNodes(10, 24);

		nodes.push_back(new Node(Coord(18, 15)));
		connectNodes(24, 25);

		nodes.push_back(new Node(Coord(18, 18)));
		connectNodes(25, 26);

		nodes.push_back(new Node(Coord(21, 18)));
		connectNodes(26, 27);

		nodes.push_back(new Node(Coord(28, 18)));
		connectNodes(27, 28);

		nodes.push_back(new Node(Coord(21, 12)));
		connectNodes(27, 29);
		connectNodes(19, 29);

		nodes.push_back(new Node(Coord(26, 12)));
		connectNodes(29, 30);
		connectNodes(20, 30);

		nodes.push_back(new Node(Coord(-1, 18)));
		connectNodes(7, 31);
		nodes[31]->warpNodeTarget = nodes[28];
		nodes[28]->warpNodeTarget = nodes[31];

		nodes.push_back(new Node(Coord(6, 24)));
		connectNodes(7, 32);

		nodes.push_back(new Node(Coord(9, 24)));
		connectNodes(32, 33);

		nodes.push_back(new Node(Coord(9, 21)));
		connectNodes(33, 34);
		connectNodes(8, 34);

		nodes.push_back(new Node(Coord(18, 21)));
		connectNodes(34, 35);
		connectNodes(26, 35);

		nodes.push_back(new Node(Coord(18, 24)));
		connectNodes(35, 36);

		nodes.push_back(new Node(Coord(21, 24)));
		connectNodes(36, 37);
		connectNodes(27, 37);

		nodes.push_back(new Node(Coord(12, 24)));
		connectNodes(33, 38);

		nodes.push_back(new Node(Coord(12, 27)));
		connectNodes(38, 39);

		nodes.push_back(new Node(Coord(15, 27)));
		connectNodes(39, 40);

		nodes.push_back(new Node(Coord(15, 24)));
		connectNodes(40, 41);
		connectNodes(36, 41);

		nodes.push_back(new Node(Coord(1, 24)));
		connectNodes(32, 42);

		nodes.push_back(new Node(Coord(26, 24)));
		connectNodes(37, 43);

		nodes.push_back(new Node(Coord(1, 27)));
		connectNodes(42, 44);

		nodes.push_back(new Node(Coord(3, 27)));
		connectNodes(44, 45);

		nodes.push_back(new Node(Coord(3, 30)));
		connectNodes(45, 46);

		nodes.push_back(new Node(Coord(1, 30)));
		connectNodes(46, 47);

		nodes.push_back(new Node(Coord(1, 33)));
		connectNodes(47, 48);

		nodes.push_back(new Node(Coord(12, 33)));
		connectNodes(48, 49);

		nodes.push_back(new Node(Coord(15, 33)));
		connectNodes(49, 50);

		nodes.push_back(new Node(Coord(26, 33)));
		connectNodes(50, 51);

		nodes.push_back(new Node(Coord(26, 30)));
		connectNodes(51, 52);

		nodes.push_back(new Node(Coord(24, 30)));
		connectNodes(52, 53);

		nodes.push_back(new Node(Coord(24, 27)));
		connectNodes(53, 54);

		nodes.push_back(new Node(Coord(26, 27)));
		connectNodes(54, 55);
		connectNodes(43, 55);

		nodes.push_back(new Node(Coord(12, 30)));
		connectNodes(49, 56);

		nodes.push_back(new Node(Coord(15, 30)));
		connectNodes(50, 57);

		nodes.push_back(new Node(Coord(9, 30)));
		connectNodes(56, 58);

		nodes.push_back(new Node(Coord(18, 30)));
		connectNodes(57, 59);

		nodes.push_back(new Node(Coord(9, 27)));
		connectNodes(58, 60);
		connectNodes(39, 60);

		nodes.push_back(new Node(Coord(18, 27)));
		connectNodes(59, 61);
		connectNodes(40, 61);

		nodes.push_back(new Node(Coord(6, 27)));
		connectNodes(60, 62);
		connectNodes(32, 62);

		nodes.push_back(new Node(Coord(21, 27)));
		connectNodes(61, 63);
		connectNodes(37, 63);

		nodes.push_back(new Node(Coord(6, 30)));
		connectNodes(62, 64);
		connectNodes(46, 64);

		nodes.push_back(new Node(Coord(21, 30)));
		connectNodes(63, 65);
		connectNodes(53, 65);
	} // MAP GENERATION
	return;
}

void Map::draw(Vector2 drawOffset, bool debug)
{
	Rectangle source = {0.0f, 0.0f, mapSprite.width,  mapSprite.height};
	Rectangle drawPostion = { drawOffset.x, drawOffset.y, 448.0f, 576.0f };
	Vector2 drawOrigin = { 0.0, 0.0f };

	DrawTexturePro(mapSprite, source, drawPostion, drawOrigin, 0.0, WHITE);

	if (debug)
	{
		for (Node* node : nodes) {
			node->draw(false, drawOffset);
		}
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
}
void Map::connectNodes(int index_a, int index_b)
{
	nodes[index_a]->neighbours.push_back(nodes[index_b]);
	nodes[index_b]->neighbours.push_back(nodes[index_a]);
}