#include "Extras.h"
#include "GameState.h"
#include "util.h"
#include <iostream>
#include <sgg/graphics.h>

Extras::Extras(float pos_x, float pos_y, float width, float height, const std::string& texture) :
    GameObject("Extras"), Box(pos_x, pos_y, width, height), m_texture(texture) {
}

Extras::Extras(Extras&& other) noexcept :
    GameObject(std::move(other)), Box(std::move(other)),
    m_extras_brush(std::move(other.m_extras_brush)),
    m_extras_brush_debug(std::move(other.m_extras_brush_debug)),
    m_texture(std::move(other.m_texture)) {
    // Reset other's state if necessary
}

Extras& Extras::operator=(Extras&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        Box::operator=(std::move(other));
        m_extras_brush = std::move(other.m_extras_brush);
        m_extras_brush_debug = std::move(other.m_extras_brush_debug);
        m_texture = std::move(other.m_texture);
        // Reset other's state if necessary
    }
    return *this;
}

void Extras::init() {
    m_extras_brush.outline_opacity = 0.0f;
    m_extras_brush.texture = m_state->getFullAssetPath(m_texture);

    m_extras_brush_debug.fill_opacity = 0.1f;
    SETCOLOR(m_extras_brush_debug.fill_color, 1.0f, 0.0f, 0.0f);
    SETCOLOR(m_extras_brush_debug.outline_color, 1.0f, 0.0f, 0.0f);
}

void Extras::update(float dt) {
    move(dt);
}

void Extras::draw() {
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_extras_brush);

    if (m_state->m_debugging) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_extras_brush_debug);
    }
}

void Extras::move(float dt) {
    m_pos_x -= m_extras_speed * (dt / 1000.0f);
}

void Extras::setTexture(const std::string& texture) {
    m_texture = texture;
    m_extras_brush.texture = m_state->getFullAssetPath(m_texture);
}

std::string Extras::getTexture() {
    return m_texture;
}
