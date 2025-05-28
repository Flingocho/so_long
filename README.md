# 🎮 so_long - Lets play!

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-success" alt="Status">
  <img src="https://img.shields.io/badge/42-School-brightgreen" alt="42">
  <br><br>
</div>

<details open>
<summary><b>🚀 Overview</b></summary>

The **so_long** project involves creating a simple 2D game where the player navigates through a map, collecting items and reaching the exit while avoiding enemies. This project introduces concepts like game development, graphics handling with the MiniLibX library, event management, and basic game mechanics.

The game supports maps with walls, collectables, a player character, enemies, and an exit. The player must collect all items before being able to exit the level.
</details>

<details>
<summary><b>✨ Features</b></summary>

- 🎮 Simple and intuitive controls (W, A, S, D keys)
- 🗺️ Custom map loading from .ber files
- 🔢 Move counter display
- 🪙 Collectable items that must be gathered
- 🚪 Exit that becomes accessible after collecting all items
- 👾 Optional enemies that end the game on contact
- 🎭 Smooth animation and graphical rendering
- 🧠 Path validation using flood fill algorithm
</details>

<details>
<summary><b>📊 Game Elements</b></summary>

| Element     | Symbol | Description                                  |
|-------------|:------:|----------------------------------------------|
| Player      |   P    | The character controlled by the player       |
| Wall        |   1    | Obstacle that cannot be passed through       |
| Empty space |   0    | Area where the player can move freely        |
| Collectable |   C    | Items that must be collected                 |
| Exit        |   E    | Level exit, active after collecting all items|
| Enemy       |   K    | Optional enemy that ends the game on contact |

</details>

<details>
<summary><b>🛠️ Function Overview</b></summary>

<details>
<summary><b>🔑 Main Functions</b></summary>

| Function | Description |
|----------|-------------|
| `main` | Entry point of the game, handles initialization |
| `key_hook` | Manages keyboard input and player actions |
| `init_process` | Initializes MiniLibX and game resources |
| `render_window` | Renders the game elements to the window |

</details>

<details>
<summary><b>⚙️ Helper Functions</b></summary>

| Function | Description |
|----------|-------------|
| `check_map` | Validates the game map structure |
| `set_matrix` | Sets up the 2D map from the file |
| `flood_fill` | Validates that the map is solvable |
| `init_sprites` | Initializes all game sprites |
| `free_resources` | Cleans up allocated memory |

</details>
</details>

<details>
<summary><b>🛠️ Installation</b></summary>

```bash
# Clone the repository
git clone https://github.com/Flingocho/so_long.git

# Navigate to the directory
cd so_long

# Build the game
make

# Run the game with a map
./so_long maps/map.ber
```

### Project Structure

The project follows a modern directory structure:

```
so_long/
├── include/                 # Header files directory
│   ├── so_long.h            # Main header with function prototypes
│   ├── libft.h              # Libft library header
│   ├── ft_printf.h          # Printf library header
│   └── mlx.h                # MiniLibX library header
├── src/                     # Source files directory
│   ├── so_long.c            # Main program implementation
│   ├── controls_manager.c   # Key input handling
│   ├── map_check.c          # Map validation functions
│   ├── render_window.c      # Graphics rendering
│   └── ...                  # Other source files
├── dependencies/            # External libraries
│   ├── libft/               # Custom C standard library functions
│   ├── ft_printf/           # Custom printf implementation
│   └── minilibx-linux/      # Graphics library
├── maps/                    # Game maps
│   └── map.ber              # Example map
├── textures/                # Game assets
│   ├── player.xpm           # Player sprite
│   ├── wall.xpm             # Wall sprite
│   └── ...                  # Other game sprites
└── Makefile                 # Build automation
```

</details>

<details>
<summary><b>🎮 Controls</b></summary>

| Key | Action |
|-----|--------|
| W   | Move Up |
| A   | Move Left |
| S   | Move Down |
| D   | Move Right |
| ESC | Exit Game |

</details>

<details>
<summary><b>🗺️ Map Format</b></summary>

Maps are defined in `.ber` files with the following conventions:
- `1`: Wall
- `0`: Empty space
- `P`: Player starting position (only one allowed)
- `E`: Exit (only one allowed)
- `C`: Collectable (at least one required)
- `K`: Enemy (optional)

Example map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

The map must be rectangular, enclosed by walls, and should contain at least one collectible, exactly one starting position, and exactly one exit.
</details>

<details>
<summary><b>🔧 Dependencies</b></summary>

- **libft**: Custom implementation of C standard library functions
- **ft_printf**: Custom implementation of printf function
- **minilibx-linux**: Simple X-Window graphics API

All dependencies are included in the project and are compiled automatically through the Makefile.
</details>

<details>
<summary><b>🌟 Key Learning Outcomes</b></summary>

- 🎯 **Game Development Fundamentals**: Core principles of game loops, state management, and player interaction
- 🖥️ **Low-level Graphics Programming**: Hands-on experience with direct pixel manipulation and frame rendering using MiniLibX
- 🧩 **Algorithm Implementation**: Applied the flood fill algorithm to validate map solvability and path finding
- 🔍 **Memory Management**: Implemented efficient memory allocation/deallocation strategies for game resources
- 🧠 **Event-driven Programming**: Handling user input and managing event hooks in real-time applications
- 🚀 **Performance Optimization**: Maintain smooth gameplay in a resource-constrained environment
- 🔧 **Project Architecture**: Well-structured codebase with clear separation of concerns and modular design
</details>

<details>
<summary><b>📜 License</b></summary>

This project is part of the 42 School curriculum and is provided under the [MIT License](LICENSE).
</details>

---

<div align="center">
  Created with ❤️ by <a href="https://github.com/Flingocho">Flingocho</a>
</div>