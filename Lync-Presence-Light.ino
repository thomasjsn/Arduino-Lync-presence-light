/*
 Lync presence light

 Circuit: Common-cathode LEDs wired like so:
 * Green anode: digital pin 3
 * Yellow anode: digital pin 5
 * Red anode: digital pin 6
 * Cathode: GND

 Based on example ReadASCIIString by Tom Igoe
 */

// pins for the LEDs:
const int greenPin = 3;
const int yellowPin = 5;
const int redPin = 6;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int green = Serial.parseInt();
    // do it again:
    int yellow = Serial.parseInt();
    // do it again:
    int red = Serial.parseInt();

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255
      green = constrain(green, 0, 255);
      yellow = constrain(yellow, 0, 255);
      red = constrain(red, 0, 255);

      // fade the green, yellow, and red LEDs:
      analogWrite(greenPin, green);
      analogWrite(yellowPin, yellow);
      analogWrite(redPin, red);

      // print the three numbers in one string as hexadecimal:
      Serial.print(green, HEX);
      Serial.print(yellow, HEX);
      Serial.println(red, HEX);
    }
  }
}








