
const int sensorPin = A0;
float baselineTemp;

void setup() {
    Serial.begin(9600);
    baselineTemp = getTemp();
    // init led pins
    for (int pinNumber = 2 ; pinNumber < 5 ; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void loop() {
    float temperature = getTemp();

    if (temperature < baselineTemp) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp + 2 
        && temperature < baselineTemp + 4) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp + 4 
        && temperature < baselineTemp + 6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp + 6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }

    delay(1);
}

float getTemp() {
  // get analog value
    int sensorValue = analogRead(sensorPin);
    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);
    
    // get voltage
    float voltage = sensorValue / 1024.0 * 5.0;
    Serial.print(", Voltage: ");
    Serial.print(voltage);

    // get temperature in celsius. this expressions is written on the sensor's manual.
    float temperature = (voltage - 0.5) * 100;
    Serial.print(", degrees C: ");
    Serial.print(temperature);

    Serial.println();
    return temperature;
}
