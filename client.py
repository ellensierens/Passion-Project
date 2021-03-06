import socketio
import time

sio = socketio.Client()

push = True

import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library

GPIO.setmode(GPIO.BOARD) # Use physical pin numbering

GPIO.setwarnings(False) # Ignore warning for now
GPIO.setup(16, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Set pin 10 to be an input pin and set initial value to be pulled low (off)

@sio.event
def connect():
    push = True
    print('connection established')

    
    while True: # Run forever
        if GPIO.input(16) == GPIO.HIGH:
            if push:
                push = False
                print("Button was pushed!")
                sio.emit('my_message', {'response': 'key was pressed'})

@sio.event
def connect_error():
	print("no connection") 

@sio.event
def my_message(data):
    print('message received with ', data)
    sio.emit('my response', {'response': 'my response'})

@sio.event
def disconnect():
    print('disconnected from server')
    connected = False

connected = False
while not connected:
    try:
        sio.connect('http://localhost:5000')
        connected = True
    except Exception as e:
        pass #do nothing try again


sio.wait()

