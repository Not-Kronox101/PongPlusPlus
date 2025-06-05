# Pong++

A modern take on the classic Pong game with power-ups and enhanced gameplay features.

## Features

- Local 2-player multiplayer
- Power-ups that affect gameplay:
  - Speed Boost: Increases ball velocity
  - Paddle Shrink/Grow: Temporarily changes paddle size
  - Multiball: Adds extra balls to the playfield
- Smooth physics-based movement
- Score tracking and win screen

## Controls

- Player 1 (Left):
  - W: Move up
  - S: Move down

- Player 2 (Right):
  - Up Arrow: Move up
  - Down Arrow: Move down

- Space: Restart game after game over

## Building the Game

### Prerequisites

- CMake (version 3.11 or higher)
- C++ compiler with C++17 support
- Git

### Build Steps

1. Clone the repository:
```bash
git clone https://github.com/yourusername/pong-plus-plus.git
cd pong-plus-plus
```

2. Create a build directory and navigate to it:
```bash
mkdir build
cd build
```

3. Generate build files:
```bash
cmake ..
```

4. Build the game:
```bash
cmake --build .
```

5. Run the game:
```bash
./PongPlusPlus
```

## Game Rules

- First player to reach 5 points wins
- Power-ups spawn every 10 seconds
- When a power-up is collected, its effect is applied randomly to one of the players
- The multiball power-up adds two extra balls to the playfield

## License

This project is licensed under the MIT License - see the LICENSE file for details. 