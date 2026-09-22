# 🅿️ Smart Parking Module

A smart parking solution built with ultrasonic sensors and microcontroller-based processing. Designed to monitor multiple parking slots in real time and provide accurate occupancy detection to improve space utilization.

## Features
- Real-time occupancy detection using ultrasonic sensors (HC-SR04)
- Scalable design to support 20+ parking slots
- Serial-based live status logging (slot-by-slot + total occupancy)
- Modular sensor-reading function for easy hardware scaling

## Hardware Used
- Arduino Uno / Mega (Mega recommended for 20+ slots)
- HC-SR04 Ultrasonic Sensors (one per slot)
- Jumper wires, breadboard/PCB
- (Optional) I2C GPIO expanders or multiplexers for large-scale deployment

## Circuit Connections (per slot)
| Component      | Arduino Pin (example) |
|-----------------|------------------------|
| Trig Pin        | Digital Output         |
| Echo Pin        | Digital Input          |

> See `trigPins[]` and `echoPins[]` arrays in code to configure per-slot wiring.

## How It Works
1. Each ultrasonic sensor measures distance to detect if a vehicle is present in its slot.
2. If distance falls below a set threshold, the slot is marked "Occupied."
3. The system cycles through all sensors, logging real-time occupancy status via Serial Monitor.
4. Total occupied/free slot counts are calculated each cycle.

## Getting Started
1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Wire ultrasonic sensors per the pin configuration in code.
3. Upload `smart_parking.ino` to your board.
4. Open Serial Monitor (9600 baud) to view live occupancy data.

## Scaling to 20+ Slots
For deployments beyond a handful of slots, consider:
- Using an Arduino Mega for additional digital pins
- I2C GPIO expanders (e.g., MCP23017)
- Distributed microcontrollers per zone reporting over a shared bus

## Future Improvements
- Add a display (LCD/OLED) showing available slots at entry
- Push occupancy data to a cloud dashboard or mobile app
- Add LED indicators per slot (red/green)

## License
MIT
