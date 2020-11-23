import socketio
# import keyboard
# from pynput.keyboard import Listener
from pynput.keyboard import Key, Listener

sio = socketio.Client()

# with Listener() as listener:
#     listener.join()

# def on_press(key):
#     print("Key pressed")

# def on_release(key):
#     print("Key released")


@sio.event
def connect():
    print('connection established')
    # while True:  # making a loop
    #     try:  # used try so that if user pressed other than the given key error will not be shown
    #         if keyboard.is_pressed('q'):  # if key 'q' is pressed 
    #             print('You Pressed A Key!')
    #             loop_function()
    #             break  # finishing the loop
    #     except:
    #         break  # if user pressed a key other than the given key the loop will break
    def on_press(key):
        print("key pressed")
        sio.emit('my_message', {'response': 'key was pressed'})

    # Collect events until released
    with Listener(
            on_press=on_press) as listener:
        listener.join()
    

@sio.event
def my_message(data):
    print('message received with ', data)
    sio.emit('my response', {'response': 'my response'})

@sio.event
def disconnect():
    print('disconnected from server')


sio.connect('http://localhost:5000')
sio.wait()