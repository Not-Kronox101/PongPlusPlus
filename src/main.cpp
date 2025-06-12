#include "../include/GameManager.h"

int main() {
    InitWindow(PongPlusPlus::SCREEN_WIDTH, PongPlusPlus::SCREEN_HEIGHT, "Pong++");
    SetTargetFPS(60);
    
    PongPlusPlus::GameManager gameManager;
    
    while (!WindowShouldClose()) {
        gameManager.update();
        gameManager.draw();
    }
    
    CloseWindow();
    return 0;
} 