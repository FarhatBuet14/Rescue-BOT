import serial
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)


def work():
    ser.write(b'1')

t=0
while(t<2000):
    if(t%10 == 0):
        print(t)
    t+=1

work()      
print("Done yyaaaahhhh (Y)")
