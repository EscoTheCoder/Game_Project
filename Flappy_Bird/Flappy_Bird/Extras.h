#pragma once

#include <iostream>
#include "GameObject.h"
#include "Box.h"
#include <sgg/graphics.h>
#include <string>

class Extras : public GameObject, public Box {
private:
    graphics::Brush m_extras_brush;
    graphics::Brush m_extras_brush_debug;
    std::string m_texture;
    const float m_extras_speed = 5.0f;

public:
    // Constructor
    Extras(float pos_x, float pos_y, float width, float height, const std::string& texture);

    // Delete copy constructor and copy assignment operator
    Extras(const Extras&) = delete;
    Extras& operator=(const Extras&) = delete;

    // Implement move constructor and move assignment operator
    Extras(Extras&& other) noexcept;
    Extras& operator=(Extras&& other) noexcept;

    void update(float dt) override;
    void init() override;
    void draw() override;
    void setTexture(const std::string& texture);
    std::string getTexture();
    void move(float dt);
};
