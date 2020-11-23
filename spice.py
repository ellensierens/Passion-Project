import numpy as np
# import tflite_runtime.interpreter as tflite
import tensorflow as tf

# converter = tf.lite.TFLiteConverter.from_saved_model("spice_2")
# tflite_model = converter.convert()
# open("converted_model.tflite", "wb").write(tflite_model)

# Convert the model

# converter = tf.lite.TFLiteConverter.from_saved_model("spice_2")
# converter.allow_custom_ops = True
# tflite_model = converter.convert()
# open("converted_model.tflite", "wb").write(tflite_model)

# # Load the TFLite model and allocate tensors.
interpreter = tf.lite.Interpreter(model_path="lite-model_spice_1.tflite")
# # interpreter = tflite.Interpreter(model_path= "converted_model.tflite")
interpreter.allocate_tensors()

# Get input and output tensors.
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# Test the model on random input data.
input_shape = input_details[0]['shape']
input_data = np.array([1], dtype=np.float32)
interpreter.set_tensor(input_details[0]['index'], input_data)

interpreter.invoke()

# The function `get_tensor()` returns a copy of the tensor data.
# Use `tensor()` in order to get a pointer to the tensor.
output_data = interpreter.get_tensor(output_details[0]['index'])
print(output_data)

# tflite_convert --saved_model_dir=spice_2 --output_file=spice.tflite