#pragma once

#include "Utilities.h"
#include "Paddle.h"
#include "Ball.h"
#include "raylib.h"

namespace PongPlusPlus {

enum class PowerUpType {
    SPEED_BOOST,
    PADDLE_SHRINK,
    PADDLE_GROW
};

class PowerUp {
public:
    PowerUp();
    
    void update(Ball& ball);
    void draw() const;
    void spawn();
    void apply(Ball& ball);
    void setTargetPaddle(Paddle& paddle) { targetPaddle = &paddle; }
    
    // Getters
    bool isActive() const { return active; }
    float getX() const { return x; }
    float getY() const { return y; }
    PowerUpType getType() const { return type; }
    void setActive(bool value) { active = value; }
    const char* getMessage() const { return message; }
    float getMessageTimer() const { return messageTimer; }
    
private:
    bool active;
    float x;
    float y;
    float size;
    PowerUpType type;
    float duration;
    float timeRemaining;
    Paddle* targetPaddle;
    const char* message;
    float messageTimer;
};

} 