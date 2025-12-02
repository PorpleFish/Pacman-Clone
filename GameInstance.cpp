#include "GameInstance.h"
#include <iostream>
#include <charconv>

GameInstance::GameInstance()
{
    lastScreenWidth = SCREEN_WIDTH;
    lastScreenHeight = SCREEN_HEIGHT;

    drawOffset = {0.0f, 0.0f};

    shouldStayOpen = true;
}

bool GameInstance::setup(bool _debug_map, bool _debug_ai)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
   
    SetTargetFPS(60);

    debug_ai = _debug_ai;
    debug_map = _debug_map;

    currentMap = Map(0);
    characters.push_back(new Player(currentMap.getNode(34), currentMap.getNode(35)));

    if (debug_ai || debug_map) 
    {
        rlImGuiSetup(false);
    }

    return true;
}

void GameInstance::run()
{
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        draw();
        pollInput();
        update(GetFrameTime());
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

    currentMap.draw(drawOffset, debug_map);

    for (Char* character : characters) character->draw(drawOffset);
    
    if (!debug_ai && !debug_map) {
        EndDrawing();
        return;
    }

    Node* hoveredNode = currentMap.getNodeFromScreenspace(GetMousePosition(), drawOffset);
    rlImGuiBegin();
    ImGui::EndFrame();
    ImGui::NewFrame();
    if (debug_map && hoveredNode != nullptr)
    {
        ImGui::SetNextWindowPos({GetMouseX() + 8.0f, GetMouseY() + 8.0f});
        ImGui::SetNextWindowSize({ 200.0f, 180.0f });
        ImGui::SetNextWindowBgAlpha(0.5f);

        if (ImGui::Begin(
            "Debug Map",
            nullptr,
            ImGuiWindowFlags_NoDecoration
        )) {
            hoveredNode->draw(true, drawOffset);
            
            static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

            ImGui::SeparatorText("Current Node");
            
            if (ImGui::BeginTable("Neighbour Positions", 3, flags))
            {
                ImGui::TableSetupColumn("Index");
                ImGui::TableSetupColumn("X");
                ImGui::TableSetupColumn("Y");
                ImGui::TableHeadersRow();

                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                ImGui::Text(std::to_string(currentMap.getNodeIndex(hoveredNode)).c_str());

                ImGui::TableSetColumnIndex(1);
                ImGui::Text(std::to_string(hoveredNode->coord.x).c_str());

                ImGui::TableSetColumnIndex(2);
                ImGui::Text(std::to_string(hoveredNode->coord.y).c_str());

                ImGui::EndTable();
            }

            ImGui::SeparatorText("Neighbours");

            if (ImGui::BeginTable("Neighbour Positions", 3, flags))
            {
                ImGui::TableSetupColumn("Index");
                ImGui::TableSetupColumn("X");
                ImGui::TableSetupColumn("Y");
                ImGui::TableHeadersRow();

                for (Node* neighbour : hoveredNode->neighbours)
                {
                    ImGui::TableNextRow();
                    ImGui::TableSetColumnIndex(0);
                    ImGui::Text(std::to_string(currentMap.getNodeIndex(neighbour)).c_str());

                    ImGui::TableSetColumnIndex(1);
                    ImGui::Text(std::to_string(neighbour->coord.x).c_str());

                    ImGui::TableSetColumnIndex(2);
                    ImGui::Text(std::to_string(neighbour->coord.y).c_str());
                }
                ImGui::EndTable();
            }
        }
        ImGui::End();
    }
    ImGui::Render();
    
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