#include "Coin.h"
#include "GameState.h"
#include "util.h"
#include <iostream>
#include <sgg/graphics.h>

Coin::Coin(float pos_x, float pos_y, float width, float height, const std::string& texture) :
    GameObject("Coin"), Box(pos_x, pos_y, width, height), m_texture(texture) {
}

Coin::Coin(Coin&& other) noexcept :
    GameObject(std::move(other)), Box(std::move(other)),
    m_coin_brush(std::move(other.m_coin_brush)),
    m_coin_brush_debug(std::move(other.m_coin_brush_debug)),
    m_texture(std::move(other.m_texture)) {
    // Reset other's state if necessary
}

Coin& Coin::operator=(Coin&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        Box::operator=(std::move(other));
        m_coin_brush = std::move(other.m_coin_brush);
        m_coin_brush_debug = std::move(other.m_coin_brush_debug);
        m_texture = std::move(other.m_texture);
        // Reset other's state if necessary
    }
    return *this;
}

void Coin::init() {
    m_coin_brush.outline_opacity = 0.0f;
    m_coin_brush.texture = m_state->getFullAssetPath(m_texture);

    m_coin_brush_debug.fill_opacity = 0.1f;
    SETCOLOR(m_coin_brush_debug.fill_color, 1.0f, 0.0f, 0.0f);
    SETCOLOR(m_coin_brush_debug.outline_color, 1.0f, 0.0f, 0.0f);
}

void Coin::update(float dt) {
    move(dt);
}

void Coin::draw() {
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_coin_brush);

    if (m_state->m_debugging) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_coin_brush_debug);
    }
}

void Coin::move(float dt) {
    m_pos_x -= m_coin_speed * (dt / 1000.0f);
}

void Coin::setTexture(const std::string& texture) {
    m_texture = texture;
    m_coin_brush.texture = m_state->getFullAssetPath(m_texture);
}

std::string Coin::getTexture() {
    return m_texture;
}
