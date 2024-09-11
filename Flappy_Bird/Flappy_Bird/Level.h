#pragma once

#include <vector>
#include "GameObject.h"
#include "Coin.h"
#include "Coin_Score.h"
#include "Pipe.h"
#include "Player.h"
#include "Hearts.h"
#include <sgg/graphics.h>

class Level : public GameObject {
private:
    graphics::Brush m_brush_background;  // Brush for the game background
    graphics::Brush m_brush_ending_background;  // Brush for the ending background

    std::vector<Pipe> m_pipes;           // List of pipes in the level
    std::vector<Coin> m_coins;           // List of coins in the level
    std::vector<Hearts> m_hearts;        // List of heart images representing lives
    
    std::vector<Coin_Score> m_coin_score; // List of coins images representing scores
   
    std::vector<GameObject*> m_static_objects;   // List of static game objects
    std::vector<GameObject*> m_dynamic_objects;  // List of dynamic game objects

    bool m_game_paused = false; // Pause flag
    bool m_game_over = false;   // Game over flag
    float m_game_over_timer = 0.0f;  // Timer to delay game stop after game over

    int m_lives; // Variable to store lives
    int m_coins_for_score;

    void checkCollisions();   // Method to check for collisions
    void loseLife();          // Method to handle losing a life
    void loseCoin();

    typedef enum { STATUS_START, STATUS_PLAYING} status_t;

    status_t status = STATUS_START;

    void updateStartScreen();
    void updateLevelScreen(float dt);

    void drawStartScreen();
    void drawLevelScreen();



public:

    int sum_coins = 0;

    Level(const std::string& name);
    ~Level();

    void init() override;     // Initialize the level
    void update(float dt) override;  // Update the level
    void draw() override;     // Draw the level

    void resetLevel();        // Method to reset the level


    friend ostream& operator<< (ostream& left, const vector<Coin_Score>& right) {
        
    }
};
