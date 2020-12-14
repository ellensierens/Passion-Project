#dependencies serial communication
import serial
import time

arduino = serial.Serial('/dev/ttyUSBB',9600)
time.sleep(0.1) #wait for serial to open

if arduino.isOpen():
    cmd= "100;C3,E3,D3,G3,"
    arduino.write(cmd.encode())