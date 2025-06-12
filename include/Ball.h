#pragma once

#include "Utilities.h"
#include "Paddle.h"
#include "raylib.h"

namespace PongPlusPlus {

class Ball {
public:
    Ball();
    
    void update(Paddle& p1, Paddle& p2);
    void draw() const;
    void reset();
    void setSpeed(float newSpeed);
    
    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getRadius() const { return radius; }
    float getSpeed() const { return speed; }
    const Paddle* getLastHitPaddle() const { return lastHitPaddle; }
    
private:
    bool checkPaddleCollision(const Paddle& paddle, float prevX, float prevY) const;
    void handlePaddleCollision(const Paddle& paddle);
    
    float x;
    float y;
    float radius;
    float speed;
    bool hasHitPaddle;
    Vector2 velocity;
    const Paddle* lastHitPaddle;
};

} 