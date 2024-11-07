
# LUDO-CS Game - README

## Overview
LUDO-CS is an enhanced and strategic version of the classic Ludo game. Based on traditional rules, LUDO-CS adds player-specific behaviors, options for clockwise and counterclockwise movement, and special mystery cells with various effects, creating a more dynamic and unpredictable gameplay experience.

## Game Rules and Features

### Players and Setup
1. **Number of Players**: Four players, each assigned a color (Red, Yellow, Green, or Blue).
2. **Pieces**: Each player has four pieces that must travel from their base to their home.
3. **Starting and Movement**: A six-sided die determines movement. Rolling a six allows a piece to leave the base, grants an additional turn, and allows players to roll up to two more consecutive sixes. Rolling three consecutive sixes forfeits the turn.

### Traditional Gameplay Rules
1. **Piece Movement**: Pieces advance by the value shown on the die.
2. **Capturing Opponent Pieces**: Landing on an opponent’s piece sends it back to its base.
3. **Exact Roll for Home Entry**: Pieces must roll the exact number to enter the home zone.

### Extended LUDO-CS Rules

#### Unique Player Behaviors
Each player has a distinctive strategy:
- **Red (Aggressive)**: Prioritizes capturing opponent pieces over advancing toward home.
- **Yellow (Winning Focus)**: Focuses on moving pieces home rather than capturing.
- **Green (Homeward Focus)**: Prioritizes advancing pieces home over capturing opponents.
- **Blue (Mystery Cell Enthusiast)**: Moves pieces in a cyclic order, focusing on mystery cells when moving counterclockwise.

#### Clockwise and Counterclockwise Movement
1. **Clockwise/Counterclockwise Assignment**: When a player rolls a six to move a piece onto the board, a coin toss determines its movement direction:
   - **Heads**: Moves clockwise (traditional direction).
   - **Tails**: Moves counterclockwise.
2. **Changing Direction**: Once on the board, pieces follow their assigned direction unless affected by a mystery cell (e.g., Pita-Kotuwa) that may alter it.

#### Mystery Cells
Mystery cells introduce an element of surprise with unique effects:

1. **Appearance**: A mystery cell appears randomly on any of the 52 cells in the standard path after two rounds and changes location every four rounds. It does not appear on an occupied cell or in the same spot consecutively.

2. **Effects of Landing on a Mystery Cell**:
   - **Teleportation**: A piece may be teleported to one of six possible locations:
     - **Bhawana** (9 cells from Yellow’s approach)
     - **Kotuwa** (27 cells from Yellow’s approach)
     - **Pita-Kotuwa** (46 cells from Yellow’s approach)
     - **Base**: Returns the piece to its base.
     - **X (Starting Point)**: Moves the piece to its color-specific starting position.
     - **Approach Cell**: Moves the piece to its color’s approach cell, just before the home straight.
   
   - **Location-Specific Effects**:
     - **Bhawana**: The piece may feel energized (doubling movement) or sick (halving movement) for the next four rounds.
     - **Kotuwa**: The piece is restricted from movement for the next four rounds. If the player rolls three consecutive threes during this period, the piece is sent back to base.
     - **Pita-Kotuwa**: If the piece was moving clockwise, it switches to counterclockwise. If it was already moving counterclockwise, it is teleported to Kotuwa.

### Winning Condition
The first player to bring all their pieces home wins the game. The game may continue to determine second, third, and fourth places.

## Project Setup

1. **Language**: C
2. **Compilation**:
   ```bash
   gcc main.c game_logic.c -o ludo-cs
   ```
3. **Execution**:
   ```bash
   ./ludo-cs
   ```

## File Structure
This project is divided into three main files:

- **types.h**: Contains type definitions and structure declarations used throughout the game, including `Player`, `Piece`, and `Cell` structures.
- **main.c**: Contains the `main` function that initiates the game by calling the `game()` function in `game_logic.c`.
- **game_logic.c**: Implements the core game mechanics, including player behaviors, piece movement, capturing logic, direction changes, and the mystery cell effects.

## License
This project is for educational purposes and is licensed for personal use only.
