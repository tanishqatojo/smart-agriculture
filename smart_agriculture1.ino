const int soilMoisturePin = A0;
const int tempSensorPin = A1;
const int pumpPin = 8;
void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); 
}
void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);
  int temperatureValue = analogRead(tempSensorPin);
  float tempC = temperatureValue * (5.0 / 1023.0) * 100.0;
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoistureValue);
  Serial.print(" | Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");
  if (soilMoistureValue < 600) {
    digitalWrite(pumpPin, HIGH);
  } else {
    digitalWrite(pumpPin, LOW);
  }
  delay(1000);
}
