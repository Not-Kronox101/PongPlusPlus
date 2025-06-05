#pragma once

#include <memory>
#include <vector>
#include "/opt/homebrew/Cellar/raylib/5.5/include/raylib.h"
#include "Paddle.h"
#include "Ball.h"
#include "PowerUp.h"
#include "UI.h"
#include "Utilities.h"


namespace PongPlusPlus {

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
};

} // namespace PongPlusPlus 