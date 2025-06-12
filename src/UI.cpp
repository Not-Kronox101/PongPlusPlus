#include "../include/UI.h"

namespace PongPlusPlus {

UI::UI()
    : fontSize(40)
{
    // Load default font
    font = GetFontDefault();
}

void UI::drawScore(int p1Score, int p2Score) const {
    char scoreText[32];
    sprintf(scoreText, "%d - %d", p1Score, p2Score);
    
    Vector2 textSize = MeasureTextEx(font, scoreText, fontSize, 1);
    Vector2 position = {
        (SCREEN_WIDTH - textSize.x) / 2,
        20
    };
    
    DrawTextEx(font, scoreText, position, fontSize, 1, SCORE_COLOR);
}

void UI::drawWinner(int winnerID) const {
    const char* text = winnerID == 1 ? "Player 1 Wins!" : "Player 2 Wins!";
    
    Vector2 textSize = MeasureTextEx(font, text, fontSize, 1);
    Vector2 position = {
        (SCREEN_WIDTH - textSize.x) / 2,
        (SCREEN_HEIGHT - textSize.y) / 2
    };
    
    DrawTextEx(font, text, position, fontSize, 1, SCORE_COLOR);
}

void UI::drawPowerUpInfo(const char* text) const {
    Vector2 textSize = MeasureTextEx(font, text, fontSize * 0.5f, 1);
    Vector2 position = {
        (SCREEN_WIDTH - textSize.x) / 2,
        SCREEN_HEIGHT - textSize.y - 20
    };
    
    DrawTextEx(font, text, position, fontSize * 0.5f, 1, SCORE_COLOR);
}

void UI::drawRestartMessage() const {
    const char* text = "Press SPACE to play again";
    
    Vector2 textSize = MeasureTextEx(font, text, fontSize * 0.5f, 1);
    Vector2 position = {
        (SCREEN_WIDTH - textSize.x) / 2,
        (SCREEN_HEIGHT - textSize.y) / 2 + 50  // Position below the winner text
    };
    
    DrawTextEx(font, text, position, fontSize * 0.5f, 1, SCORE_COLOR);
}

void UI::drawPowerUpMessage(const char* message) const {
    Vector2 textSize = MeasureTextEx(font, message, fontSize * 0.5f, 1);
    Vector2 position = {
        (SCREEN_WIDTH - textSize.x) / 2,
        SCREEN_HEIGHT - textSize.y - 50  // Position above the bottom of the screen
    };
    
    DrawTextEx(font, message, position, fontSize * 0.5f, 1, YELLOW);
}

} 