# My Hunter - C Project

## Description
**My Hunter** is a **2D shooting game** inspired by the classic **Duck Hunt**. The goal is to shoot ducks as they move across the screen using the mouse. This project serves as an introduction to **graphical programming with CSFML** and emphasizes **event handling, animations, and real-time user interactions**.

The project also focuses on optimizing performance by managing animations and movements with **timing functions** to ensure smooth gameplay.

## Features
The **My Hunter** game includes the following functionalities:

- **Interactive Gameplay**: The player can click on moving ducks to shoot them.
- **Animated Sprites**: Ducks are rendered using sprite sheets for fluid animation.
- **Mouse Input Handling**: The program processes mouse events for shooting mechanics.
- **Window Management**: A game window is created, and events are managed properly.
- **Performance Optimization**: Animations are controlled using `sfClock` to avoid frame rate dependency.
- **Command Line Option**: Running the game with `-h` displays usage information.

## Installation
To compile and run the project, follow the directory structure and commands below:

### Folder Structure
```
/include/
  ├── my.h              # Header file containing function declarations and constants
/src/
  ├── my_hunter.c            # Entry point of the program
  ├── sprite.c         # Functions to manage animated sprites
  ├── event.c           # Functions for handling user inputs
  ├── menu.c           # Functions for handling the start menu
  ├── move_duck.c           # Functions for handling sprite movement
  ├── window.c           # Functions for handling the window
/image/                # Contains sprites, sounds, and other game resources
/ogg/                  # Contains game music
Makefile                # Compilation rules
README.md               # This file
```

### Compilation
Clone the repository:
```sh
git clone https://github.com/jawedlahrouri/My_hunter-Epitech.git
cd my_hunter
```
Compile the project:
```sh
make
```
Run the game:
```sh
./my_hunter
```
Display help message:
```sh
./my_hunter -h
```

## Example Gameplay
- **Game Start**: Ducks appear and move across the screen.
- **Player Shoots**: Clicking on a duck removes it from the screen.

## Technical Details
The game is built using **CSFML** for graphics and event handling. The game logic ensures smooth sprite movement, responsive shooting mechanics, and an intuitive user interface.

### Key Functions
- `main()`: Sets up the window, sprites, and game variables.
- `handle_event()`: Processes mouse clicks and other user inputs.
- `animate_sprite()`: Animates the ducks
-  `move_duck()`: updates ducks positions.
- `game_loop()`: Handle all the game loop.

## Contributors
This project was developed as part of an **EPITECH programming exercise**.
