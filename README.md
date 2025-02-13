# Snake Game

This is a simple console-based Snake Game implemented in C++.

## Features
- Classic snake gameplay with movement in four directions.
- Food spawning mechanism.
- Increasing difficulty based on user selection.
- Real-time movement and collision detection.
- Score tracking with the highest score display.

## Controls
```
W - Move Up
S - Move Down
A - Move Left
D - Move Right
X - Quit Game
Y - Restart Game (after Game Over)
N - Exit Game
```

## How to Play
1. Choose difficulty level: Easy, Medium, or Hard.
2. Control the snake using `W`, `A`, `S`, and `D` keys.
3. Eat the food (`@`) to grow the snake and increase your score.
4. Avoid colliding with the walls or the snake’s body.
5. Press `X` anytime to exit the game.
6. After game over, choose `Y` to restart or `N` to exit.

## Compilation & Execution
To compile the game, use a C++ compiler (MinGW for Windows recommended):
```sh
 g++ -o snake_game snake_game.cpp -static-libgcc -static-libstdc++
```
Run the game using:
```sh
 ./snake_game
```

## Requirements
- Windows OS (due to `windows.h` dependency)
- C++ Compiler (e.g., MinGW, MSVC)

## Notes
- The game utilizes the Windows API (`windows.h`) for cursor manipulation and console styling.
- This project is for educational purposes and can be modified for enhancements.

## License
This project is open-source. Feel free to modify and share it!

## Installation
Clone the repository:
```sh
git clone https://github.com/your-username/snake-game.git
cd snake-game
```

## Contribution
Feel free to submit pull requests or open issues to improve the game!

