#include <iostream>

#include "raylib.h"

#include "Constants.h"
#include "Map.h"

static void setUp(void);

static void update(float delta);
static void draw(void);
static void input(float delta);

static void cleanUp(void);

Map map;
Pacman pacman;

Texture2D sprite_sheet;

int main()
{
    setUp();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update(GetFrameTime());
        draw();
        input(GetFrameTime());
    }

    cleanUp();

    return 0;
}

static void setUp(void)
{
    sprite_sheet = LoadTexture("Sprite/sheet.png");

    // View
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(24);

    map = Map();
    pacman = Pacman(&sprite_sheet);
}

static void update(float delta)
{
    pacman.update(delta, &map);
}

static void draw(void)
{
    BeginDrawing();

    ClearBackground(BLACK);

    map.draw();

    pacman.draw();

    EndDrawing();
}

static void input(float delta)
{
    pacman.input();
}

static void cleanUp(void)
{

}