#pragma once

#include "sgg/graphics.h"
#include "Start_Level.h"
#include "Level.h"
#include "Level_2.h"
#include <string>
#include <utility> // For std::pair

class GameState {
private:
    std::string m_asset_path = "assets\\";

    float m_canvas_width = 6.0f;
    float m_canvas_height = 6.0f;

    // Raw pointers for Player and Start_Level management
    class Player* m_player = nullptr;
    Start_Level* level_1 = nullptr;
    Start_Level* level_2 = nullptr;

    Start_Level* current_level = nullptr; // Pointer to current level (base class)
    bool in_level_2 = false; // To keep track of whether you're in Level 2 or not

    // Private constructor for Singleton
    GameState();

public:
    float m_global_offset_x = 0.0f;
    float m_global_offset_y = 0.0f;
    bool m_debugging = false;

    // Singleton getInstance method
    static GameState* getInstance();

    // Basic functionality
    void init();
    void draw();
    void update(float dt);

    // Canvas dimensions
    std::pair<float, float> getCanvasDimensions() const;

    // Asset path management
    std::string getAssetDir() const;
    std::string getFullAssetPath(const std::string& asset) const;

    void handleGameOver();

    // Player getter and setter
    class Player* get_Player() const;
    void set_Player(class Player* player);

    ~GameState();
};
