#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  delay(1500);

  Serial.println("Let's start!");
}

void loop() {
  delay(30000);
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity = dht.readHumidity();
  delay(500);
  // Read temperature as Celsius
  float temperature = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    String humidityString = "Humidity: " + String(humidity) + "%";
    String temperatureString = "Temperature: " + String(temperature) + "ºC";
    Serial.println(humidityString); 
    Serial.println(temperatureString);
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Humidity: "); 
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(temperature);
  Serial.print(" *C ");
}
