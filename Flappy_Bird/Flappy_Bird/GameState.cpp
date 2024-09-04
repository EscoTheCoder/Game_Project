#include "GameState.h"
#include "Level.h"
#include "Player.h"
#include <thread>
#include <chrono>
using namespace std;

void GameState::init() {
    m_current_level = new Level("Level0");
    m_current_level->init();

    m_player = new Player("Bird");
    m_player->init();
}

void GameState::draw() {
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

GameState::GameState() {
}

float GameState::get_CanvasWidth() {
    return m_canvas_width;
}

float GameState::get_CanvasHeight() {
    return m_canvas_height;
}

GameState* GameState::getInstance() {
    if (m_unique_instance == nullptr) {
        m_unique_instance = new GameState();
    }
    return m_unique_instance;
}

GameState::~GameState() {
    if (m_player) {
        delete m_player;
    }
    if (m_current_level) {
        delete m_current_level;
    }
}

string GameState::getAssetDir() {
    return m_asset_path;
}

string GameState::getFullAssetPath(const string& asset) {
    return m_asset_path + asset;
}

GameState* GameState::m_unique_instance = nullptr;
