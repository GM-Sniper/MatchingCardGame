# Matching Cards Game - Qt Implementation

## Introduction

Welcome to the Matching Cards Game implemented in Qt! This game challenges players to find matching pairs of cards while adhering to specific rules and interactions.

### Game Features

1. **Initial Card Display**: All cards are initially hidden, awaiting the player's interaction to reveal their contents.

2. **Show All Cards Option**: The player can press the 'S' key to display all cards temporarily. Pressing 'S' again hides the cards and allows continued gameplay.

3. **Keyboard Controls**: Navigate the game board using arrow keys (right/left/up/down) and open a card using the spacebar.

4. **Selector Tool**: A selector assists in navigating and showing cards, disappearing upon card selection or opening.

5. **Openings Counter**: Keep track of the number of times a player opens a card, displayed prominently in red on the screen.

6. **Matched Card Mechanics**:
    - Matching pairs update the score and cause both cards to disappear after a brief 2-second display.
    - Non-matching pairs automatically close after 2 seconds of display.

7. **Game End Conditions**:
    - Winning: On successful completion, a green message confirms the victory, and the selector disappears.
    - Losing: Exceeding 40 moves triggers a "Game Over" message.

### Bonus Feature

- **Login Window**: Before starting the game, users must log in with their credentials. Successful login displays the user's name and image on the game screen.

### Game Flow

- Players navigate the card grid using keyboard arrows and open cards with the spacebar.
- The game counts openings and matches, displaying progress and end conditions accordingly.
- Users can use the 'S' key to reveal all cards temporarily.
- Winning the game displays a victory message, while exceeding move limits results in a game over.

### Implementation Details

The game is built using the Qt framework, integrating C++ programming for logic and user interface elements. Graphics design is essential for card images and other game assets.
