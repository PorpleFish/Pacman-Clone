#pragma once

#include "Character.h"

class Ghost : public Char {
public:
	Ghost() {}

	void update(float delta) override;
	void draw(void) override;
};