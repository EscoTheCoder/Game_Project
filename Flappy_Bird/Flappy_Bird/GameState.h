#pragma once

#include "sgg/graphics.h"
#include <string>

using namespace std;

class GameState {

private:
    string m_asset_path = "assets\\";

    float m_canvas_width = 6.0f;
    float m_canvas_height = 6.0f;

    static GameState* m_unique_instance;

    GameState();

    class Player* m_player = nullptr;
    class Level* m_current_level = nullptr;

public:
    float get_CanvasWidth();
    float get_CanvasHeight();

    float m_global_offset_x = 0.0f;
    float m_global_offset_y = 0.0f;
    bool m_debugging = false;

    void init();
    void draw();
    void update(float dt);

    static GameState* getInstance();
    ~GameState();

    string getAssetDir();
    string getFullAssetPath(const string& asset);

    class Player* get_Player() {
        return m_player;
    }

    void set_Player(class Player* m_player) {
        this->m_player = m_player;
    }
};
