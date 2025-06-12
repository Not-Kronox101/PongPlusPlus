#pragma once

#include <memory>
#include <vector>
#include "raylib.h"
#include "Paddle.h"
#include "Ball.h"
#include "PowerUp.h"
#include "UI.h"
#include "Utilities.h"


namespace PongPlusPlus {

enum class GameState {
    START_SCREEN,
    PLAYING,
    END_SCREEN
};

class GameManager {
public:
    GameManager();
    ~GameManager();
    
    void update();
    void draw();
    bool isGameOver() const { return gameOver; }
    
private:
    void initializeGame();
    void handleBallOutOfBounds();
    void spawnPowerUp();
    void handlePowerUpCollision();
    void resetGame();
    void drawStartScreen();
    void drawEndScreen();
    
    std::unique_ptr<Paddle> player1;
    std::unique_ptr<Paddle> player2;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<PowerUp> powerUp;
    std::unique_ptr<UI> ui;
    
    int player1Score;
    int player2Score;
    bool gameOver;
    float powerUpSpawnTimer;
    const float POWERUP_SPAWN_INTERVAL = 10.0f;
    
    GameState currentState;
    int winner; // 1 for player1, 2 for player2, 0 for no winner yet
};

} 