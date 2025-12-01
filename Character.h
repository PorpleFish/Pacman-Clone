#pragma once

#include <stdio.h>
#include <string>

#include "Constants.h"
#include "Map.h"

class Char {
public:
	Char() {};

	Char(float _baseSpeed, std::string _name, Vector2 _pos) 
		: baseSpeed(_baseSpeed), name(_name), pos(_pos) {};

	virtual void draw(Vector2 drawOffset) {};
	virtual void update(float delta) {};

	// Static:
	float baseSpeed;
	std::string name;

	// Dynamic:
	Vector2 pos;
};