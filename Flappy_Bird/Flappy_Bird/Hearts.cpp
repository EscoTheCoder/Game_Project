#include "Hearts.h"
#include "GameState.h"
#include "box.h"
#include "util.h"
#include <iostream>
#include <sgg/graphics.h>

Hearts::Hearts(float pos_x, float pos_y, float width, float height, const std::string& texture) :
    GameObject("Heart"), Box(pos_x, pos_y, width, height), m_texture(texture) {
}


Hearts::Hearts(Hearts&& other) noexcept:
    GameObject(std::move(other)), Box(std::move(other)),
    m_hearts_brush(std::move(other.m_hearts_brush)),
    m_hearts_brush_debug(std::move(other.m_hearts_brush_debug)),
    m_texture(std::move(other.m_texture)) {
    // Reset other's state if necessary
}

Hearts& Hearts::operator=(Hearts&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        Box::operator=(std::move(other));
        m_hearts_brush = std::move(other.m_hearts_brush);
        m_hearts_brush_debug = std::move(other.m_hearts_brush_debug);
        m_texture = std::move(other.m_texture);
        // Reset other's state if necessary
    }
    return *this;
}

void Hearts::init() {
    m_hearts_brush.outline_opacity = 0.0f;
    m_hearts_brush.texture = m_state->getFullAssetPath(m_texture);

    m_hearts_brush_debug.fill_opacity = 0.1f;
    SETCOLOR(m_hearts_brush_debug.fill_color, 1.0f, 0.0f, 0.0f);
    SETCOLOR(m_hearts_brush_debug.outline_color, 1.0f, 0.0f, 0.0f);

    // Αποθηκεύουμε την αρχική θέση κατά την αρχικοποίηση
    m_initial_pos_x = m_pos_x;
    m_initial_pos_y = m_pos_y;
}

void Hearts::update(float dt) {
    move(dt);
}

void Hearts::draw() {
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_hearts_brush);

    if (m_state->m_debugging) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_hearts_brush_debug);
    }
}

void Hearts::reset() {
    // Επαναφορά της θέσης του σωλήνα στην αρχική κατάσταση
    m_pos_x = m_initial_pos_x;
    m_pos_y = m_initial_pos_y;
}

void Hearts::move(float dt) {
    m_pos_x -= m_hearts_speed * (dt / 1000.0f);
}

void Hearts::setTexture(const std::string& texture) {
    m_texture = texture;
    m_hearts_brush.texture = m_state->getFullAssetPath(m_texture);
}

std::string Hearts::getTexture() {
    return m_texture;
}
