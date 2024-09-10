#pragma once

#include "sgg/graphics.h"
#include <string>
#include <memory> // For smart pointers
#include <utility> // For std::pair

class GameState {
private:
    std::string m_asset_path = "assets\\";

    float m_canvas_width = 6.0f;
    float m_canvas_height = 6.0f;

    // Using smart pointers to manage Player and Level memory
    std::unique_ptr<class Player> m_player = nullptr;
    std::unique_ptr<class Level> m_current_level = nullptr;

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

    // Player getter and setter
    class Player* get_Player() const;
    void set_Player(class Player* player);

    // Destructor is now default, as unique_ptr will handle memory cleanup
    ~GameState() = default;
};
