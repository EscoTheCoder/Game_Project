#pragma once

#include <iostream>
#include "GameObject.h"
#include "Box.h"
#include <sgg/graphics.h>
#include <string>

class Coin : public GameObject, public Box {
private:
    graphics::Brush m_coin_brush;
    graphics::Brush m_coin_brush_debug;
    std::string m_texture;
    const float m_coin_speed = 5.0f;

public:
    // Constructor
    Coin(float pos_x, float pos_y, float width, float height, const std::string& texture);

    // Delete copy constructor and copy assignment operator
    Coin(const Coin&) = delete;
    Coin& operator=(const Coin&) = delete;

    // Implement move constructor and move assignment operator
    Coin(Coin&& other) noexcept;
    Coin& operator=(Coin&& other) noexcept;

    void update(float dt) override;
    void init() override;
    void draw() override;
    void setTexture(const std::string& texture);
    std::string getTexture();
    void move(float dt);
};
