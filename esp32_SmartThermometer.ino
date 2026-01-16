#define BLYNK_TEMPLATE_ID "****************"
#define BLYNK_TEMPLATE_NAME "SmartThermometer"
#define BLYNK_AUTH_TOKEN "*****************"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

//network
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "*************";     
char pass[] = "*********";

// Hardware Pin Definitions
#define DHTPIN 4           // DHT11 Data Pin connected to GPIO 4
#define DHTTYPE DHT11      // Sensor type
#define RED_LED_PIN 19     // Indicator for high humidity
#define BLUE_LED_PIN 18    // Indicator for normal humidity

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

int humidityThreshold = 50; 

// This function is called every time the Slider widget in the Blynk app (V2) is moved
BLYNK_WRITE(V2) {
  humidityThreshold = param.asInt(); // Assign slider value to threshold variable
  Serial.print("New Humidity Threshold Set via App: %");
  Serial.println(humidityThreshold);
}


void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  Blynk.virtualWrite(V0, t); // V0 for Temperature
  Blynk.virtualWrite(V1, h); // V1 for Humidity

  // LED Logic based on humidity threshold
  if(h >= humidityThreshold){
    digitalWrite(RED_LED_PIN, HIGH);  // Turn on Red LED
    digitalWrite(BLUE_LED_PIN, LOW);   // Turn off Blue LED
  } else {
    digitalWrite(RED_LED_PIN, LOW);   // Turn off Red LED
    digitalWrite(BLUE_LED_PIN, HIGH);  // Turn on Blue LED
  }


  Serial.print("Humidity: "); Serial.print(h); Serial.print("%");
  Serial.print(" | Temp: "); Serial.print(t); Serial.print("°C");
  Serial.print(" | Threshold: "); Serial.print(humidityThreshold); Serial.println("%");
}

void setup() {
  Serial.begin(115200);
  

  Blynk.begin(auth, ssid, pass);
  
  dht.begin();
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run(); 
  timer.run(); 
}