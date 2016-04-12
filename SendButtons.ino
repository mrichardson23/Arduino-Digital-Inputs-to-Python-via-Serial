/*
   Arduino to Python Serial Button Sender
   by Matt Richardson
   http://mattrichardson.com/
   April 7, 2013
   
   This Arduino and Python code is an easy way to get the state of eight
   digital inputs from the Arduino and pass them as a single byte into Python.
   It's hard-coded to take 8 pins, however you can use any eight pins.
   
   The state of 8 digital inputs (like buttons or switches) can be sent via serial
   in a single byte. This is because there are 8 bits in a byte, each with a state of
   on or off.
 
   To use this code as is, use 8 normally open buttons. One side of each pin connects
   to the digital inputs 2 through 9 (or otherwise if you change FIRST_PIN below).
   The other side of all the buttons connect to GND.
   
*/

int pins[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i++) { // for each of 8 pins in pins array
    pinMode(pins[i], INPUT); // each pin is an input
    digitalWrite(pins[i], HIGH); // and turn on pull up resistors
  }
}

void loop() {
  if (Serial.available() > 0) { // any bytes in coming? If so:
    byte response = B00000000;
    for (int i = 7; i >= 0; i--) { // Let's work backwards through each pin.
      if (digitalRead(pins[i]) == LOW) { // if the pin is LOW, meaning the button is pressed
        response = response << 1; // Shift all bits to the left one spot. Has no real effect on first iteration (0=00000000)
        response += 1; // Set the last bit to one by adding the int 1 to response.
      } else { // if the pin is HIGH, meaning the button is not pressed...
        response = response << 1; // Just shift the bits, filling in a 0 in that spot.
      }
    }
    Serial.write(response); // When we're done, write the byte out via serial.
    while (Serial.available()) Serial.read(); // clear out any remaining bytes in the incoming buffer.
  }
}
