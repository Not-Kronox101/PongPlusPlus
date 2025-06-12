#include "../include/GameManager.h"

namespace PongPlusPlus {

GameManager::GameManager()
    : player1Score(0)
    , player2Score(0)
    , gameOver(false)
    , powerUpSpawnTimer(0.0f)
    , currentState(GameState::START_SCREEN)
    , winner(0)
{
    initializeGame();
}

GameManager::~GameManager() = default;

void GameManager::initializeGame() {
    player1 = std::make_unique<Paddle>(50, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2);
    player2 = std::make_unique<Paddle>(SCREEN_WIDTH - 50 - PADDLE_WIDTH, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2);
    
    ball = std::make_unique<Ball>();
    
    powerUp = std::make_unique<PowerUp>();
    
    ui = std::make_unique<UI>();
}

void GameManager::update() {
    switch (currentState) {
        case GameState::START_SCREEN:
            if (IsKeyPressed(KEY_SPACE)) {
                currentState = GameState::PLAYING;
            }
            break;
            
        case GameState::PLAYING:
            player1->update(true);
            player2->update(false);
            
            ball->update(*player1, *player2);
            
            powerUp->update(*ball);


            powerUpSpawnTimer += GetFrameTime();
            if (powerUpSpawnTimer >= POWERUP_SPAWN_INTERVAL) {
                spawnPowerUp();
                powerUpSpawnTimer = 0.0f;
            }
            
            handlePowerUpCollision();

            handleBallOutOfBounds();
            
            // Check for game over
            if (gameOver) {
                winner = (player1Score > player2Score) ? 1 : 2;
                currentState = GameState::END_SCREEN;
            }
            break;
            
        case GameState::END_SCREEN:
            if (IsKeyPressed(KEY_SPACE)) {
                resetGame();
                currentState = GameState::START_SCREEN;
            }
            break;
    }
}

void GameManager::draw() {
    BeginDrawing();
    {
        ClearBackground(BACKGROUND_COLOR);
        
        switch (currentState) {
            case GameState::START_SCREEN:
                drawStartScreen();
                break;
                
            case GameState::PLAYING:
                player1->draw();
                player2->draw();
                
                ball->draw();
                
                powerUp->draw();
                
                ui->drawScore(player1Score, player2Score);
                
                if (powerUp->getMessageTimer() > 0) {
                    ui->drawPowerUpMessage(powerUp->getMessage());
                }
                break;
                
            case GameState::END_SCREEN:
                drawEndScreen();
                break;
        }
    }
    EndDrawing();
}

void GameManager::drawStartScreen() {
    const char* title = "PONG++";
    const char* startMessage = "Press SPACE to Start";
    
    int titleWidth = MeasureText(title, 60);
    int messageWidth = MeasureText(startMessage, 30);
    
    // Draw title and start message
    DrawText(title, SCREEN_WIDTH/2 - titleWidth/2, SCREEN_HEIGHT/6, 60, WHITE);
    DrawText(startMessage, SCREEN_WIDTH/2 - messageWidth/2, SCREEN_HEIGHT*4/5, 30, WHITE);
    
    // Draw control diagram
    const int PADDLE_WIDTH = 20;
    const int PADDLE_HEIGHT = 100;
    const int PADDLE_SPACING = 200;
    const int CENTER_Y = SCREEN_HEIGHT/2;
    
    // Draw left paddle (Player 1)
    DrawRectangle(SCREEN_WIDTH/2 - PADDLE_SPACING, CENTER_Y - PADDLE_HEIGHT/2, 
                 PADDLE_WIDTH, PADDLE_HEIGHT, WHITE);
    DrawText("W", SCREEN_WIDTH/2 - PADDLE_SPACING - 30, CENTER_Y - 40, 30, WHITE);
    DrawText("S", SCREEN_WIDTH/2 - PADDLE_SPACING - 30, CENTER_Y + 10, 30, WHITE);
    DrawText("Player 1", SCREEN_WIDTH/2 - PADDLE_SPACING - 80, CENTER_Y - PADDLE_HEIGHT/2 - 30, 20, WHITE);
    
    // Draw right paddle (Player 2)
    DrawRectangle(SCREEN_WIDTH/2 + PADDLE_SPACING - PADDLE_WIDTH, CENTER_Y - PADDLE_HEIGHT/2, 
                 PADDLE_WIDTH, PADDLE_HEIGHT, WHITE);
    DrawText("UP", SCREEN_WIDTH/2 + PADDLE_SPACING + 10, CENTER_Y - 40, 20, WHITE);
    DrawText("DOWN", SCREEN_WIDTH/2 + PADDLE_SPACING + 10, CENTER_Y + 10, 20, WHITE);
    DrawText("Player 2", SCREEN_WIDTH/2 + PADDLE_SPACING + 10, CENTER_Y - PADDLE_HEIGHT/2 - 30, 20, WHITE);
    
    // Draw connecting lines
    DrawLine(SCREEN_WIDTH/2 - PADDLE_SPACING - 30, CENTER_Y - 40, 
             SCREEN_WIDTH/2 - PADDLE_SPACING, CENTER_Y - 40, WHITE);
    DrawLine(SCREEN_WIDTH/2 - PADDLE_SPACING - 30, CENTER_Y + 10, 
             SCREEN_WIDTH/2 - PADDLE_SPACING, CENTER_Y + 10, WHITE);
    DrawLine(SCREEN_WIDTH/2 + PADDLE_SPACING, CENTER_Y - 40, 
             SCREEN_WIDTH/2 + PADDLE_SPACING + 50, CENTER_Y - 40, WHITE);
    DrawLine(SCREEN_WIDTH/2 + PADDLE_SPACING, CENTER_Y + 10, 
             SCREEN_WIDTH/2 + PADDLE_SPACING + 70, CENTER_Y + 10, WHITE);
}

void GameManager::drawEndScreen() {
    const char* gameOverText = "GAME OVER";
    char winnerText[50];
    const char* restartMessage = "Press SPACE to Play Again";
    
    sprintf(winnerText, "Player %d Wins!", winner);
    
    int gameOverWidth = MeasureText(gameOverText, 60);
    int winnerWidth = MeasureText(winnerText, 40);
    int restartWidth = MeasureText(restartMessage, 30);
    
    DrawText(gameOverText, SCREEN_WIDTH/2 - gameOverWidth/2, SCREEN_HEIGHT/3, 60, WHITE);
    DrawText(winnerText, SCREEN_WIDTH/2 - winnerWidth/2, SCREEN_HEIGHT/2, 40, WHITE);
    DrawText(restartMessage, SCREEN_WIDTH/2 - restartWidth/2, SCREEN_HEIGHT*2/3, 30, WHITE);
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
    winner = 0;
    initializeGame();
}

} 