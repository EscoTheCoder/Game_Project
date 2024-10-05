#pragma once

#include <iostream>
#include "GameObject.h"
#include "box.h"
#include <sgg/graphics.h>
#include <string>

class Block : public GameObject, public Box {
private:
    graphics::Brush m_pipe_brush;         // Brush for drawing the pipe
    graphics::Brush m_pipe_brush_debug;   // Brush for drawing the debug outline

    string m_texture;                // Texture file for the pipe
    const float m_pipe_speed = 2.0f;      // Speed at which the pipe moves left

    float m_initial_pos_x;
    float m_initial_pos_y;

public:
    Block(float pos_x, float pos_y, float width, float height, const string& texture);

    void update(float dt) override;
    void init() override;
    void draw() override;

    void setTexture(const std::string& texture);
    void move(float dt);                  // Method to move the pipe

    void reset();
};
