# space
Game made in MAC0211 in colaboration with Mathias Van Sluys Menck, and Rodrigo Zanette Magalhães

## Installation
Just download the souce code and run

```
make
```

and it will create the binary file `space`. To run the game, excecute this file in a terminal.

## Commands
### For player 1:
| Command  | Action |
| ------------- | ------------- |
| Up arrow | Accelerate  |
| Down arrow | Shot  |
| Left arrow | Turn anticlockwise  |
| Right arrow | Turn clockwise  |
### For player 2:
| Command  | Action |
| ------------- | ------------- |
| W | Accelerate  |
| S | Shot  |
| A | Turn anticlockwise  |
| D | Turn clockwise  |

## Customizing the game
You can create new levels or spaceships or edit the ones that exists by editing the files in the `resource` directory.

The syntax for levels files is:
```
[Planet diameter] [Planet mass]
[Player 1 X position] [Player 1 Y position] [Player 1 X velocity] [Player 1 Y velocity]
[Player 2 X position] [Player 2 Y position] [Player 2 X velocity] [Player 2 Y velocity]
[Window width] [Window height]
```

And the syntax for spaceships files is:
```
[Mass] [Shot cooldown] [Rotation cooldown] [Total HP] [Diameter] [Speed]
```

