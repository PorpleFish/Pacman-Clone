#pragma once

#include "raylib.h"

#include "Character.h"

enum class PlayerState {
	MOVING = 1,
	STUCK = 2,
	POWERED = 3,
	DEAD = 4
};

class Player : public Char {
public:
	Player() {};

	Player(Node* startBetweenA, Node* startBetweenB) :
		Char{
			80.0f,
			"Pacman",
			startBetweenA,
			startBetweenB,
			Vector2Distance(startBetweenA->coord.getScreenPos(), startBetweenB->coord.getScreenPos()) / 2
	},
		movementDirection(Direction::RIGHT),
		inputDirection(Direction::RIGHT),
		inputBuffer(0),
		state(PlayerState::MOVING)
	{	};

	void update(float delta) override;
	void draw(Vector2 drawOffset) override;

	void inputDirectionHandler(Direction newInput, int inputBufferFrames);

private:
	Direction movementDirection;
	Direction inputDirection;

	int inputBuffer;
	PlayerState state;
};