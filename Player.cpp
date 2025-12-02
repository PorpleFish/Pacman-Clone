#include "Player.h"
#include <iostream>
void Player::update(float delta)
{
	float speed = baseSpeed * delta;

	if (inputBuffer > 0)
		inputBuffer--;
	else 
		inputDirection = movementDirection;

	switch (state)
	{
	case PlayerState::MOVING:
	{
		distanceToNode -= speed;

		if (distanceToNode < speed) // this means we're close to a node!
		{
			// if the player is trying to move in another direction:
			if (inputBuffer > 0)
			{
				if (currentNode->getNeighbour(inputDirection) != nullptr)
				{
					if (tryTurnInDirection(inputDirection)) {
						movementDirection = inputDirection;
						inputBuffer = 0;
					};
				}
				else
				{
					inputDirection = movementDirection;
					inputBuffer = 0;

					previousNode = currentNode;
					currentNode = currentNode->getNeighbour(movementDirection);

					distanceToNode = Vector2Distance(
						previousNode->coord.getScreenPos(),
						currentNode->coord.getScreenPos()
					);
				}
			}
			
			else if(currentNode->getNeighbour(movementDirection) == nullptr)
			{
				state = PlayerState::STUCK;
			}

			else 
			{
				previousNode = currentNode;
				currentNode = currentNode->getNeighbour(movementDirection);

				distanceToNode = Vector2Distance(
					previousNode->coord.getScreenPos(),
					currentNode->coord.getScreenPos()
				);
			}

		}
		break;
	}
	case PlayerState::STUCK:
	{
		if (inputBuffer > 0 && tryTurnInDirection(inputDirection))
		{
			std::cout << "dafasd";
			movementDirection = inputDirection;
			state = PlayerState::MOVING;
		}
		break;
	}
	};
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
	if (inputDirection != movementDirection) inputBuffer = inputBufferFrames;

	if (
		(inputDirection == Direction::UP && movementDirection == Direction::DOWN ||
		inputDirection == Direction::RIGHT && movementDirection == Direction::LEFT ||
		inputDirection == Direction::DOWN && movementDirection == Direction::UP ||
		inputDirection == Direction::LEFT && movementDirection == Direction::RIGHT)
		&& state == PlayerState::MOVING || state == PlayerState::POWERED
		)
	{
		Vector2 currentPos = currentNode->coord.getScreenPos();

		switch (movementDirection) {
		case Direction::UP:
			currentPos.y += distanceToNode;
			break;
		case Direction::RIGHT:
			currentPos.x -= distanceToNode;
			break;
		case Direction::DOWN:
			currentPos.y -= distanceToNode;
			break;
		case Direction::LEFT:
			currentPos.x += distanceToNode;
			break;
		}

		movementDirection = inputDirection;
		std::swap(previousNode, currentNode);

		distanceToNode = Vector2Distance(
			currentPos,
			currentNode->coord.getScreenPos()
		);
	}
}
