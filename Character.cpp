#include "Character.h"

bool Char::tryTurnInDirection(Direction targetDirection)
{
	Node* nextNode;
	nextNode = currentNode->getNeighbour(targetDirection);

	if (nextNode != nullptr)
	{
		previousNode = currentNode;
		currentNode = nextNode;
		distanceToNode = Vector2Distance(
			previousNode->coord.getScreenPos(),
			currentNode->coord.getScreenPos()
		);
		return true;
	}
	return false;
}
