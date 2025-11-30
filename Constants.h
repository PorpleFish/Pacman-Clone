#pragma once

static const int GRID_WIDTH = 28;
static const int GRID_HEIGHT = 36;
static const int GRID_UNIT_SIZE = 16;

static const int SCREEN_WIDTH = GRID_WIDTH * GRID_UNIT_SIZE;
static const int SCREEN_HEIGHT = GRID_HEIGHT * GRID_UNIT_SIZE;

enum class direction {
	NONE =  0,
	UP =    1,
	RIGHT = 2,
	DOWN =  3,
	LEFT =  4
};