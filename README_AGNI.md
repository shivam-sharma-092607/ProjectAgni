# AGNI — Automated Ground-based Network for Ignition Detection

AGNI is a fire-detection prototype designed to identify early signs of fire using low-cost sensors and an Arduino-based node. The project focuses on detecting dangerous environmental conditions such as rising temperature and elevated gas/smoke levels, then triggering an immediate local alert.

## Project Overview

This project is built around a simple idea:

- **Sense** environmental changes using sensors
- **Detect** fire-like conditions using threshold checks
- **Alert** through a buzzer/LED
- **Extend** the system later into a long-range network using LoRa-based communication

The research document describes AGNI as a **ground-based early ignition detection network** intended for forest-fire monitoring, with sensor nodes, relay hubs, and a central control unit. The current code represents the **prototype stage** of that idea.

## Problem Statement

Forest fires spread quickly and are difficult to stop once they grow. Satellite, drone, and manual patrol methods are useful, but they often detect fires too late or depend on expensive infrastructure. AGNI aims to provide a **low-cost, local, and scalable early-warning system** that can detect danger at the ground level.

## Hardware Used

### Transmitter Node
- Arduino Uno
- DHT sensor (temperature and humidity)
- Gas sensor input on analog pin
- Buzzer
- LED

### Receiver Node
- Arduino Uno or compatible board
- Buzzer
- LED

## How the System Works

### 1) Sensor Node / Transmitter
The transmitter reads live environmental data from sensors. If the readings cross a fixed threshold, it assumes a fire risk and activates the local alarm.

### 2) Alert Generation
When danger is detected:
- the buzzer turns ON
- the LED turns ON
- a serial message is printed in the Arduino Serial Monitor

### 3) Receiver Node
The receiver script is written as a separate alert unit. In the current form, it continuously shows a fire-alert message and toggles its buzzer/LED to simulate a received warning.

## Code Execution Flow

### `transmitter.ino`
1. Initializes the Serial Monitor at 9600 baud.
2. Starts the DHT sensor.
3. Sets the buzzer and LED as output pins.
4. Continuously reads:
   - temperature
   - humidity
   - gas level from the analog pin
5. Compares the sensor values against thresholds.
6. If temperature or gas level is too high:
   - prints a fire warning
   - turns ON buzzer and LED
7. Otherwise:
   - prints that the environment is normal
   - keeps buzzer and LED OFF

### `receiver.ino`
1. Initializes the Serial Monitor at 9600 baud.
2. Configures the LED and buzzer pins as outputs.
3. Repeatedly prints a fire-alert message.
4. Turns ON the LED and buzzer for a short time.
5. Turns them OFF again and repeats.

## Important Note About the Current Code

The research document describes a **LoRa-based transmitter and hub network**, but the current Arduino code is still a **local wired prototype**. That means:

- the transmitter detects danger locally
- the receiver simulates an alert node
- there is **no actual wireless transmission logic yet** in the shown code

This is completely fine for a prototype. It just means the code currently demonstrates **detection and local alerting**, while the document describes the **full target architecture** for future development.

## Threshold Logic Used in the Prototype

In the transmitter code:
- fire risk is triggered if **temperature >= 50°C**
- or if **gas level >= 200** on the analog sensor reading

These values can be adjusted later based on real testing and calibration.

## Future Scope

The research document already suggests several future improvements:
- LoRa communication between sensor nodes and hubs
- solar-powered deployment
- better smoke/CO and temperature calibration
- fire-extinguisher integration
- smarter prediction and mapping of fire-prone regions

## Research Findings and Documentation

The uploaded project report contains a lot of valuable research material, including:
- motivation and problem context
- fire-prone region analysis
- comparison with existing detection methods
- system architecture
- components and prototype setup
- outcomes and future scope

For a strong GitHub presentation, the best approach is usually:

- keep the **README.md** short and project-focused
- put detailed research findings in a **separate report file** such as `docs/research-report.md`
- or convert the report into a **PDF** and link it from the README
- optionally add a `docs/` folder with diagrams, photos, and references

That makes the repository easier to read while still preserving the full research work.

## Suggested Repository Structure

```bash
AGNI/
├── transmitter.ino
├── receiver.ino
├── README.md
├── docs/
│   ├── research-report.md
│   ├── figures/
│   └── prototype-images/
└── assets/
```

## Conclusion

AGNI is a promising early fire-detection prototype built around affordable sensors and Arduino. The current implementation demonstrates the core idea of sensing and alerting, while the research document defines the larger vision of a scalable LoRa-based forest-fire warning network.
