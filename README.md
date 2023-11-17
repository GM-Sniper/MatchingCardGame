# Matching Cards Game - Qt Implementation

<img width="355" alt="image" src="https://github.com/GM-Sniper/MatchingCardGame/assets/144553627/69a80818-9d23-4b1e-a4f3-4817acd3e0b9">

<img width="341" alt="image" src="https://github.com/GM-Sniper/MatchingCardGame/assets/144553627/dca6cf5a-f2b1-4cef-9a35-00e717f53403">



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

- **Login Window**: Before starting the game, users must log in with their credentials. Successful login displays the user's name and image on the game screen. (Use username: Admin and password: admin to log into the game. To change the username or pasword, add an element in the array in users.h)

### Game Flow

- Players navigate the card grid using keyboard arrows and open cards with the spacebar.
- The game counts openings and matches, displaying progress and end conditions accordingly.
- Users can use the 'S' key to reveal all cards temporarily.

### Requirements

- Qt framework installed on your machine.
- Compatible OS (Windows, macOS, Linux) for Qt development.

### Installation

1. Clone the repository to your local machine.
2. Open the project in Qt Creator or your preferred IDE.
3. Build and run the project.

### Usage

- Follow on-screen instructions and keyboard controls to interact with the game.
- Use 'S' to reveal all cards temporarily and navigate using arrow keys and the spacebar.

## Contribution

Contributions to the game project are welcome! Feel free to fork the repository, make changes, and submit pull requests.

## License

This project is licensed under the [MIT License](LICENSE).
- Winning the game displays a victory message, while exceeding move limits results in a game over.

### Implementation Details

The game is built using the Qt framework, integrating C++ programming for logic and user interface elements. Graphics design is essential for card images and other game assets.
