import serial
import time
import speech_recognition as sr
r = sr.Recognizer()

mic = sr.Microphone(sample_rate = 44100, device_index = 1)
s = serial.Serial("/dev/ttyACM0", 9600)

time.sleep(5)
while 1:
    with mic as source:
        print('speak')
        audio = r.record(source, duration = 5)
        try:
            message = r.recognize_google(audio)
            print(message)
            encodedMessage = message.encode()
            s.write(encodedMessage)
        except:
            print('Try Again')
            
    