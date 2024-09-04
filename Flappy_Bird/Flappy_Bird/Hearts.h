#pragma once

#include "GameObject.h"
#include <sgg/graphics.h>
#include <string>

class Hearts : public GameObject {
private:
    float m_pos_x;
    float m_pos_y;
    float m_width;
    float m_height;
    std::string m_texture;
    graphics::Brush m_brush;

public:
    Hearts(float pos_x, float pos_y, float width, float height, const std::string& texture);

    Hearts(const Hearts&) = delete;
    Hearts& operator=(const Hearts&) = delete;

    Hearts(Hearts&& other) noexcept;
    Hearts& operator=(Hearts&& other) noexcept;

    void init() override;
    void draw() override;
    void setPosition(float pos_x, float pos_y);
    void setTexture(const std::string& texture);
    void setSize(float width, float height);
};
