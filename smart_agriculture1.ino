const int soilMoisturePin = A0;
const int tempSensorPin = A1;
const int pumpPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);  // Ensure the pump is off initially
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);
  int temperatureValue = analogRead(tempSensorPin);
  
  // Convert analog readings to actual values
  float tempC = temperatureValue * (5.0 / 1023.0) * 100.0;
  
  // Print values to Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoistureValue);
  Serial.print(" | Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  // Control the water pump based on soil moisture
  if (soilMoistureValue < 600) {  // Adjust the threshold as needed
    digitalWrite(pumpPin, HIGH);  // Turn on the pump (LED)
  } else {
    digitalWrite(pumpPin, LOW);   // Turn off the pump (LED)
  }

  delay(1000);  // Wait for a second before the next reading
}
