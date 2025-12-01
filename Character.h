#pragma once

#include <stdio.h>
#include <string>

#include "Constants.h"
#include "Map.h"

class Char {
public:
	Char() {};

	Char(float _baseSpeed, std::string _name, Node* _previousNode, Node* _currentNode, float _distanceToNode)
		: baseSpeed(_baseSpeed), name(_name), previousNode(_previousNode), currentNode(_currentNode), distanceToNode(_distanceToNode) {};

	virtual void draw(Vector2 drawOffset) {};
	virtual void update(float delta) {};

	// Static:
	float baseSpeed;
	std::string name;

	// Dynamic:
	Node* currentNode;
	Node* previousNode;
	float distanceToNode;
};