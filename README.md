# 🚀 GUI - SFML C++ Practice Project

A lightweight, interactive 2D playground built from scratch using **C++** and the **SFML (Simple and Fast Multimedia Library)**. This project serves as a practical sandbox for mastering game loops, real-time input handling, sound management, and basic state transformations.

> *"What's up, here in this code I'm just practicing SFML, or you can say 'learning SFML' *_* and this code does not represent anything serious, so you can move the ball, shoot, reload, and you can use the turbo!.... wow a turbo (shut up). Have not fun :); kidding, I hope you like the bunch of code!"*

---

## ✨ Features

- **🎮 Real-Time Movement & Turbo**: Smooth directional movement using `WASD` keys, paired with a Turbo modifier (`Left Control`) for double speed.
- **🔊 Smart Sound Pooling**: Implements an optimized memory-safe audio pool (`std::vector<std::unique_ptr<sf::Sound>>`) to handle multiple rapid gunfire sound effects without overlapping crashes or memory leaks.
- **🔫 Ammo & Reload Mechanics**: Dynamic ammo counter system with firing cooldowns and an interactive reload feature (`R` key).
- **🎨 Visual Feedback (Hovering/Firing Effects)**: Real-time color transition effects on the target shape when firing.
- **⏱️ Frame Rate & Delta Time Control**: Fixed framerate limit (60 FPS) with delta time calculations for consistent movement speed across frames.

---

## 🛠️ Technologies Used

- **Language**: C++
- **Graphics & Audio**: SFML (Simple and Fast Multimedia Library)
- **Standard Library**: `<memory>`, `<vector>`, `<sstream>`, `<chrono>`

---

## 🕹️ Controls

| Key / Input | Action |
| :--- | :--- |
| **W, A, S, D** | Move the ball up, left, down, and right |
| **Left Control** | Turbo Mode (Hold while moving) |
| **Left Mouse Click** | Shoot (Consumes ammo & plays sound from pool) |
| **R** | Reload ammunition |
| **ESC / Close** | Exit window |

---

## 📂 Code Architecture Preview

The core game loop handles inputs, sound status checks, and rendering efficiently within a single-window context:

```cpp
while (window.isOpen()) {
    // Event handling
    // Input processing (WASD + Turbo)
    // Sound pool management & Shooting logic
    // Rendering window and updating UI text
}
