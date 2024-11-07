
# Ludo-CLI

**Ludo-CLI** is a command-line implementation of the traditional board game Ludo. This program, written in C, simulates the gameplay and rules of the classic game, supporting up to four players. The objective for each player is to navigate all their pieces from the starting base to the "Home" area before the others.

## Table of Contents

- [About the Game](#about-the-game)
- [Rules and Gameplay](#rules-and-gameplay)
- [Code Structure](#code-structure)
- [Compiling and Running the Game](#compiling-and-running-the-game)
- [Example Output](#example-output)
- [Author](#author)
- [License](#license)

---

## About the Game

Ludo is a popular board game derived from the ancient Indian game Pachisi. This version of Ludo uses a six-sided die and allows players to capture opponent pieces, adding strategy and excitement. **Ludo-CLI** simulates this experience with a focus on core gameplay mechanics, making it suitable for educational purposes and for those interested in studying turn-based game programming.

## Rules and Gameplay

### Setup
- **Players**: Up to four players, each assigned a color: **Red**, **Yellow**, **Green**, or **Blue**.
- **Pieces**: Each player has four pieces, starting in their color-specific base.
- **Objective**: Move all four pieces from the base to the home area, following a clockwise path on the board.

### Turn Order
1. **Dice Roll**:
   - Each player rolls a six-sided die once per turn.
   - A roll of six allows the player to either move a piece from the base to the starting point or continue moving a piece already in play. A six also grants an additional roll.
   - Rolling three consecutive sixes forfeits the turn.

2. **Piece Movement**:
   - Pieces advance based on dice rolls.
   - Landing on an opponent's piece sends that piece back to its base.

3. **Winning Condition**:
   - The first player to move all four pieces to their home wins. The game can continue to determine further rankings.

4. **Special Cells**:
   - Approach cells and Home Straight paths are specific to each player color.

## Code Structure

The project contains the following files:

- **`main.c`**: Contains the main function that initializes the game.
- **`game_logic.c`**: Implements the core game logic, including player moves, dice rolling, capturing, and win conditions.
- **`types.h`**: Defines structures and constants used throughout the program.

### Functions

- **`game()`**: The main game loop, which controls player turns, manages the dice rolls, and checks for win conditions.
- **`movePiece()`**: Moves a piece based on dice rolls and captures opponents when applicable.
- **`capture()`**: Checks if a player lands on an opponent’s piece and processes the capture.
- **`displaySummary()`**: Displays a round summary of each player’s pieces.

## Compiling and Running the Game

### Requirements
- **Compiler**: GCC or compatible C compiler

### Instructions
1. **Compile the Program**:
   ```bash
   gcc main.c game_logic.c -o ludo-cli
   ```
2. **Run the Program**:
   ```bash
   ./ludo-cli
   ```

## Example Output

The simulation provides detailed output, including:
- **Dice Rolls**: Each player's roll results.
- **Piece Movements**: Tracks pieces as they move, capture opponents, and enter home.
- **Game Results**: Announces the winning player and game status after each round.

## Author
Kalana Jinendra

## License
This project is open for educational and non-commercial use.

---
