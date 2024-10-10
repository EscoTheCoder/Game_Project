#include "Level_2.h"
#include "GameState.h"
#include "Coin_Score.h"
#include "Player.h"
#include <sgg/graphics.h>
#include <iostream>

using namespace std;

Level_2::Level_2(const string& name) :
    GameObject(name), m_lives(3), Start_Level("level2") { // Initialize with 3 lives
}

Level_2::~Level_2() {
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

void Level_2::init() {
    m_lives = 3; // Reset to 3 lives
    m_coins_for_score = 3;
    m_game_over = false; // Reset game-over flag
    m_game_over_timer = 0.0f; // Reset game-over timer

    // Initialize background
    m_brush_background.outline_opacity = 0.0f;
    m_brush_background.texture = m_state->getFullAssetPath("background.png");

    // Initialize ending background
    m_brush_ending_background.outline_opacity = 0.0f;
    m_brush_ending_background.texture = m_state->getFullAssetPath("exit_btn.png");



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



    for (int i = 0; i < 150; i++) {
        //m_extras.emplace_back((float)i, 5.50f, 1.0f, 1.0f, "Ground.png");
        m_blocks.emplace_back((float)i, 5.50f, 1.1f, 1.1f, "obstacleSquare.png");
    }

    m_extras.emplace_back(4.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_extras.emplace_back(7.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_extras.emplace_back(7.5f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_extras.emplace_back(14.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(15.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(16.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_extras.emplace_back(17.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(18.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(19.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_extras.emplace_back(20.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(21.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(21.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(27.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(28.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(29.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(30.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(31.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(32.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_extras.emplace_back(33.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(34.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(35.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(36.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(37.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(37.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(38.0f, 4.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(39.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(39.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(40.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(40.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(41.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(41.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(42.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(42.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_extras.emplace_back(42.0f, 2.8f, 0.5f, 0.5f, "obstacleTriangle.png");
    m_blocks.emplace_back(43.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(43.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(44.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(44.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(45.0f, 4.50f, 1.0f, 1.1f, "obstacleSquare.png");
    m_blocks.emplace_back(45.0f, 3.50f, 1.0f, 1.1f, "obstacleSquare.png");



    for (auto& pipe : m_blocks) {
        pipe.init();
    }


    // Initialize coins
    m_coins.emplace_back(21.0f, 2.5f, 0.5f, 0.5f, "coin.png");
    m_coins.emplace_back(32.0f, 3.2f, 0.5f, 0.5f, "coin.png");
    m_coins.emplace_back(32.0f, 3.2f, 0.5f, 0.5f, "coin.png");
    m_coins.emplace_back(62.0f, 3.2f, 0.5f, 0.5f, "coin.png");

    for (auto& coin : m_coins) {
        coin.init();
    }

    //m_extras.emplace_back(75.0f, 3.2f, 2.0f, 5.0f, "do_not_stop_image.png");
    m_extras.emplace_back(75.0f, 2.5f, 2.0f, 2.0f, "portal.png");

    for (auto& extras : m_extras) {
        extras.init();
    }

    // Position the hearts at the top-left corner
    float heart_pos_x = 0.3f;  // Positioned near the left edge of the canvas
    float heart_pos_y = 0.3f;  // Positioned near the top edge of the canvas
    float heart_spacing = 0.05f; // Space between hearts

    m_hearts.clear();
    for (int i = 0; i < m_lives; ++i) {
        m_hearts.emplace_back(heart_pos_x + i * (0.3f + heart_spacing), heart_pos_y, 0.3f, 0.3f, "heart_2.png"); // Example size of 0.3x0.3
    }

    for (auto& heart : m_hearts) {
        heart.init();
    }

    // Position the coins at the top-left corner
    float coin_score_pos_x = 0.3f;  // Positioned near the left edge of the canvas
    float coin_score_pos_y = 0.7f;  // Positioned near the top edge of the canvas
    float coin_score_spacing = 0.05f; // Space between hearts

    m_coin_score.clear();
    for (int i = 0; i < m_lives; ++i) {
        m_coin_score.emplace_back(coin_score_pos_x + i * (0.3f + coin_score_spacing), coin_score_pos_y, 0.3f, 0.3f, "coin.png"); // Example size of 0.3x0.3
    }

    for (auto& coin_score : m_coin_score) {
        coin_score.init();
    }
}



void Level_2::update(float dt) {

    if (status == STATUS_START) {
        updateStartScreen();
    }
    else {
        updateLevelScreen(dt);
    }
}

void Level_2::updateStartScreen() {

    //graphics::playSound(m_state->getFullAssetPath("music.wav"), 0.009f);

    graphics::MouseState mouse;
    graphics::getMouseState(mouse);

    if (graphics::getKeyState(graphics::SCANCODE_SPACE) || mouse.button_left_pressed) {

        status = STATUS_PLAYING;
    }
}


void Level_2::updateLevelScreen(float dt) {

    if (m_game_paused) {
        graphics::MouseState mouse;
        graphics::getMouseState(mouse);

        if (graphics::getKeyState(graphics::SCANCODE_SPACE) || mouse.button_left_pressed) {
            resetLevel();
        }
        return;
    }

    // If the game is over, start the timer to delay the ending
    if (m_game_over) {
        m_game_over_timer += dt;
        if (m_game_over_timer > 2000.0f) { // Wait for 2 seconds (2000ms)
            graphics::stopMessageLoop();
        }
        return;
    }


    // Update player
    if (m_state->get_Player()->isActive()) {
        m_state->get_Player()->update(dt);
    }

    // Update pipes
    for (auto& pipe : m_blocks) {
        pipe.update(dt);
    }

    // Update coins
    for (auto& coin : m_coins) {
        coin.update(dt);
    }

    for (auto& extras : m_extras) {
        extras.update(dt);
    }


    //// Update coins_score
    //for (auto& coins_score : m_coin_score) {
    //    coins_score.update(dt);
    //}

    checkCollisions();

    GameObject::update(dt);
}



void Level_2::draw() {

    if (status == STATUS_START) {
        drawStartScreen();
    }
    else {
        drawLevelScreen();
    }

}


void Level_2::drawStartScreen() {
    graphics::Brush br;

    float w = m_state->getCanvasDimensions().first / 4;
    float h = m_state->getCanvasDimensions().second / 4;

    float offset_x = m_state->m_global_offset_x / 2.0f + w / 2.0f;
    float offset_y = m_state->m_global_offset_y / 2.0f + h / 2.0f;

    br.outline_opacity = 0.0f;
    br.texture = m_state->getFullAssetPath("start_btn.png");
    // Draw background
    graphics::drawRect(offset_x, offset_y, w, h, br);

}

void Level_2::drawLevelScreen() {
    float w = m_state->getCanvasDimensions().first;
    float h = m_state->getCanvasDimensions().second;

    float offset_x = m_state->m_global_offset_x / 2.0f + w / 2.0f;
    float offset_y = m_state->m_global_offset_y / 2.0f + h / 2.0f;

    // Draw the ending background with smaller dimensions
    float ending_bg_width = w * 0.8f; // 70% of the canvas width
    float ending_bg_height = h * 0.3f; // 70% of the canvas height

    // Draw background
    graphics::drawRect(offset_x, offset_y, w, h, m_brush_background);

    if (!m_game_over) {
        // Draw player
        if (m_state->get_Player()->isActive()) {
            m_state->get_Player()->draw();
        }

        // Draw pipes
        for (auto& pipe : m_blocks) {
            pipe.draw();
        }

        // Draw coins
        for (auto& coin : m_coins) {
            coin.draw();
        }

        // Draw extras
        for (auto& extras : m_extras) {
            extras.draw();
        }

        // Draw hearts (lives) on the left side of the canvas
        for (auto& heart : m_hearts) {
            heart.draw();
        }

        // Draw coin (score) on the left side of the canvas
        for (auto& coin_score : m_coin_score) {
            coin_score.draw();
        }
    }
    else {
        // If the game is over, draw the ending background
        //m_brush_background.outline_opacity = 0.0f;
        graphics::drawRect(offset_x, offset_y, ending_bg_width, ending_bg_height, m_brush_ending_background);
    }
}


void Level_2::loseLife() {
    if (m_lives > 0) {
        m_lives--;

        // Remove a heart visually by popping the last heart from the list
        m_hearts.pop_back();

        if (m_lives == 0) {
            m_game_over = true;
        }
    }
}

void Level_2::loseCoin() {
    if (m_coins_for_score > 0) {
        m_coins_for_score--;

        // Remove a coin visually by popping the last coin from the list
        m_coin_score.pop_back();

        /*if (m_coins_for_score == 0) {
            m_game_over = true;
        }*/
    }
}



void Level_2::resetLevel() {
    // Reset player and other objects (existing code)

    Player* player = m_state->get_Player();
    player->reset();

    // Reset pipes
    for (auto& pipe : m_blocks) {
        pipe.reset();
    }

    // Reset coins
    m_coins.clear();
    m_coins.emplace_back(21.0f, 2.5f, 0.5f, 0.5f, "coin.png");
    m_coins.emplace_back(32.0f, 3.2f, 0.5f, 0.5f, "coin.png");
    m_coins.emplace_back(32.0f, 3.2f, 0.5f, 0.5f, "coin.png");
    m_coins.emplace_back(62.0f, 3.2f, 0.5f, 0.5f, "coin.png");

    for (auto& coin : m_coins) {
        coin.init();
    }


    for (auto& extras : m_extras) {
        extras.reset();
    }

    // Reset hearts' position at the top-left corner
    m_hearts.clear(); // Clears but doesn’t free memory

    float heart_pos_x = 0.3f;  // Positioned near the left edge of the canvas
    float heart_pos_y = 0.3f;  // Positioned near the top edge of the canvas
    float heart_spacing = 0.05f; // Space between hearts

    for (int i = 0; i < m_lives; ++i) {
        m_hearts.emplace_back(heart_pos_x + i * (0.3f + heart_spacing), heart_pos_y, 0.3f, 0.3f, "heart_2.png"); // Example size of 0.3x0.3
    }

    for (auto& heart : m_hearts) {
        heart.init();
    }

    // Reset coin_score's position at the top-left corner
    m_coin_score.clear(); // Clears but doesn’t free memory

    // Position the coins at the top-left corner
    float coin_score_pos_x = 0.3f;  // Positioned near the left edge of the canvas
    float coin_score_pos_y = 0.7f;  // Positioned near the top edge of the canvas
    float coin_score_spacing = 0.05f; // Space between hearts

    for (int i = 0; i < 3; ++i) { // <3 gia na einai panta 3 ta coins_for_score meta to reset
        m_coin_score.emplace_back(coin_score_pos_x + i * (0.3f + coin_score_spacing), coin_score_pos_y, 0.3f, 0.3f, "coin.png"); // Example size of 0.3x0.3
    }

    for (auto& coin_score : m_coin_score) {
        coin_score.init();
    }

    m_game_paused = false;
}


void Level_2::checkCollisions() {
    if (m_game_paused || m_game_over) return;

    Player* player = m_state->get_Player();
    if (!player) {
        std::cerr << "Player not initialized!" << std::endl;
        return;
    }

    bool isGrounded = false;  // To track if the player is on a block

    // Check pipe collisions
    for (auto& pipe : m_blocks) {

        float offset = 0.0f;

        // First, check for vertical collision (standing on top of a pipe)
        if ((offset = player->intersectDown(pipe)) != 0.0f) {
            player->m_pos_y += offset;
            player->set_velocity_y(0.0f);
            isGrounded = true;  // Player is standing on a pipe
        }

        // Check for horizontal collision only if not grounded
        if ((!isGrounded || isGrounded) && (offset = player->intersectSideways(pipe)) != 0.0f) {
            player->m_pos_x -= offset;
            loseLife();
            m_game_paused = true;
            return;
        }
    }

    // Check coin collection outside the pipe loop for clarity
    auto it = m_coins.begin();
    while (it != m_coins.end()) {
        if (player->intersect(*it)) {  // Player collects a coin
            graphics::playSound(m_state->getFullAssetPath("point.wav"), 0.5f);
            loseCoin();  // Decrease the coin count
            it = m_coins.erase(it);  // Remove the collected coin
        }
        else {
            ++it;  // Move to the next coin
        }
    }

    // Check extra item collisions
    for (auto& extra : m_extras) {
        if (player->intersect(extra)) {  // Player collides with an extra item
            graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
            loseLife();
            m_game_paused = true;
            return;
        }
    }
    // Check extras collisions
    auto itt = m_extras.begin();
    while (itt != m_extras.end()) {
        if (player->intersect(*itt)) {
            if (itt->getTexture() == "portal.png") {
                graphics::playSound(m_state->getFullAssetPath("game_over.wav"), 0.5f);
                loseLife();
                m_game_over = true; // End the game when the portal is hit
                return;
            }
            else {
                graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
                loseLife();
                m_game_paused = true;
            }
        }
        else {
            ++itt;
        }
    }

    // Check if the player hits the ground
    float floorY = m_state->getCanvasDimensions().second - 0.1f;
    if (player->m_pos_y > floorY) {
        player->m_pos_y = floorY;  // Adjust the player's position to be on the ground
        player->set_velocity_y(0.0f);  // Reset the vertical velocity
        graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
        loseLife();
        m_game_paused = true;
    }
}

