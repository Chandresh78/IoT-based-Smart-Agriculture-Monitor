# IoT Sensor Data Logging with ESP8266 and ThingSpeak

This project demonstrates how to use an ESP8266 microcontroller to read temperature, humidity, and soil moisture data from sensors and send the data to the ThingSpeak cloud platform for storage and visualization. The DHT11 sensor is used for temperature and humidity measurements, while an analog soil moisture sensor measures soil moisture levels.

## Hardware Requirements
- ESP8266 microcontroller (e.g., NodeMCU)
- DHT11 temperature and humidity sensor
- Analog soil moisture sensor
- Breadboard and jumper wires
- USB cable for programming and power

## Software Requirements
- Arduino IDE
- DHT sensor library
- ESP8266WiFi library
- ThingSpeak library

## Circuit Diagram
Connect the components as follows:

1. **DHT11 Sensor**
   - VCC to 3.3V
   - GND to GND
   - Data pin to D5

2. **Soil Moisture Sensor**
   - VCC to 3.3V
   - GND to GND
   - Analog output to A0

## Code Explanation
The code initializes the sensors and WiFi connection, reads data from the sensors, and sends the data to ThingSpeak at regular intervals.

### Libraries
```cpp
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
```

### Constants and Variables
- `DHTPIN` and `DHTTYPE`: Pin and type for the DHT11 sensor.
- `ssid` and `password`: WiFi credentials.
- `myChannelNumber` and `myWriteAPIKey`: ThingSpeak channel number and API key.
- `temperature`, `humidity`, `sensor_output`, `percent_water`, `state`: Variables for storing sensor data and managing state.

### Setup Function
- Initializes serial communication, DHT sensor, and WiFi connection.
- Connects to ThingSpeak.

### Loop Function
- Reads temperature and humidity from the DHT11 sensor.
- Reads soil moisture from the analog pin.
- Maps the soil moisture sensor output to a percentage value.
- Sends data to ThingSpeak, cycling through temperature, humidity, and soil moisture data fields.

## How to Use
1. **Setup the Hardware:**
   - Assemble the circuit as described in the circuit diagram.

2. **Install the Required Libraries:**
   - Open Arduino IDE.
   - Go to Sketch > Include Library > Manage Libraries.
   - Install the DHT sensor library, ESP8266WiFi library, and ThingSpeak library.

3. **Configure the Code:**
   - Replace `"Enter your Wifi name"` and `"Enter your Wifi password"` with your WiFi SSID and password.
   - Replace `myChannelNumber` and `myWriteAPIKey` with your ThingSpeak channel number and write API key.

4. **Upload the Code:**
   - Connect the ESP8266 to your computer using a USB cable.
   - Select the correct board and port from the Tools menu.
   - Click the Upload button.

5. **Monitor Data:**
   - Open the Serial Monitor to see the sensor readings and status messages.
   - Go to your ThingSpeak channel to view the data.

## Notes
- Ensure your ESP8266 and sensors are properly powered and connected.
- Adjust the `delay(30000);` in the `loop` function to change the data update interval (currently set to 30 seconds).
- The soil moisture sensor values may need calibration depending on your specific sensor and soil conditions.

## Troubleshooting
- If the ESP8266 fails to connect to WiFi, check the SSID and password.
- If sensor readings are incorrect, verify the connections and ensure the sensors are working.

## References
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
- [ESP8266WiFi Library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
- [ThingSpeak Library](https://github.com/mathworks/thingspeak-arduino)
