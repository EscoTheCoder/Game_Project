#pragma once

#include <iostream>
#include "GameObject.h"
#include "Box.h"
#include <sgg/graphics.h>
#include <string>

class Hearts : public GameObject, public Box {
private:
    graphics::Brush m_hearts_brush;
    graphics::Brush m_hearts_brush_debug;

    std::string m_texture;
    const float m_hearts_speed = 5.0f;

    float m_initial_pos_x;
    float m_initial_pos_y;

public:
    Hearts(float pos_x, float pos_y, float width, float height, const std::string& texture);

    Hearts(const Hearts&) = delete;
    Hearts& operator=(const Hearts&) = delete;

    Hearts(Hearts&& other) noexcept;
    Hearts& operator=(Hearts&& other) noexcept;

    void update(float dt) override;
    void init() override;
    void draw() override;
    void setTexture(const std::string& texture);
    std::string getTexture();
    void move(float dt);

    void reset();
};
