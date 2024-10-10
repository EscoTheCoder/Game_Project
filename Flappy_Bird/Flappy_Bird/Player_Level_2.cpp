#include "Player_Level_2.h"
#include "GameState.h"
#include "util.h"
#include <sgg/graphics.h>
#include <iostream>

Player_Level_2::Player_Level_2(const std::string& name) :
    GameObject(name)
{
    m_width = 0.4f;
    m_height = 0.4f;
}

void Player_Level_2::init() {
    // Set the initial position for the player only when the game starts
    m_pos_x = m_state->getCanvasDimensions().first / 4.0f;  // Starting position (left side)
    m_pos_y = m_state->getCanvasDimensions().second / 2.0f;

    // Store the initial position only during the first init, not during resets
    m_initial_pos_x = m_pos_x;
    m_initial_pos_y = m_pos_y;

    m_velocity_y = 0.0f; // Reset velocity0

    m_brush_player.fill_opacity = 1.0f;
    m_brush_player.outline_opacity = 0.0f;
    m_brush_player.texture = m_state->getFullAssetPath("lap_phuong_3.png");

    m_brush_player_debug.fill_opacity = 0.1f;
    SETCOLOR(m_brush_player_debug.fill_color, 1.0f, 0.0f, 0.0f);
    SETCOLOR(m_brush_player_debug.outline_color, 1.0f, 0.0f, 0.0f);
}


void Player_Level_2::reset() {
    // Reset player to the initial starting position and reset velocity
    m_pos_x = m_initial_pos_x;
    m_pos_y = m_initial_pos_y;
    m_velocity_y = 0.0f; // Reset velocity to zero when the game resets
    m_isJumping = false; // Ensure jumping flag is reset
}





void Player_Level_2::movePlayer_2(float dt) {
    float delta_time = dt / 1000.0f; // Convert milliseconds to seconds

    // Jumping logic
    graphics::MouseState mouse;
    graphics::getMouseState(mouse);

    if (m_velocity_y == 0) {
        m_velocity_y -= (graphics::getKeyState(graphics::SCANCODE_SPACE) || mouse.button_left_pressed) ? m_jump_force : 0;
    }

    // Apply gravity
    m_velocity_y += m_gravity * delta_time;

    // Update vertical position based on velocity
    m_pos_y += m_velocity_y * delta_time;

}



void Player_Level_2::update(float dt) {
    movePlayer_2(dt);
}

void Player_Level_2::draw() {
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush_player);
    debugDraw();
}

void Player_Level_2::debugDraw() {
    if (m_state->m_debugging) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush_player_debug);

        char s[20];
        sprintf_s(s, "(%5.2f, %5.2f)", m_pos_x, m_pos_y);
        graphics::drawText(m_pos_x - 0.4f, m_pos_y - 0.6f, 0.15f, s, m_brush_player_debug);
    }
}

float Player_Level_2::getPosX() const { return m_pos_x; }
float Player_Level_2::getPosY() const { return m_pos_y; }
float Player_Level_2::getWidth() const { return m_width; }
float Player_Level_2::getHeight() const { return m_height; }
float Player_Level_2::getVelocityY() const { return m_velocity_y; }