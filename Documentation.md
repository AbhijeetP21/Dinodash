# **Dinodash**
Dinodash is a visually engaging 2D side-scrolling survival game where players control **Glino the Dino**, dodging obstacles, collecting power-ups, and unlocking achievements. Developed in **C++** using the **Raylib** library, the game provides immersive graphics, dynamic gameplay, and a seamless experience.

---

## **Game Features**

1. **Dynamic Gameplay**  
   - Players can jump, duck, and use shields to avoid obstacles and survive longer.  
   - Obstacles include **axes (Laeva)** falling toward Glino.  

2. **Power-Ups**  
   - **Watermelon**: Collect for bonus points.  
   - **Shield**: Provides temporary invincibility.  

3. **Visual Enhancements**  
   - Parallax scrolling for background elements like mountains, trees, and clouds.  
   - **Day/Night Cycle**: Alternates between daytime (with sun) and night (with a moon and starry sky).  

4. **Achievements**  
   - "First 50 Points"  
   - "Scored 100 Points"  
   - "Survived 5 Minutes"  

5. **Sounds and Music**  
   - Background music and sound effects for jumps, collisions, and item pickups.  

---

## **Controls**
- **Space**: Jump over obstacles.  
- **S**: Duck under obstacles.  
- **Q**: Turn off background music.  
- **E**: Turn on background music.  
- **Enter**: Start or restart the game.

---

## **Game Elements**

### **1. Background Layers**
- **Distant Mountains**: Moves slower for depth perception.  
- **Clouds**: Multiple cloud layers appear at staggered positions and speeds.  
- **Sun and Moon**: Appear alternately during day-night transitions.  

### **2. Obstacles**
- **Laeva (Axes)**: Fall toward the Dino. Colliding with these ends the game unless the shield is active.  

### **3. Power-Ups**
- **Watermelon**: Collect to gain points.  
- **Shield**: Grants invincibility for a short duration.  

### **4. Scoring**
- The player earns points as time progresses and receives additional points by collecting watermelons.  

---

## **Code Overview**

The core game loop and mechanics are implemented using Raylib and structured as follows:

### **1. Initialization**
- Game window, assets (textures, sounds), and game variables are initialized.  
- **Assets** include textures for the Dino, mountains, clouds, trees, axes, watermelons, shields, and background (day/night).  

### **2. Game Logic**
- **Day-Night Cycle**: Managed using a timer (`cycleDuration`) to toggle between day and night. The **moon** and **sun** move across the screen during their respective phases.  
- **Player Movement**: Glino jumps with physics-based gravity and ducks when "S" is pressed.  
- **Collision Detection**: Checks for collisions with obstacles and items using `CheckCollisionRecs`.  
- **Achievements**: Unlockable achievements displayed based on the player's progress.  

### **3. Rendering**
- Background elements, foreground elements, power-ups, and the Dino are drawn in each frame using **Raylib's rendering functions**.  
- The parallax effect is achieved by moving background layers at different speeds.  

### **4. Sound Management**
- Jump, collision, and pickup sounds are triggered using `PlaySound()`.  
- Background music streams continuously with control options.  

---

## **File Structure**
```
Dinodash/
│-- Dinodash.cpp        # Main game code
│-- assets/
    ├── Sounds/
    │   ├── jump.wav
    │   ├── pickupCoin.wav
    │   ├── hitHurt.wav
    │   └── Pixel Kings.wav
    └── textures/
        ├── dino.png
        ├── mountain.png
        ├── distant_mountain.png
        ├── cloud.png
        ├── treesBack.png
        ├── treesFront.png
        ├── LAEVA.png
        ├── Yellow Watermelon2.png
        ├── shield.png
        ├── day.png
        ├── starrynight.png
        ├── sun.png
        └── moon.png
```

---

## **How to Build and Run**

### **Prerequisites**
1. **Raylib**: Install Raylib for your platform. Ensure it is linked during compilation.  
2. **C++ Compiler**: A modern C++ compiler (C++17 or later).  

### **Compilation**
To compile the game using **Clang**:
```bash
clang++ -std=c++17 Dinodash.cpp -o Dinodash \
    -I/usr/local/include -L/usr/local/lib -lraylib \
    -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

### **Run the Game**
After compilation:
```bash
./Dinodash
```

---

## **Challenges Faced**
1. **Parallax Scrolling**: Implementing the movement of multiple background layers at different speeds to create a depth effect.  
   - **Solution**: Adjusted positions of each layer dynamically based on `GetFrameTime()` for smoother rendering.  

2. **Day-Night Cycle**: Synchronizing the sun and moon movement with day-night transitions.  
   - **Solution**: Added a timer mechanism (`cycleDuration`) to toggle states and reset positions.  

3. **Collision Detection**: Managing precise collision detection between the Dino and moving objects.  
   - **Solution**: Used `CheckCollisionRecs` and adjusted padding around sprites for better accuracy.

4. **Resource Management**: Ensuring textures and sounds were loaded correctly and released after use.  
   - **Solution**: Verified file paths and added cleanup logic using `UnloadTexture` and `CloseWindow`.  

---

## **Future Enhancements**
1. **Leaderboards**: Add online/global leaderboards to track high scores.  
2. **More Power-Ups**: Introduce new abilities like speed boosts or slow-motion effects.  
3. **Levels**: Implement multiple levels with increasing difficulty.  
4. **Enhanced Graphics**: Improve animations and add more background details.  

---

## **Credits**
- **Developer**: Abhijeet Pachpute  
- **Library**: Raylib  
- **Assets**: Custom graphics, pngwing.com and free audio resources  

---
