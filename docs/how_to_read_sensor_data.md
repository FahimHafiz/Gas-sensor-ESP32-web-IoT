# How to Read Data from MQ-2 Gas Sensor with ESP32

## Overview
This section describes how to read analog data from the MQ-2 gas sensor using the ESP32 and convert the readings to an approximate PPM (parts per million) value.

### Hardware Required
- **ESP32 Microcontroller**
- **MQ-2 Gas Sensor**
- **Connecting Wires**

### Circuit Diagram
![Circuit Diagram](../images/circuit_diagram.png)

### Step 1: Connecting the Sensor
- Connect the **analog output (A0)** of the MQ-2 sensor to an analog pin on the ESP32 (e.g., GPIO34).
- Connect **VCC** to 5V (or 3.3V depending on your sensor specifications).
- Connect **GND** to the ground pin of the ESP32.

### Step 2: Reading Analog Data
Using the Arduino IDE, write code to read analog data from the sensor. Refer to the ESP32 code in [code/ESP32_MQ2.ino](../code/ESP32_MQ2.ino).

### Step 3: Converting to PPM
The MQ-2 sensor provides raw analog data, which can be converted to an approximate PPM value based on calibration factors. This is done using a simple calculation within the ESP32 code.
