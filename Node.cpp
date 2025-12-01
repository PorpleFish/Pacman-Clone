#include "Node.h"

void Node::draw(bool hovered, Vector2 drawOffset)
{
	for (Node* neighbour : neighbours)
	{
		if (hovered)
		{
			DrawLineV(
				Vector2Add(coordToScreenSpace(coord), drawOffset),
				Vector2Add(coordToScreenSpace(neighbour->coord), drawOffset),
				RED
			);
		}
		else
		{
			DrawLineV(
				Vector2Add(coordToScreenSpace(coord), drawOffset),
				Vector2Add(coordToScreenSpace(neighbour->coord), drawOffset),
				DARKPURPLE
			);
		}
	}
	if (hovered)
	{
		DrawCircleV(Vector2Add(coordToScreenSpace(coord), drawOffset), 3, BLUE);
	}
	else
	{
		DrawCircleV(Vector2Add(coordToScreenSpace(coord), drawOffset), 3, GREEN);
	}
}

Vector2 Node::coordToScreenSpace(Coord coord)
{
	return {
		(float)coord.x * GRID_UNIT_SIZE,
		(float)coord.y * GRID_UNIT_SIZE
	};
};