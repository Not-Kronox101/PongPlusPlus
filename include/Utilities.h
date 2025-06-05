#pragma once

#include "/opt/homebrew/Cellar/raylib/5.5/include/raylib.h"
#include <random>

namespace PongPlusPlus {

// Screen dimensions
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

// Game settings
constexpr int MAX_SCORE = 5;
constexpr float PADDLE_SPEED = 700.0f;
constexpr float BALL_INITIAL_SPEED = 300.0f;  // Increased from 200.0f
constexpr float BALL_MAX_SPEED = 700.0f;      // Increased from 500.0f
constexpr float BALL_SPEED_INCREASE = 1.2f;   // Speed increase factor per hit
constexpr float BALL_RADIUS = 10.0f;
constexpr float PADDLE_WIDTH = 15.0f;
constexpr float PADDLE_HEIGHT = 100.0f;
constexpr float POWERUP_SIZE = 80.0f;

// Colors
constexpr Color PADDLE_COLOR = WHITE;
constexpr Color BALL_COLOR = WHITE;
constexpr Color POWERUP_COLOR = YELLOW;
constexpr Color SCORE_COLOR = WHITE;
constexpr Color BACKGROUND_COLOR = BLACK;

// Utility functions
float clamp(float value, float min, float max);
float getRandomFloat(float min, float max);
int getRandomInt(int min, int max);

} // namespace PongPlusPlus 