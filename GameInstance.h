#pragma once

#include <vector>

#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

#include "Constants.h"

#include "Map.h"
#include "Player.h"
#include "Ghost.h"

class GameInstance {
public:
	GameInstance();

	bool setup(bool _debug_map, bool _debug_ai);

	void run();

private:
	Map currentMap;

	std::vector<Char*> characters;

	void update(float delta);
	void draw(void);
	void pollInput(void);
	void handleVariableScreenWidth(void);
	bool debug_map; 
	bool debug_ai;
};