### **Dinodash**
**Dinodash** is a fast-paced, action-packed dinosaur survival game where players must dodge obstacles, collect power-ups, and unlock achievements. Built with **C++** and **Raylib**, it features immersive gameplay, stunning visuals, and exciting challenges.

---

### **Pre-requisites**

1. **C++ (preferably C++17 or later)**  
   Code uses modern C++ style, thus game some features need recent verions of C++ to function properly. so ensure you're using C++17 or later for compatibility.

2. **raylib**  
   **Raylib** is an essential library for rendering the game’s visuals. Follow the instructions below to verify that it is properly installed.

---

### **Check if raylib is Installed Correctly:**

1. **Check raylib version:**
   Run the following command in your terminal:
   ```bash
   pkg-config --modversion raylib
   ```
   If installed correctly, this should return the installed version number (e.g., `4.5.0`).

2. **Check raylib include path:**
   To verify the include path, run:
   ```bash
   pkg-config --cflags raylib
   ```
   This should output the include path for raylib (e.g., `-I/opt/homebrew/include`).

3. **Check raylib library path:**
   To verify the library path, run:
   ```bash
   pkg-config --libs raylib
   ```
   This should return the linker flags and library path for raylib (e.g., `-L/opt/homebrew/lib -lraylib`).

   You may need to update the paths in your compile command based on the output of these checks.

---

### **Compile the Game**

Once raylib is correctly installed, compile the game with the following command. This command assumes raylib is installed on `/usr/local`, but you may need to adjust paths based on your installation:
I have added flags for OpenGL and System frameworks based on my local machine, it may or may not require on different machines.

```bash
clang++ -std=c++17 Dinodash.cpp -o Dinodash \
    -I/usr/local/include -L/usr/local/lib -lraylib \
    -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

---

### **Run the Game:**

After compiling the game, run the following command to start playing:

```bash
./Dinodash
```

---

### **Notes:**

- Ensure your system has the necessary frameworks for compiling, especially OpenGL and Cocoa, depending on your platform (macOS, Linux, Windows).
- If you're on a different platform, you may need to adjust the compile flags accordingly.
- If you run into any issues with raylib or the compilation, feel free to check the raylib documentation or GitHub repository for more details on installation and troubleshooting.

---


