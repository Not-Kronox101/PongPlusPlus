#include "../include/GameManager.h"

int main() {
    // Initialize window
    InitWindow(PongPlusPlus::SCREEN_WIDTH, PongPlusPlus::SCREEN_HEIGHT, "Pong++");
    SetTargetFPS(60);
    
    // Create game manager
    PongPlusPlus::GameManager gameManager;
    
    // Main game loop
    while (!WindowShouldClose()) {
        gameManager.update();
        gameManager.draw();
    }
    
    // Cleanup
    CloseWindow();
    return 0;
} 