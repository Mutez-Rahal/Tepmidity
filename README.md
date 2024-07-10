# Tepmidity
This project prints the data received from the temperature and humidity sensor to the database with the help of Google Firebase.
## Technologies Used
- **DHT11 Sensor:** For measuring temperature and humidity.
- **NodeMCU (ESP8266):** For connecting to Wi-Fi and sending data to Firebase.
- **Google Firebase:** For storing and visualizing the sensor data.

## Installation

Follow these steps to set up the project:

1. **Clone the repository:**
    ```bash
    git clone https://github.com/Mutez-Rahal/Tepmidity.git
    cd Tepmidity
    ```

2. **Set up the hardware:**
    - Connect the DHT11 sensor to the NodeMCU.
    - DHT11 Pin Configuration:
      - VCC to 3.3V
      - GND to GND
      - Data Pin to D4 (or any GPIO pin you prefer)

3. **Configure Firebase:**
    - Set up a new Firebase project at [Firebase Console](https://console.firebase.google.com/).
    - Get your Firebase Realtime Database URL and authentication details.

4. **Configure the NodeMCU:**
    - Install the Arduino IDE.
    - Install the necessary libraries (DHT sensor library, FirebaseESP8266 library).
    - Open the provided `.ino` file in Arduino IDE.
    - Enter your Wi-Fi credentials and Firebase details in the code.
    - Upload the code to your NodeMCU.

## Usage

Once the setup is complete:

1. Power on the NodeMCU.
2. The NodeMCU will start sending temperature and humidity data from the DHT11 sensor to Firebase.
3. You can view the real-time data in your Firebase Realtime Database.

<h2>🖼️ Circuit Photo</h2>

![image](https://github.com/Mutez-Rahal/Tepmidity/assets/138363266/256500fb-6283-4a14-a0f5-29fc5daefafb)
