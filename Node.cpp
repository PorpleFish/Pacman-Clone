#include "Node.h"

void Node::draw(bool hovered, Vector2 drawOffset)
{
	Vector2 tileDrawPosition = Vector2Add(drawOffset, { GRID_UNIT_SIZE / 2, GRID_UNIT_SIZE / 2 });
	for (Node* neighbour : neighbours)
	{
		if (hovered)
		{
			DrawLineV(
				Vector2Add(coordToScreenSpace(coord), tileDrawPosition),
				Vector2Add(coordToScreenSpace(neighbour->coord), tileDrawPosition),
				RED
			);
		}
		else
		{
			DrawLineV(
				Vector2Add(coordToScreenSpace(coord), tileDrawPosition),
				Vector2Add(coordToScreenSpace(neighbour->coord), tileDrawPosition),
				DARKPURPLE
			);
		}
	}
	if (hovered)
	{
		DrawCircleV(Vector2Add(coordToScreenSpace(coord), tileDrawPosition), 3, BLUE);
	}
	else
	{
		DrawCircleV(Vector2Add(coordToScreenSpace(coord), tileDrawPosition), 3, GREEN);
	}
}

Vector2 Node::coordToScreenSpace(Coord coord)
{
	return {
		(float)coord.x * GRID_UNIT_SIZE,
		(float)coord.y * GRID_UNIT_SIZE
	};
};