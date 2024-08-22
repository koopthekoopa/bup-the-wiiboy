# Bup the Catboy

A Mario-like 2D platformer game written in C with SDL

## Source Tree

```
include       - Headers for various libraries
lib
  lunarengine - A custom 2D platformer engine built for this game
lvledit       - Source code for the level editor program
src
  assets      - Reading & parsing assets
  audio       - Audio engine
  font        - Text/font renderer
  game        - Core game source code
    data      - Game data (tile, tileset and entity metadata)
    entities  - Entity interaction and update code
    network   - Server, client and packet handing for online multiplayer
    tiles     - Tile interaction
tools         - Programs used during compilation
  assetgen    - Generates an asset archive from the "assets"
                directory that gets embedded into the
                games executable
```

## Building

### Windows

1. Install the [MSYS2 Toolchain](https://msys2.org)
2. Launch the **MINGW64** shell
3. Install dependencies
```
pacman -S git make mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-libgme
```
4. Follow the [General compile steps](#general-compile-steps)

### Linux

1. Install dependencies

**Debian**
```
sudo apt install git make gcc libsdl2-dev libgme-dev
```
**Arch**
```
sudo pacman -S git make gcc sdl2 libgme
```
2. Follow the [General compile steps](#general-compile-steps)

### Cross compiling for Windows on Linux

1. Setup `quasi-msys2` on your distro using the following command:
```
curl https://raw.githubusercontent.com/Dominicentek/BupTheCatboy/main/quasi-msys2-setup.sh | sh
```
2. After that, run `~/quasi-msys2/env/shell.sh`
3. Install dependencies
```
pacmake install _gcc _SDL2 _libgme
```
4. Follow the [General compile steps](#general-compile-steps)

### General compile steps

1. Clone the repository
```
git clone https://github.com/Dominicentek/BupTheCatboy && cd BupTheCatboy
```
2. [Acquire assets](#acquiring-assets)
3. Compile the game using the `make -j$(nproc)` command
4. The executable should be located at `build/btcb`

## Acquiring assets

This game isn't published yet so assets are impossible to get for now.