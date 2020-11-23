import tensorflow as tf

converter = tf.lite.TFLiteConverter.from_saved_model("spice_1")
converter.target_spec.supported_ops = [
  tf.lite.OpsSet.TFLITE_BUILTINS, # enable TensorFlow Lite ops.
  tf.lite.OpsSet.SELECT_TF_OPS # enable TensorFlow ops.
]
tflite_model = converter.convert()
open("converted_model_1.tflite", "wb").write(tflite_model)