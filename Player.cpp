#include "Player.h"
#include <iostream>

void Player::update(float delta)
{
	if (inputDirection != movementDirection)
	{
		inputBuffer--;
		if (inputBuffer <= 0) {
			inputDirection = movementDirection;
		}

		// TODO: Check if pacman can move in inputDirection

		movementDirection = inputDirection;
	}

	float speed = baseSpeed * delta;
	switch (movementDirection){
	case Direction::UP:
		pos.y -= speed;
		break;
	case Direction::RIGHT:
		pos.x += speed;
		break;
	case Direction::DOWN:
		pos.y += speed;
		break;
	case Direction::LEFT:
		pos.x -= speed;
		break;
	}
}

void Player::draw(Vector2 drawOffset)
{
	DrawCircleV(Vector2Add(pos, drawOffset), 11.0f, YELLOW);
}

void Player::inputDirectionHandler(Direction newInput, int inputBufferFrames)
{
	inputDirection = newInput;
	inputBuffer = inputBufferFrames;
}
