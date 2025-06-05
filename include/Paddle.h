#pragma once

#include "../include/Utilities.h"
#include "/opt/homebrew/Cellar/raylib/5.5/include/raylib.h"

namespace PongPlusPlus {

class Paddle {
public:
    Paddle(float x, float y);
    
    void update(bool isPlayer1);
    void draw() const;
    void resize(float scale);
    void setSpeedMultiplier(float multiplier) { speedMultiplier = multiplier; }
    
    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    
    // Setters
    void setY(float newY) { y = newY; }
    
private:
    float x;
    float y;
    float width;
    float height;
    float originalHeight;
    float speed;
    float speedMultiplier;
};

} // namespace PongPlusPlus 