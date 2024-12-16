# Dinodash
Dinodash is a fast-paced, action-packed dinosaur survival game where players must dodge obstacles, collect power-ups, and unlock achievements. Built with C++ and Raylib, it features immersive gameplay, visuals, and exciting challenges.


#Pre-requisites:
1. Latest C++ (preferbly 15+): Code uses modern C++ style, thus some game feature need recent verions of C++ to function properly.
2. raylib : Importatnt library. You can follow below instructions to ensure raylib is functioning properly.

 Check if you have proper raylib installation: 
 1. Check raylib version:
 "pkg-config --modversion raylib" 
  If installed correctly, it will return the installed version number (e.g., 4.5.0).

 2. Check raylib include path:
    "pkg-config --cflags raylib"
    This should output the include path for raylib (e.g., -I/opt/homebrew/include). You may need to use/update this path in the compile code.

 3. Check raylib library path:
    "pkg-config --libs raylib"
    This should output the linker flags and library path for raylib (e.g., -L/opt/homebrew/lib -lraylib). You may need to use/update this path in the compile code.


#Complie the Game:
I have added flags for OpenGL and System frameworks based on my local machine, it may or may not require on different machines.

"
clang++ -std=c++17 Dino_game.cpp -o Dinodash \
    -I/usr/local/include -L/usr/local/lib -lraylib \
    -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
"

#Run the game:
After compiling, "./Dino_game"

#Notes:
1. Ensure your system has the necessary frameworks for compiling, especially OpenGL and Cocoa, depending on your platform (macOS, Linux or Windows).
2. If you're on a different platform, you may need to adjust the compile flags accordingly.
3. If you run into any issues with raylib or the compilation, feel free to check the raylib documentation or GitHub repository for more details on installation and troubleshooting.
