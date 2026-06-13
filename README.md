# 🚗 Autonomous Car Lane Detection Simulator

A C++ simulation of an autonomous vehicle navigating a multi-lane road. The car automatically detects obstacles ahead, changes lanes when necessary, and attempts to reach its destination safely.

## 📌 Features

* Multi-lane road simulation
* Obstacle detection system
* Automatic lane changing
* Collision avoidance logic
* Real-time console visualization
* Cross-platform support (Windows/Linux)

## 🛠️ Technologies Used

* C++
* STL (Vector)
* Thread Library
* Chrono Library

## 📂 Project Structure

```
Autonomous-Car-Simulator/
│
├── main.cpp
├── README.md
└── .gitignore
```

## ▶️ How to Run

### Compile

Using g++:

```bash
g++ main.cpp -o simulator -std=c++11
```

### Execute

Windows:

```bash
simulator.exe
```

Linux/macOS:

```bash
./simulator
```

## 🎮 Simulation Overview

* The vehicle starts at the beginning of the road.
* Obstacles are placed at predefined positions.
* The car continuously checks for obstacles ahead.
* When an obstacle is detected, the car attempts to switch to a safe lane.
* If no safe lane is available, the simulation stops with a collision message.
* If the car reaches the end successfully, the simulation is completed.

## 🚀 Future Improvements

* Random obstacle generation
* Traffic signal simulation
* Multiple autonomous vehicles
* Sensor-based decision making
* Path planning algorithms
* Graphical User Interface (GUI)
* AI-based obstacle avoidance

## 📸 Sample Output

```
.............|............|.............
.............|......X.....|.............
C............|............|.............
.............|............|.............
```

## 👨‍💻 Author

Vidyanand Mahto

## 📜 License

This project is licensed under the MIT License.
