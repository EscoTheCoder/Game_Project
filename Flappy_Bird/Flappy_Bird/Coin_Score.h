#pragma once

#include <iostream>
#include "GameObject.h"
#include "Box.h"
#include <sgg/graphics.h>
#include <string>

class Coin_Score : public GameObject, public Box {
private:
    graphics::Brush m_coin_score_brush;
    graphics::Brush m_coin_score_brush_debug;

    std::string m_texture;
    const float m_coin_score_speed = 5.0f;

    float m_initial_pos_x;
    float m_initial_pos_y;
    

public:

    

    Coin_Score(float pos_x, float pos_y, float width, float height, const std::string& texture);

    Coin_Score(const Coin_Score&) = delete;
    Coin_Score& operator=(const Coin_Score&) = delete;

    Coin_Score(Coin_Score&& other) noexcept;
    Coin_Score& operator=(Coin_Score&& other) noexcept;

    void update(float dt) override;
    void init() override;
    void draw() override;
    void setTexture(const std::string& texture);
    std::string getTexture();
    void move(float dt);

    void reset();
};
