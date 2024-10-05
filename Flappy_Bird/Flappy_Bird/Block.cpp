#include "Block.h"
#include "GameState.h"
#include "util.h"
#include <sgg/graphics.h>

Block::Block(float pos_x, float pos_y, float width, float height, const std::string& texture) :
    GameObject("Block"), Box(pos_x, pos_y, width, height), m_texture(texture)
{
}

void Block::init() {
    m_pipe_brush.outline_opacity = 0.0f; // No outline for the pipe
    m_pipe_brush.texture = m_state->getFullAssetPath(m_texture); // Set the texture

    m_pipe_brush_debug.fill_opacity = 0.1f; // Lightly transparent debug fill
    SETCOLOR(m_pipe_brush_debug.fill_color, 1.0f, 0.0f, 0.0f); // Red color for the debug outline
    SETCOLOR(m_pipe_brush_debug.outline_color, 0.0f, 1.0f, 0.0f); // Green outline color for debugging

    // Αποθηκεύουμε την αρχική θέση κατά την αρχικοποίηση
    m_initial_pos_x = m_pos_x;
    m_initial_pos_y = m_pos_y;
}

void Block::update(float dt) {
    move(dt); // Move the pipe according to the game logic
}

void Block::draw() {
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_pipe_brush);

    if (m_state->m_debugging) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_pipe_brush_debug);
    }
}

void Block::reset() {
    // Επαναφορά της θέσης του σωλήνα στην αρχική κατάσταση
    m_pos_x = m_initial_pos_x;
    m_pos_y = m_initial_pos_y;
}

void Block::move(float dt) {
    // Move the pipe to the left as time passes
    m_pos_x -= m_pipe_speed * (dt / 1000.0f); // Adjust the pipe's speed directly
}

void Block::setTexture(const std::string& texture) {
    m_texture = texture;
    m_pipe_brush.texture = m_state->getFullAssetPath(m_texture); // Update the brush texture
}
