#pragma once

#include "Utilities.h"
#include </opt/homebrew/Cellar/raylib/5.5/include/raylib.h>

namespace PongPlusPlus {

class UI {
public:
    UI();
    
    void drawScore(int p1Score, int p2Score) const;
    void drawWinner(int winnerID) const;
    void drawPowerUpInfo(const char* text) const;
    void drawRestartMessage() const;
    void drawPowerUpMessage(const char* message) const;
    
private:
    Font font;
    int fontSize;
};

} // namespace PongPlusPlus 