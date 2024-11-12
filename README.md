# Bup the Catboy (Wii Port)

A Mario-like 2D platformer game written in C with SDL.   
Ported to Nintendo Wii by KoopTheKoopa.

## Source Tree

```
include       - Headers for various libraries
lib
  lunarengine - A custom 2D platformer engine built for this game
  bupscript   - Source code for the BupScript language
                interpreter used for modding
src
  io          - Input and output
    assets    - Reading & parsing assets
    audio     - Audio engine
  font        - Text/font renderer
  game        - Core game source code
    data      - Game data (tile, tileset and entity metadata)
    entities  - Entity interaction and update code
    network   - Server, client and packet handing for online multiplayer
    overlay   - HUD, title screen
    tiles     - Tile interaction
tools         - Programs used during compilation
  assetgen    - Generates an asset archive from the "assets"
                directory that gets embedded into the
                game's executable
```

## Building

You must install devkitpro first. You can follow on how to [here](https://devkitpro.org/wiki/Getting_Started).   

### Windows

1. Launch the **MSys2** shell that is bundled in devkitpro
   (should be either in your start menu or `<devkitpro directory>/msys2/msys2.exe`)
2. Install dependencies
```sh
pacman -S git make base-devel gcc wii-dev wii-sdl2 ppc-libpng
```
3. Follow the [General compile steps](#general-compile-steps)

### Linux

1. Install dependencies

**Debian**
```sh
sudo dkp-pacman -S git make gcc wii-dev wii-sdl2 ppc-libpng
```
**Arch**
```sh
sudo pacman -S git make gcc wii-dev wii-sdl2 ppc-libpng
```
2. Follow the [General compile steps](#general-compile-steps)

### General compile steps

1. Clone the repository
```sh
git clone --recursive https://github.com/koopthekoopa/bup-the-wiiboy && cd bup-the-wiiboy
```
2. [Acquire assets](#acquiring-assets)*
3. Compile the game using the `make -j$(nproc)` command
4. The executable should be located at `build/btcb.dol`

*Assets aren't required for the game to compile, but it won't be able to run correctly as level, texture and sound data is missing. 

## Acquiring assets

This game isn't published yet so assets are impossible to get for now.
