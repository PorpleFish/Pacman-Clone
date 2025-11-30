#pragma once

#include "raylib.h"

#include "Character.h"

enum class PlayerState{
	NORMAL = 1,
	POWERED = 2,
	DEAD = 3
};

class Player : public Char {
public:
	Player() {};

	Player(Vector2 startPlace): 
		Char{ 80.0f, "Pacman", startPlace },
		movementDirection(Direction::RIGHT),
		inputDirection(Direction::RIGHT),
		inputBuffer(0)
	{ 
	};

	void update(float delta) override;
	void draw(void) override;

	void inputDirectionHandler(Direction newInput, int inputBufferFrames);

private:
	Direction movementDirection;
	Direction inputDirection;

	int inputBuffer;

};