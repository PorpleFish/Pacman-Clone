#include "Node.h"

void Node::draw(bool hovered, Vector2 drawOffset)
{
	Vector2 tileDrawPosition = Vector2Add(drawOffset, { GRID_UNIT_SIZE / 2, GRID_UNIT_SIZE / 2 });
	for (Node* neighbour : neighbours)
	{
		if (hovered)
		{
			DrawLineV(
				Vector2Add(coord.getScreenPos(), tileDrawPosition),
				Vector2Add(neighbour->coord.getScreenPos(), tileDrawPosition),
				RED
			);
		}
		else
		{
			DrawLineV(
				Vector2Add(coord.getScreenPos(), tileDrawPosition),
				Vector2Add(neighbour->coord.getScreenPos(), tileDrawPosition),
				DARKPURPLE
			);
		}
	}
	if (hovered)
	{
		DrawCircleV(Vector2Add(coord.getScreenPos(), tileDrawPosition), 3, BLUE);
	}
	else
	{
		DrawCircleV(Vector2Add(coord.getScreenPos(), tileDrawPosition), 3, GREEN);
	}
}

Node* Node::getNeighbour(Direction dir)
{
	Node* correctNeighbour = nullptr;
	for (Node* neighbour : neighbours)
	{
		if (dir == Direction::UP && neighbour->coord.y < coord.y)
		{
			correctNeighbour = neighbour;
			break;
		}
		if (dir == Direction::RIGHT && neighbour->coord.x > coord.x)
		{
			correctNeighbour = neighbour;
			break;
		}
		if (dir == Direction::DOWN && neighbour->coord.y > coord.y)
		{
			correctNeighbour = neighbour;
			break;
		}
		if (dir == Direction::LEFT && neighbour->coord.x < coord.x)
		{
			correctNeighbour = neighbour;
			break;
		}
	}
	return correctNeighbour;
}

Vector2 Coord::getScreenPos()
{
	return {
		(float)x * GRID_UNIT_SIZE,
		(float)y * GRID_UNIT_SIZE
	};
}
