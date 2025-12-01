#include "Player.h"
#include <iostream>

void Player::update(float delta)
{
	float speed = baseSpeed * delta;

	if (inputDirection != movementDirection)
	{
		inputBuffer--;
		if (inputBuffer <= 0) {
			inputDirection = movementDirection;
		}

		if (fabs(distanceToNode) < speed)
		{
			movementDirection = inputDirection;

			Node* nextNode;
			nextNode = currentNode->getNeighbour(movementDirection);

			if (nextNode != nullptr)
			{
				previousNode = currentNode;
				currentNode = nextNode;
				distanceToNode = Vector2Distance(
					previousNode->coord.getScreenPos(), 
					currentNode->coord.getScreenPos()
				);
				state = PlayerState::MOVING;
			}
		}
	}

	if (state == PlayerState::MOVING)
	{
		distanceToNode -= speed;

		if (distanceToNode < speed)
		{
			Node* nextNode;
			nextNode = currentNode->getNeighbour(movementDirection);
			if (nextNode != nullptr && nextNode != currentNode)
			{
				previousNode = currentNode;
				currentNode = nextNode;
				distanceToNode = Vector2Distance(
					previousNode->coord.getScreenPos(),
					currentNode->coord.getScreenPos()
				);
			}
			else
			{
				state = PlayerState::STUCK;
			}
		}
	}
}

void Player::draw(Vector2 drawOffset)
{
	Vector2 drawPos = currentNode->coord.getScreenPos();

	switch (movementDirection) {
	case Direction::UP:
		drawPos.y += distanceToNode;
		break;
	case Direction::RIGHT:
		drawPos.x -= distanceToNode;
		break;
	case Direction::DOWN:
		drawPos.y -= distanceToNode;
		break;
	case Direction::LEFT:
		drawPos.x += distanceToNode;
		break;
	}

	drawPos = Vector2Add(drawPos, drawOffset);
	drawPos = Vector2Add(drawPos, { GRID_UNIT_SIZE / 2, GRID_UNIT_SIZE / 2 });

	DrawCircleV(drawPos, 11.0f, YELLOW);
}

void Player::inputDirectionHandler(Direction newInput, int inputBufferFrames)
{
	inputDirection = newInput;
	inputBuffer = inputBufferFrames;
}
