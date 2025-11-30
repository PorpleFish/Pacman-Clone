#include "Node.h"

Node::Node(Vector2 _pos, Node** _neighbours)
{
	pos = _pos;
	for (int i = 0; i < sizeof(_neighbours); i++) {
		neighbours.push_back(_neighbours[i]);
	}
}
