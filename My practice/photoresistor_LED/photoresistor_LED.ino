int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int led = 9;           // the PWM pin the LED is attached to
float voltage = 0;  // voltage(0~5V) cross the resistor which is affected by the photoresistor

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 0, 255);
  
  // set the brightness of pin 9:
  analogWrite(led, sensorValue);

  // show the voltage(0~5V) cross the resistor
  voltage = (sensorValue/255.0)*5.0;  // map to 0~5V
  Serial.print(voltage);
  Serial.println("V");

  // wait for 100 milliseconds to see the dimming effect
  delay(100);
}
