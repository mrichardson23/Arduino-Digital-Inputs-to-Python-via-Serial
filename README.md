Sample Code: Arduino Digital Inputs to Python via Serial
=============
by Matt Richardson
http://mattrichardson.com/
April 7, 2013

This Arduino and Python code is an easy way to get the state of 8 eight
digital inputs from the Arduino and pass them as a single byte into Python.
It's hard-coded to take 8 pins, starting with the pin defined as FIRST_PIN
in SendButtons.ino.

The state of 8 digital inputs (like buttons or switches) can be sent via serial
in a single byte. This is because there are 8 bits in a byte, each with a state of
on or off.

To use this code as is, use 8 normally open buttons. One side of each pin connects
to the digital inputs 2 through 9 (or otherwise if you change FIRST_PIN).
The other side of all the buttons connect to GND.