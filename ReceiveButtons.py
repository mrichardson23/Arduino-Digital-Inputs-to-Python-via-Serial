#   Arduino to Python Serial Button Sender
#   by Matt Richardson
#   http://mattrichardson.com/
#   April 7, 2013
#   Use in conjunction with SendButtons.ino

import serial
import time
import glob

# Below is Mac-specific to get the serial ports into a list
# Check http://stackoverflow.com/questions/11303850/what-is-the-cross-platform-method-of-enumerating-serial-ports-in-python-includi
# and the answer http://stackoverflow.com/a/11398450/440779
# for other platforms.
SerialPorts = glob.glob('/dev/tty.usb*') + glob.glob('/dev/cu.usb*')

ser = serial.Serial(SerialPorts[0], 9600, timeout=1) # create the serial object
time.sleep(2) # Arduino needs time to reset after a serial connection.

ser.flushInput() # Clear the buffer
inByte = ser.read(1) # Grab the next byte (timesout after 1 sec, as set above)
inByte = int(inByte.encode('hex'), 16) #Convert the hex string into an int.

# Below, we're doing a bitwise comparison of the bits in the serial input byte AND the int value
# represented by each bit being turned on, but none of the others:
# 00000001 = 1
# 00000010 = 2
# 00000100 = 4
# 00001000 = 8
# 00010000 = 16
# 00100000 = 32
# 01000000 = 64
# 10000000 = 128

if inByte&1: 
	print "Button 1 pressed."
if inByte&2:
	print "Button 2 pressed."
if inByte&4:
	print "Button 3 pressed."
if inByte&8:
	print "Button 4 pressed."
if inByte&16:
	print "Button 5 pressed."
if inByte&34:
	print "Button 6 pressed."
if inByte&64:
	print "Button 7 pressed."
if inByte&128:
	print "Button 8 pressed."

if inByte == 0:
	print "No buttons are pressed."
