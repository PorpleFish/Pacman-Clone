#include "GameInstance.h"
#include <iostream>

GameInstance::GameInstance()
{
    currentMap = Map(0);
    lastScreenWidth = SCREEN_WIDTH;
    lastScreenHeight = SCREEN_HEIGHT;
    drawOffset = {0.0f, 0.0f};
}

bool GameInstance::setup(bool _debug_map, bool _debug_ai)
{
    characters.push_back(new Player({14.5 * GRID_UNIT_SIZE, 14.5 * GRID_UNIT_SIZE }));

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(60);

    debug_ai = _debug_ai;
    debug_map = _debug_map;

    if (debug_ai || debug_map) {
        rlImGuiSetup(true);
    }

    return true;
}

void GameInstance::run()
{
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update(GetFrameTime());
        draw();
        pollInput();
        handleVariableScreenWidth();
    }
}

void GameInstance::update(float delta)
{
    for (Char* character : characters) character->update(delta);
}

void GameInstance::draw(void)
{
    BeginDrawing();

    ClearBackground(BLACK);

    currentMap.draw(drawOffset);
    
    for (Char* character : characters) character->draw(drawOffset);
    

    if (!debug_ai && !debug_map) {
        EndDrawing();
        return;
    }
    
    rlImGuiBegin();

    if (debug_map)
    {
        bool open;

        Node* hoveredNode = currentMap.getNodeFromScreenspace(GetMousePosition(), drawOffset);
        if (hoveredNode != nullptr)
        {
            // Draw the text for that node's index
            // Draw the text for that node's neighbours
        }
    }
    rlImGuiEnd();
    EndDrawing();
}

void GameInstance::pollInput()
{
    Player* player = nullptr;

    for (Char* character : characters)
    {
        if (character->name == "Pacman") player = (Player*)character;
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player->inputDirectionHandler(Direction::RIGHT, 30);
    if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) player->inputDirectionHandler(Direction::LEFT, 30);
    if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) player->inputDirectionHandler(Direction::UP, 30);
    if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) player->inputDirectionHandler(Direction::DOWN, 30);
}

void GameInstance::handleVariableScreenWidth(void)
{
    if (lastScreenWidth != GetScreenWidth()) {
        lastScreenWidth = GetScreenWidth();
        if (lastScreenWidth > SCREEN_WIDTH) drawOffset.x = (lastScreenWidth - SCREEN_WIDTH) * 0.5f;
        else drawOffset.x = 0;
    }

    if (lastScreenHeight != GetScreenHeight()) {
        lastScreenHeight = GetScreenHeight();
        if (lastScreenHeight > SCREEN_HEIGHT) drawOffset.y = (lastScreenHeight - SCREEN_HEIGHT) * 0.5f;
        else drawOffset.y = 0;
    }
}

static void cleanUp(void)
{
    rlImGuiShutdown();
}