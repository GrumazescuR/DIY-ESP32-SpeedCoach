# Initial GPS Test

## Objective

Verify that the ESP32 can receive and decode GPS data from the L76K GPS module.

## Hardware

- ESP32 Dev Module
- L76K GPS module
- Breadboard and jumper wires
- USB connection to PC

## Test Setup

The L76K GPS module was connected to the ESP32 using UART communication.

- GPS TX -> ESP32 GPIO 16
- GPS RX -> ESP32 GPIO 17
- Baud rate: 9600
- ESP32 Serial Monitor baud rate: 115200

## Test Procedure

1. Connected the GPS module to the ESP32.
2. Uploaded a GPS test sketch using the TinyGPSPlus library.
3. Checked that raw GPS data was being received.
4. Decoded the GPS data into readable values.
5. Walked around while monitoring the Serial Monitor.
6. Observed changes in speed and GPS position.
7. Used the GPS speed reading to calculate an estimated 500 m split time.

## Results

The GPS successfully communicated with the ESP32 and produced valid data.

The tests showed:

- Raw NMEA GPS data being received
- Satellite count
- GPS position data
- Speed in km/h
- Estimated 500 m split time

During the movement test, the GPS recorded a speed of approximately 1.81 km/h and calculated a 500 m split of approximately 16:31.

## Conclusion

The initial GPS test was successful.

The ESP32 and L76K GPS module can now be used as the basis for further SpeedCoach development.
