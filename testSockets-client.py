import socketio
# import keyboard
# from pynput.keyboard import Listener
#from pynput.keyboard import Key, Listener
import time

sio = socketio.Client()

import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library

GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
GPIO.setup(18,GPIO.OUT)
GPIO.setwarnings(False) # Ignore warning for now
GPIO.setup(16, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Set pin 10 to be an input pin and set initial value to be pulled low (off)

@sio.event
def connect():
    print('connection established')

    GPIO.output(18, GPIO.HIGH)
    # while True:  # making a loop
    #     try:  # used try so that if user pressed other than the given key error will not be shown
    #         if keyboard.is_pressed('q'):  # if key 'q' is pressed 
    #             print('You Pressed A Key!')
    #             loop_function()
    #             break  # finishing the loop
    #     except:
    #         break  # if user pressed a key other than the given key the loop will break
    # def on_press(key):
    #     print("key pressed")
    #     sio.emit('my_message', {'response': 'key was pressed'})

    # # Collect events until released
    # with Listener(
    #         on_press=on_press) as listener:
    #     listener.join()

    
    while True: # Run forever
        if GPIO.input(16) == GPIO.HIGH:
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
while not connected:
    try:
        sio.connect('http://localhost:5000')
        connected = True
    except Exception as e:
        pass #do nothing try again


sio.wait()

