# Arkanoid (FreeGLUT)

A video game based off Arkanoid (popular retro block breaking game) built in C++ using FreeGLUT (an alternative to the OpenGL Utility Toolkit library).

## Structure

- include: Public headers
- src: Implementation files and entry point
- CMakeLists.txt: Build configuration

## Game Features (Planned)

- Paddle and ball movement
- Brick layout and destruction
- Basic collision detection
- Score and lives
- Level reset / progression

## Build (CMake)

1. Install FreeGLUT and OpenGL development libraries.
2. Generate build files:
   - `cmake -S . -B build`
3. Build:
   - `cmake --build build`
4. Run:
   - `./build/arkanoid` (or `build\\arkanoid.exe` on Windows)

## Notes

- Linker settings for FreeGLUT/OpenGL may be platform-specific, update CMakeLists.txt if not on Windows.
- Update the library names in CMakeLists.txt to match your toolchain.
