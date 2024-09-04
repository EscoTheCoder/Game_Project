#include "Hearts.h"
#include "GameState.h"
#include "util.h"
#include <sgg/graphics.h>
#include <iostream>

Hearts::Hearts(float pos_x, float pos_y, float width, float height, const std::string& texture)
    : GameObject("Heart"), m_pos_x(pos_x), m_pos_y(pos_y), m_width(width), m_height(height), m_texture(texture) {
}

Hearts::Hearts(Hearts&& other) noexcept
    : GameObject(std::move(other)),
    m_pos_x(other.m_pos_x), m_pos_y(other.m_pos_y),
    m_width(other.m_width), m_height(other.m_height),
    m_texture(std::move(other.m_texture)),
    m_brush(std::move(other.m_brush)) {
}

Hearts& Hearts::operator=(Hearts&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        m_pos_x = other.m_pos_x;
        m_pos_y = other.m_pos_y;
        m_width = other.m_width;
        m_height = other.m_height;
        m_texture = std::move(other.m_texture);
        m_brush = std::move(other.m_brush);
    }
    return *this;
}

void Hearts::init() {
    m_brush.outline_opacity = 0.0f;  // No outline
    std::string full_texture_path = GameState::getInstance()->getFullAssetPath(m_texture);
    m_brush.texture = full_texture_path;  // Set texture from asset path

    // Debug output to check if the texture path is correct
    std::cout << "Initializing Heart with texture: " << full_texture_path << std::endl;
}

void Hearts::draw() {
    // Debug output to check if draw() is being called
    std::cout << "Drawing Heart at position (" << m_pos_x << ", " << m_pos_y << ")" << std::endl;

    if (!m_brush.texture.empty()) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush);
    }
    else {
        // If texture is empty, draw a placeholder rectangle
        graphics::Brush placeholder_brush;
        SETCOLOR(placeholder_brush.fill_color, 1.0f, 0.0f, 0.0f);
        //placeholder_brush.fill_color = graphics::RED;  // Use a solid color for debugging
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, placeholder_brush);
    }
}

void Hearts::setPosition(float pos_x, float pos_y) {
    m_pos_x = pos_x;
    m_pos_y = pos_y;
}

void Hearts::setTexture(const std::string& texture) {
    m_texture = texture;
    std::string full_texture_path = GameState::getInstance()->getFullAssetPath(m_texture);
    m_brush.texture = full_texture_path;  // Update brush texture from asset path

    // Debug output to check if the texture path is updated
    std::cout << "Updated Heart texture to: " << full_texture_path << std::endl;
}

void Hearts::setSize(float width, float height) {
    m_width = width;
    m_height = height;
}
