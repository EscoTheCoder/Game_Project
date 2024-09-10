#include "Level.h"
#include "GameState.h"
#include "Player.h"
#include <sgg/graphics.h>
#include <iostream>

using namespace std;

Level::Level(const string& name) :
    GameObject(name), m_lives(3) { // Initialize with 3 lives
}

Level::~Level() {
    for (auto p_gob : m_static_objects) {
        if (p_gob) {
            delete p_gob;
        }
    }
    for (auto p_gob : m_dynamic_objects) {
        if (p_gob) {
            delete p_gob;
        }
    }
}

void Level::init() {
    m_lives = 3; // Reset to 3 lives

    // Initialize background
    m_brush_background.outline_opacity = 0.0f;
    m_brush_background.texture = m_state->getFullAssetPath("background.png");
    

    // Initialize static and dynamic objects
    for (auto p_gob : m_static_objects) {
        if (p_gob) {
            p_gob->init();
        }
    }
    for (auto p_gob : m_dynamic_objects) {
        if (p_gob) {
            p_gob->init();
        }
    }


    // Initialize pipes with positions and textures
    m_pipes.emplace_back(5.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(5.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(8.0f, 5.50f, 1.0f, 2.0f, "pipe_up.png");
    m_pipes.emplace_back(8.0f, 1.0f, 1.0f, 4.0f, "pipe_down.png");

    m_pipes.emplace_back(11.0f, 5.50f, 1.0f, 4.0f, "pipe_up.png");
    m_pipes.emplace_back(11.0f, 1.0f, 1.0f, 2.0f, "pipe_down.png");

    m_pipes.emplace_back(14.0f, 5.50f, 1.0f, 2.0f, "pipe_up.png");
    m_pipes.emplace_back(14.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(17.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(17.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(20.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(20.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(23.0f, 5.50f, 1.0f, 4.0f, "pipe_up.png");
    m_pipes.emplace_back(23.0f, 1.0f, 1.0f, 2.0f, "pipe_down.png");

    m_pipes.emplace_back(26.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(26.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(29.0f, 5.50f, 1.0f, 2.0f, "pipe_up.png");
    m_pipes.emplace_back(29.0f, 1.0f, 1.0f, 4.0f, "pipe_down.png");

    m_pipes.emplace_back(32.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(32.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(35.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(35.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(38.0f, 5.50f, 1.0f, 2.0f, "pipe_up.png");
    m_pipes.emplace_back(38.0f, 1.0f, 1.0f, 4.0f, "pipe_down.png");

    m_pipes.emplace_back(41.0f, 5.50f, 1.0f, 4.0f, "pipe_up.png");
    m_pipes.emplace_back(41.0f, 1.0f, 1.0f, 2.0f, "pipe_down.png");

    m_pipes.emplace_back(44.0f, 5.50f, 1.0f, 2.0f, "pipe_up.png");
    m_pipes.emplace_back(44.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(47.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(47.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(50.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(50.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(53.0f, 5.50f, 1.0f, 4.0f, "pipe_up.png");
    m_pipes.emplace_back(53.0f, 1.0f, 1.0f, 2.0f, "pipe_down.png");

    m_pipes.emplace_back(56.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(56.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    m_pipes.emplace_back(59.0f, 5.50f, 1.0f, 2.0f, "pipe_up.png");
    m_pipes.emplace_back(59.0f, 1.0f, 1.0f, 4.0f, "pipe_down.png");

    m_pipes.emplace_back(62.0f, 5.50f, 1.0f, 3.0f, "pipe_up.png");
    m_pipes.emplace_back(62.0f, 1.0f, 1.0f, 3.0f, "pipe_down.png");

    for (auto& pipe : m_pipes) {
        pipe.init();
    }

    // Initialize coins
    m_coins.emplace_back(5.0f, 3.2f, 1.0f, 1.0f, "Bronze-Medal.png");
    m_coins.emplace_back(32.0f, 3.2f, 1.0f, 1.0f, "Silver-Medal.png");
    m_coins.emplace_back(62.0f, 3.2f, 1.0f, 1.0f, "Gold-Medal.png");

    for (auto& coin : m_coins) {
        coin.init();
    }

    // Initialize hearts representing lives
    float heart_pos_x = 1.0f; // Positioned near the left edge of the canvas
    float heart_pos_y = m_state->get_CanvasHeight() - 1.0f; // Positioned near the top edge of the canvas
    float heart_spacing = 0.35f; // Space between hearts

    m_hearts.clear();
    for (int i = 0; i < m_lives; ++i) {
        m_hearts.emplace_back(heart_pos_x + i * (0.3f + heart_spacing), heart_pos_y, 0.3f, 0.3f, "heart.png"); // Example size of 0.3x0.3
    }

    for (auto& heart : m_hearts) {
        heart.init();
    }
}

void Level::update(float dt) {
    if (m_game_paused) {
        if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
            resetLevel();
        }
        return;
    }

    // Update player
    if (m_state->get_Player()->isActive()) {
        m_state->get_Player()->update(dt);
    }

    // Update pipes
    for (auto& pipe : m_pipes) {
        pipe.update(dt);
    }

    // Update coins
    for (auto& coin : m_coins) {
        coin.update(dt);
    }

    checkCollisions();

    GameObject::update(dt);
}

void Level::draw() {
    float w = m_state->get_CanvasWidth();
    float h = m_state->get_CanvasHeight();

    float offset_x = m_state->m_global_offset_x / 2.0f + w / 2.0f;
    float offset_y = m_state->m_global_offset_y / 2.0f + h / 2.0f;

    // Draw background
    graphics::drawRect(offset_x, offset_y, w, h, m_brush_background);

    // Draw player
    if (m_state->get_Player()->isActive()) {
        m_state->get_Player()->draw();
    }

    // Draw pipes
    for (auto& pipe : m_pipes) {
        pipe.draw();
    }

    // Draw coins
    for (auto& coin : m_coins) {
        coin.draw();
    }

    // Draw hearts (lives) on the right side of the canvas
    for (auto& heart : m_hearts) {
        heart.draw();
    }
}


void Level::loseLife() {
    if (m_lives > 0) {
        m_lives--;

        // Remove a heart visually by popping the last heart from the list
        m_hearts.pop_back();

        if (m_lives == 0) {
            graphics::stopMessageLoop(); // Stop the game if no lives left
        }
    }
}


void Level::resetLevel() {
    // Reset player and other objects (existing code)

    Player* player = m_state->get_Player();
    player->reset();

    // Reset pipes
    for (auto& pipe : m_pipes) {
        pipe.reset();
    }

    // Reset coins
    m_coins.clear();
    m_coins.emplace_back(5.0f, 3.2f, 1.0f, 1.0f, "Bronze-Medal.png");
    m_coins.emplace_back(32.0f, 3.2f, 1.0f, 1.0f, "Silver-Medal.png");
    m_coins.emplace_back(62.0f, 3.2f, 1.0f, 1.0f, "Gold-Medal.png");

    for (auto& coin : m_coins) {
        coin.init();
    }

    // Reset hearts
    m_hearts.clear();
    float heart_pos_x = 1.0f; // Positioned near the left edge of the canvas
    float heart_pos_y = m_state->get_CanvasHeight() - 1.0f; // Positioned near the top edge of the canvas
    float heart_spacing = 0.35f; // Space between hearts

    for (int i = 0; i < m_lives; ++i) {
        m_hearts.emplace_back(heart_pos_x + i * (0.3f + heart_spacing), heart_pos_y, 0.3f, 0.3f, "heart.png");
    }

    for (auto& heart : m_hearts) {
        heart.init();
    }

    m_game_paused = false;
}


void Level::checkCollisions() {
    if (m_game_paused) return;

    Player* player = m_state->get_Player();
    if (!player) {
        std::cerr << "Player not initialized!" << std::endl;
        return;
    }


    for (auto& pipe : m_pipes) {
        if (player->intersect(pipe)) {
            graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
            loseLife();
            m_game_paused = true;
            return;
        }
    }

    auto it = m_coins.begin();
    while (it != m_coins.end()) {
        if (player->intersect(*it)) {
            graphics::playSound(m_state->getFullAssetPath("point.wav"), 0.5f);

            if (it->getTexture() == "Gold-Medal.png") {
                it = m_coins.erase(it);
                m_game_paused = true;
                graphics::stopMessageLoop();
                return;
            }

            it = m_coins.erase(it);
        }
        else {
            ++it;
        }
    }

    float floorY = m_state->get_CanvasHeight() - 0.1f;
    if (player->m_pos_y > floorY) {
        graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
        loseLife();
        m_game_paused = true;
    }
}
