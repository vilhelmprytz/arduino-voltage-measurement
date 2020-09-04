#include <Arduino.h>

int analogPin = A0; // analog pin 0
int val = 0; // current analog value
float voltage = 0; // current calculated voltage

int green_led = 12; // LED that is connected to green
int red_led = 13; // LED that is connected to red

void setup() {
  // ability to print back value to connected computer
  Serial.begin(9600);

  // pin 12 = green lamp
  pinMode(green_led, OUTPUT);

  // pin 13 = red lamp
  pinMode(red_led, OUTPUT);
}

// 1023 --> 5 V
// 657 --> 3.3 V
// 0 --> 0 V

void loop() {
  val = analogRead(analogPin); // read the current value
  voltage = 5.0 * val / 1024; // since the analog input only has 1024 bits this is how we convert to volt
  Serial.println(voltage); // print value back to us

  // updating continuously floods the connection
  delay(500); // update very 500

  // if voltage above 1.5, all good
  if (voltage > 1.5) {
    digitalWrite(green_led, HIGH); // power on green
    digitalWrite(red_led, LOW); // power off red
  } else { // not OK!
    digitalWrite(green_led, LOW); // power off green
    digitalWrite(red_led, HIGH); // power on red
  }
}
