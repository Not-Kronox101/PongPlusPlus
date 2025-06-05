#include "../include/Paddle.h"

namespace PongPlusPlus {

Paddle::Paddle(float x, float y)
    : x(x)
    , y(y)
    , width(PADDLE_WIDTH)
    , height(PADDLE_HEIGHT)
    , originalHeight(PADDLE_HEIGHT)
    , speed(PADDLE_SPEED)
    , speedMultiplier(1.0f)
{
}

void Paddle::update(bool isPlayer1) {
    float moveAmount = speed * speedMultiplier * GetFrameTime();
    
    if (isPlayer1) {
        if (IsKeyDown(KEY_W)) {
            y -= moveAmount;
        }
        if (IsKeyDown(KEY_S)) {
            y += moveAmount;
        }
    } else {
        if (IsKeyDown(KEY_UP)) {
            y -= moveAmount;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y += moveAmount;
        }
    }
    
    // Keep paddle within screen bounds
    y = clamp(y, 0, SCREEN_HEIGHT - height);
}

void Paddle::draw() const {
    DrawRectangle(x, y, width, height, PADDLE_COLOR);
}

void Paddle::resize(float scale) {
    float newHeight = originalHeight * scale;
    float oldY = y;
    y = y + (height - newHeight) / 2;  // Center the paddle vertically
    height = newHeight;
    
    // Ensure paddle stays within screen bounds
    if (y < 0) y = 0;
    if (y + height > SCREEN_HEIGHT) y = SCREEN_HEIGHT - height;
}

} // namespace PongPlusPlus 