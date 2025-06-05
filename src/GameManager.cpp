#include "../include/GameManager.h"

namespace PongPlusPlus {

GameManager::GameManager()
    : player1Score(0)
    , player2Score(0)
    , gameOver(false)
    , powerUpSpawnTimer(0.0f)
{
    initializeGame();
}

GameManager::~GameManager() = default;

void GameManager::initializeGame() {
    // Create paddles
    player1 = std::make_unique<Paddle>(50, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2);
    player2 = std::make_unique<Paddle>(SCREEN_WIDTH - 50 - PADDLE_WIDTH, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2);
    
    // Create ball
    ball = std::make_unique<Ball>();
    
    // Create power-up
    powerUp = std::make_unique<PowerUp>();
    
    // Create UI
    ui = std::make_unique<UI>();
}

void GameManager::update() {
    if (gameOver) {
        if (IsKeyPressed(KEY_SPACE)) {
            resetGame();
        }
        return;
    }
    
    // Update paddles
    player1->update(true);
    player2->update(false);
    
    // Update main ball
    ball->update(*player1, *player2);
    
    // Update power-up
    powerUp->update(*ball);
    
    // Handle power-up spawning
    powerUpSpawnTimer += GetFrameTime();
    if (powerUpSpawnTimer >= POWERUP_SPAWN_INTERVAL) {
        spawnPowerUp();
        powerUpSpawnTimer = 0.0f;
    }
    
    // Handle power-up collision
    handlePowerUpCollision();
    
    // Handle ball out of bounds
    handleBallOutOfBounds();
}

void GameManager::draw() {
    BeginDrawing();
    {
        ClearBackground(BACKGROUND_COLOR);
        
        // Draw paddles
        player1->draw();
        player2->draw();
        
        // Draw ball only if game is not over
        if (!gameOver) {
            ball->draw();
        }
        
        // Draw power-up
        powerUp->draw();
        
        // Draw UI
        ui->drawScore(player1Score, player2Score);
        
        // Draw power-up message if active
        if (powerUp->getMessageTimer() > 0) {
            ui->drawPowerUpMessage(powerUp->getMessage());
        }
        
        if (gameOver) {
            ui->drawWinner(player1Score > player2Score ? 1 : 2);
            ui->drawRestartMessage();
        }
    }
    EndDrawing();
}

void GameManager::handleBallOutOfBounds() {
    // Check main ball
    if (ball->getX() < 0) {
        player2Score++;
        ball->reset();
    } else if (ball->getX() > SCREEN_WIDTH) {
        player1Score++;
        ball->reset();
    }
    
    // Check for game over
    if (player1Score >= MAX_SCORE || player2Score >= MAX_SCORE) {
        gameOver = true;
    }
}

void GameManager::spawnPowerUp() {
    if (!powerUp->isActive()) {
        powerUp->spawn();
    }
}

void GameManager::handlePowerUpCollision() {
    if (!powerUp->isActive()) return;
    
    // Check collision with main ball
    float dx = ball->getX() - powerUp->getX();
    float dy = ball->getY() - powerUp->getY();
    float distance = sqrt(dx * dx + dy * dy);
    
    if (distance < ball->getRadius() + POWERUP_SIZE / 2) {
        // Apply to the last hit paddle
        const Paddle* lastHit = ball->getLastHitPaddle();
        if (lastHit) {
            powerUp->setTargetPaddle(*const_cast<Paddle*>(lastHit));
            powerUp->apply(*ball);
        }
        powerUp->setActive(false);
    }
}

void GameManager::resetGame() {
    player1Score = 0;
    player2Score = 0;
    gameOver = false;
    initializeGame();
}

} // namespace PongPlusPlus 