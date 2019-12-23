import io
import picamera
import cv2
import numpy
import serial
import time
import RPi.GPIO as gp

####### Servo Motor Contol #######
gp.setmode(gp.BOARD)
gp.setup(11, gp.OUT)
pwm=gp.PWM(11, 50)
pwm.start(3)

port = '/dev/ttyACM0'
Face = 0

turn=1
while(turn):
    
    i=3
    while(i):

        #Create a memory stream so photos doesn't need to be saved in a file
        stream = io.BytesIO()
        
        #Get the picture (low resolution, so it should be quite fast)
        #Here you can also specify other parameters (e.g.:rotate the image)
        with picamera.PiCamera() as camera:
            camera.resolution = (320, 240)
            camera.capture(stream, format='jpeg')
            print("Captured......................")

        #Convert the picture into a numpy array
        buff = numpy.fromstring(stream.getvalue(), dtype=numpy.uint8)

        #Now creates an OpenCV image
        image = cv2.imdecode(buff, 1)

        #Load a cascade file for detecting faces
        face_cascade = cv2.CascadeClassifier('/home/pi/Desktop/Buddy/haarcascade_frontalface_alt.xml')

        #Convert to grayscale
        gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

        #Look for faces in the image using the loaded cascade file
        faces = face_cascade.detectMultiScale(gray, 1.1, 5)

        #print "Found "+str(len(faces))+" face(s)"



        #Draw a rectangle around every found face
        for (x,y,w,h) in faces:
            Face = 1
            cv2.rectangle(image,(x,y),(x+w,y+h),(255,255,0),2)
            print("Detected")
            ser = serial.Serial(port, 9600, timeout=1)
                
            t=0
            while(t<2000):
                if(t%10 == 0):
                    print(t)
                t+=1

            
            ser.write(b'0') ## Stop_Detected

            with picamera.PiCamera() as camera:
                
                print("Start Video")
                camera.start_recording('examplevid.h264')
                time.sleep(5)
                camera.stop_recording()
                print("Stop Video")
            


        #Save the result image
        if(i==3):
            cv2.imwrite('result1.jpg',image)
            
        if(i==2):
            cv2.imwrite('result2.jpg',image)
            
        if(i==1):
            cv2.imwrite('result3.jpg',image)

        
        i=i-1


        if(Face == 1):
            Face = 2
            break

    ################   Move Servo   ##################      

        if(i==0):
            pwm.ChangeDutyCycle(3)
            #ser.write(b'1')  ## Move_Servo_pos1
            print("First Pos__________________________")
            
        if(i==2):
            pwm.ChangeDutyCycle(5)
            #ser.write(b'2')  ## Move_Servo_pos2
            print("Second Pos__________________________")
            
            
        if(i==1):
            pwm.ChangeDutyCycle(7)
            #ser.write(b'3')  ## Move_Servo_pos3
            print("Third Pos__________________________")

            

        t=0
        while(t<200):
            if(t%10 == 0):
                print(t)
            t+=1

    print("###############################################");

    t=0
    while(t<500):
        if(t%10 == 0):
            print(t)
        t+=1

#    turn = 0

    if(cv2.waitKey(1) & 0xFF == ord('q')):
        break
    if(Face == 2):
        Face = 0
        ser = serial.Serial(port, 9600, timeout=1)
        t=0
        while(t<2000):
            if(t%10 == 0):
                print(t)
            t+=1
        ser.write(b'1');
        break
