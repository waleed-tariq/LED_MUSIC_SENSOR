# LED Sound Sensor

This is the Arduino code for an RGB strip that will change its luminosity based on the music it hears. The main component that is doing the work is the sound sensor. It assigns certain values based on how loud the sound it hears. This allows the code to change the intensity of the LED's based on the value the sensor returns. To power the LED's, must use either a 5 volt power supply or some other power source. The RGB strip also fades through all of the colors as it is powered on. Within the code is a lot of commented out chunks. These are different pieces of code that can manipulate the LED strip. They can be ignored if the main use of the strip is to have it communicate with the sensor.

## Requirements

Arduino Leonardo
Microphone Sensor (must have analog output)
WS2812B LED Strip
5 Volt Power Supply
