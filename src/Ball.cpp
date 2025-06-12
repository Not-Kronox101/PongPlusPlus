#include "../include/Ball.h"
#include <cmath>

namespace PongPlusPlus {

Ball::Ball()
    : x(SCREEN_WIDTH / 2.0f)
    , y(SCREEN_HEIGHT / 2.0f)
    , radius(BALL_RADIUS)
    , speed(BALL_INITIAL_SPEED)
    , hasHitPaddle(false)
    , lastHitPaddle(nullptr)
{
    reset();
}

void Ball::update(Paddle& p1, Paddle& p2) {
    float deltaTime = GetFrameTime();
    
    float prevX = x;
    float prevY = y;
    
    x += velocity.x * deltaTime;
    y += velocity.y * deltaTime;
    
    if (checkPaddleCollision(p1, prevX, prevY)) {
        handlePaddleCollision(p1);
        lastHitPaddle = &p1;
        hasHitPaddle = true;
    }
    if (checkPaddleCollision(p2, prevX, prevY)) {
        handlePaddleCollision(p2);
        lastHitPaddle = &p2;
        hasHitPaddle = true;
    }
    
    if (y - radius <= 0 || y + radius >= SCREEN_HEIGHT) {
        velocity.y = -velocity.y;
    }

    if (hasHitPaddle) {
        float newSpeed = speed * BALL_SPEED_INCREASE;
        if (newSpeed <= BALL_MAX_SPEED) {
            setSpeed(newSpeed);
        }
        hasHitPaddle = false;  // Reset the flag
    }
}

void Ball::draw() const {
    DrawCircle(x, y, radius, BALL_COLOR);
}

void Ball::reset() {
    x = SCREEN_WIDTH / 2.0f;
    y = SCREEN_HEIGHT / 2.0f;
    lastHitPaddle = nullptr;
    speed = BALL_INITIAL_SPEED;  // Reset to initial speed
    
    // Random initial direction
    float angle = getRandomFloat(-PI/4, PI/4);
    if (getRandomInt(0, 1) == 0) {
        angle += PI;
    }
    
    velocity.x = cos(angle) * speed;
    velocity.y = sin(angle) * speed;
}

void Ball::setSpeed(float newSpeed) {
    speed = newSpeed;
    float magnitude = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    velocity.x = (velocity.x / magnitude) * speed;
    velocity.y = (velocity.y / magnitude) * speed;
}

bool Ball::checkPaddleCollision(const Paddle& paddle, float prevX, float prevY) const {
    // Calculate ball boundaries
    float ballLeft = x - radius;
    float ballRight = x + radius;
    float ballTop = y - radius;
    float ballBottom = y + radius;
    
    float paddleLeft = paddle.getX();
    float paddleRight = paddle.getX() + paddle.getWidth();
    float paddleTop = paddle.getY();
    float paddleBottom = paddle.getY() + paddle.getHeight();
    
    // Check if ball is moving towards the paddle
    bool movingTowardsPaddle = (velocity.x < 0 && paddle.getX() < x) || 
                              (velocity.x > 0 && paddle.getX() > x);
    
    // Check if ball was on the correct side of the paddle in the previous frame
    bool wasOnCorrectSide = (velocity.x < 0 && prevX > paddleRight) || 
                           (velocity.x > 0 && prevX < paddleLeft);
    
    // Check for collision
    bool collision = ballRight >= paddleLeft &&
                    ballLeft <= paddleRight &&
                    ballBottom >= paddleTop &&
                    ballTop <= paddleBottom;
    
    return movingTowardsPaddle && wasOnCorrectSide && collision;
}

void Ball::handlePaddleCollision(const Paddle& paddle) {
    float relativeIntersectY = (paddle.getY() + (paddle.getHeight() / 2)) - y;
    float normalizedIntersectY = relativeIntersectY / (paddle.getHeight() / 2);
    
    // Calculate bounce angle (-45 to 45 degrees)
    float bounceAngle = normalizedIntersectY * (PI / 4);
    
    // Determine if this is the right paddle
    bool isRightPaddle = paddle.getX() > SCREEN_WIDTH / 2;
    
    // Set velocity based on which paddle was hit
    if (isRightPaddle) {
        velocity.x = -cos(bounceAngle) * speed;  // Always move left after hitting right paddle
    } else {
        velocity.x = cos(bounceAngle) * speed;   // Always move right after hitting left paddle
    }
    velocity.y = -sin(bounceAngle) * speed;
    
    // Ensure ball doesn't get stuck in paddle
    if (velocity.x > 0) {
        x = paddle.getX() + paddle.getWidth() + radius + 2.0f;
    } else {
        x = paddle.getX() - radius - 2.0f;
    }
}

} 