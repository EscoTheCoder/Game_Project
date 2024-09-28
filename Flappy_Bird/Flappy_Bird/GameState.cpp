#include "GameState.h"
#include "Level.h"
#include "Player.h"
#include <thread>
#include <chrono>
#include <algorithm> // For std::max, std::min

using namespace std;

GameState::GameState() {
    // Constructor remains empty for now
}

GameState* GameState::getInstance() {
    // Thread-safe Singleton pattern in C++11
    static GameState instance;
    return &instance;
}

void GameState::init() {
    // Initialize the level and player using smart pointers
    m_current_level = std::make_unique<Level>("Level0");
    m_current_level->init();

    m_player = std::make_unique<Player>("Bird");
    m_player->init();

    graphics::preloadBitmaps(getAssetDir());
}

void GameState::draw() {
    // Draw the level
    if (m_current_level) {
        m_current_level->draw();
    }
}

void GameState::update(float dt) {
    if (dt > 500) { // Ignore long delays
        return;
    }

    float sleep_time = max(0.0f, 17.0f - dt);
    this_thread::sleep_for(chrono::duration<float, milli>(sleep_time));

    if (m_current_level) {
        m_current_level->update(dt);
    }

    m_debugging = graphics::getKeyState(graphics::SCANCODE_0);
}

std::pair<float, float> GameState::getCanvasDimensions() const {
    return { m_canvas_width, m_canvas_height };
}

std::string GameState::getAssetDir() const {
    return m_asset_path;
}

std::string GameState::getFullAssetPath(const std::string& asset) const {
    return m_asset_path + asset;
}

class Player* GameState::get_Player() const {
    return m_player.get();
}

void GameState::set_Player(class Player* player) {
    // Use unique_ptr's reset to change the player
    m_player.reset(player);
}
