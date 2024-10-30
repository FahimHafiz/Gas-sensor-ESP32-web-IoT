# Gas Sensor Data Logging with ESP32 and XAMPP

## Overview
This repository demonstrates how to read data from an MQ-2 gas sensor using an ESP32 microcontroller, convert the analog readings to an approximate PPM (parts per million) value, and store the data in a local database using XAMPP. This project serves as an introduction to IoT-based gas monitoring systems, bridging hardware and software integration.

### Repository Sections
1. **[Sensor Data Acquisition](docs/how_to_read_sensor_data.md)** - Instructions on reading analog data from the MQ-2 gas sensor, converting it to PPM, and connecting the hardware.
2. **[XAMPP Introduction](docs/xampp_intro.md)** - Overview of XAMPP for local database management.
3. **[Database Integration](docs/database_integration.md)** - Step-by-step guide for setting up a database in XAMPP, writing a PHP script to insert data, and connecting the ESP32 to the database.

### Directory Structure
- **Code**: 
  - [ESP32 Arduino Code](code/esp32code-arduino-ide) - Code to read sensor data and send it to the database.
  - [PHP Script](code/php_code) - Code for inserting sensor data into the XAMPP database.
- **Images**: 
  - [Circuit Diagram](images/circuit_img) - MQ-2 sensor and ESP32 circuit connection.
  - [PPM Calculation Process](images/ppm_reading) - Visuals for reading and converting PPM data.
  - [Web Interface](images/web_img) - Screenshots of database setup and XAMPP configuration.

## Getting Started
To get started, follow the instructions in each of the three sections below. Each section contains relevant images and code to help you set up the ESP32, configure XAMPP, and integrate the database.

---

### 1. Sensor Data Acquisition
Detailed instructions on reading analog data from the MQ-2 gas sensor using the ESP32, converting it to PPM, and wiring the circuit. See [how_to_read_sensor_data.md](docs/how_to_read_sensor_data.md) for details.


### 2. XAMPP Introduction
A short introduction to XAMPP, including an explanation of its components and their use in this project. For more information, see [xampp_intro.md](docs/xampp_intro.md).

### 3. Database Integration
Step-by-step instructions for setting up the XAMPP database, writing a PHP script to store data, and linking the ESP32 code to the PHP script. See [database_integration.md](docs/database_integration.md) for the complete guide.

---

## Code Files
- **ESP32 Arduino Code for only PPM Calculation**: [esp32_gas_sensor.ino](code/esp32code-arduino-ide/esp32_gas_sensor.ino) - Reads MQ-2 sensor data, converts it to PPM.
- **ESP32 Arduino Code for displaying the PPM data to local database**: [esp32_gas_sensor_db.ino](code/esp32code-arduino-ide/esp32_gas_sensor_db.ino) - Reads MQ-2 sensor data, converts it to PPM, and sends it to the PHP script for database update.
- **PHP Script**: [gas_sensor_php.php](code/php_code/gas_sensor_php.php) - Receives sensor data and inserts it into the XAMPP database.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For questions or suggestions, please open an issue in this repository.


---

