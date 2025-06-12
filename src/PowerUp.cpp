#include "../include/PowerUp.h"

namespace PongPlusPlus {

PowerUp::PowerUp()
    : active(false)
    , x(0)
    , y(0)
    , size(POWERUP_SIZE)
    , type(PowerUpType::SPEED_BOOST)
    , duration(3.0f)
    , timeRemaining(0.0f)
    , targetPaddle(nullptr)
    , message(nullptr)
    , messageTimer(0.0f)
{
}

void PowerUp::update(Ball& ball) {
    if (!active) return;
    
    float dx = ball.getX() - x;
    float dy = ball.getY() - y;
    float distance = sqrt(dx * dx + dy * dy);
    
    if (messageTimer > 0) {
        messageTimer -= GetFrameTime();
        if (messageTimer <= 0) {
            message = nullptr;
        }
    }
    
    // Update time remaining for active effects
    if (timeRemaining > 0) {
        timeRemaining -= GetFrameTime();
        if (timeRemaining <= 0) {
            // Reset effects when duration expires
            if (targetPaddle) {
                targetPaddle->resize(1.0f);  // Reset to original size
                targetPaddle->setSpeedMultiplier(1.0f);  // Reset speed multiplier
            }
            timeRemaining = 0;
        }
    }
}

void PowerUp::draw() const {
    if (!active) return;
    
    // Draw power-up with different colors based on type
    Color color;
    switch (type) {
        case PowerUpType::SPEED_BOOST:
            color = RED;
            break;
        case PowerUpType::PADDLE_SHRINK:
            color = BLUE;
            break;
        case PowerUpType::PADDLE_GROW:
            color = GREEN;
            break;
    }
    
    // Draw square instead of circle
    DrawCircle(x - size/2, y - size/2, size, size, color);
}

void PowerUp::spawn() {
    active = true;
    
    // Calculate the middle area between paddles
    float leftBound = 50 + PADDLE_WIDTH + POWERUP_SIZE;
    float rightBound = SCREEN_WIDTH - 50 - PADDLE_WIDTH - POWERUP_SIZE;  
    
    // Set x, y positions within the middle area
    x = getRandomFloat(leftBound, rightBound);
    y = getRandomFloat(size, SCREEN_HEIGHT - size);
    
    int typeIndex = getRandomInt(0, 2);
    type = static_cast<PowerUpType>(typeIndex);
}

void PowerUp::apply(Ball& ball) {
    if (!targetPaddle) return;
    
    // Determine which player got the power-up
    bool isPlayer1 = targetPaddle->getX() < SCREEN_WIDTH / 2;
    const char* playerText = isPlayer1 ? "Player 1" : "Player 2";
    
    switch (type) {
        case PowerUpType::SPEED_BOOST:
            targetPaddle->setSpeedMultiplier(2.0f);  // Double the paddle speed
            timeRemaining = duration;
            message = TextFormat("%s got Speed Boost!", playerText);
            break;
            
        case PowerUpType::PADDLE_SHRINK:
            targetPaddle->resize(0.5f);
            timeRemaining = duration;
            message = TextFormat("%s's paddle shrunk!", playerText);
            break;
            
        case PowerUpType::PADDLE_GROW:
            targetPaddle->resize(2.0f);
            timeRemaining = duration;
            message = TextFormat("%s's paddle grew!", playerText);
            break;
    }
    
    messageTimer = 2.0f; 
}

} 