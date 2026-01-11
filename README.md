# ❤️ Heart-Shaped LED Turn Signals (Arduino Prototype)

## Project Overview

This project was created as the **final project for my Computer Architecture course**. Rather than building something purely theoretical, I wanted to design a project I would *actually use*. As someone who enjoys **car modifications** and embedded systems, I decided to prototype a custom set of **heart-shaped LED turn signals**.

This repository contains the **Arduino-based proof-of-concept prototype**, built on a breadboard. The long-term goal is to redesign this project into a **permanent, automotive-safe installation** that can be added to my vehicle.

---

## What This Project Does

* Implements **custom heart-shaped LED turn signals** using discrete LEDs
* Supports **left and right turn signal animations**
* Uses a **trailing / sequential LED effect** to indicate turn direction

  * Left turn: LEDs animate in one direction
  * Right turn: LEDs animate in the opposite direction
* Designed as a **modular prototype** to experiment with animation logic and power constraints

> ⚠️ This version is a prototype intended for development and testing only.

---

## Hardware Used (Prototype)

* **Microcontroller:** Arduino Uno
* **LEDs:** 5mm discrete LEDs (≈84 total)
* **Resistors:** 100Ω resistors (one per LED)
* **Construction:** Solderless breadboards and jumper wires
* **Power:** Arduino 5V rail (prototype only)

Images of the full breadboard layout and LED clusters are included below.

---

## Software

* **Platform:** Arduino
* **Language:** C / C++ (Arduino framework)
* **Libraries:** Arduino core libraries only

### High-Level Code Behavior

At a high level, the code:

1. Reads simulated turn signal inputs
2. Maps each input to a specific LED group
3. Animates LEDs using timed, sequential activation
4. Ensures LEDs turn off cleanly between animation cycles

The animation logic was iteratively tuned by testing directly on the breadboard.

---

## Challenges & Key Learnings

### Power Constraints

The biggest technical challenge was managing **power limitations**. Running ~84 discrete LEDs directly from an Arduino introduced:

* Current limitations
* Brightness inconsistency
* Awareness of why automotive systems require proper power regulation

This project reinforced the importance of:

* Power budgeting
* Current limiting per LED
* Planning for external power and drivers in real-world embedded systems

### Embedded + Creative Design

This project sits at the intersection of:

* Embedded systems
* Hardware design
* Creative, aesthetic-driven engineering

It strengthened my confidence in taking **non-traditional ideas** and translating them into working hardware.

---

## Project Status

* ✅ Proof-of-concept complete
* 🔧 Breadboard prototype only
* 🚗 Not yet installed in a vehicle

Future iterations will include:

* Automotive-safe power regulation
* PCB design
* Weatherproof housing
* Direct integration with vehicle turn signal circuitry

---

## Media

### Full Breadboard Layout

![Full Breadboard Layout](FullBreadBoardLayout.jpeg)

### Left Side Close-Up

![Left Close-Up](LeftCloseUp.jpg)

### Right Side Close-Up

![Right Close-Up](RightCloseUp.jpg)

---

## Why This Project Matters

Although this was a **school assignment**, it reflects my broader interests in:

* Embedded systems
* Hardware-software integration
* Creative engineering projects

This project demonstrates my ability to:

* Design and prototype real hardware
* Debug power and timing issues
* Apply classroom concepts to practical, personal projects

---

## License

This project is shared for **educational and reference purposes**. Feel free to explore, learn from, or adapt the ideas for your own projects.
