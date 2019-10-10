# Paper Puppets

*A lab report by Yuxin Zhang*

## In this Report

To submit your lab, clone [this repository](https://github.com/FAR-Lab/IDD-Fa18-Lab4). You'll need to describe your design, include a video of your paper display in operation, and upload any code you wrote to make it move.

## Part A. Actuating DC motors  

   https://youtu.be/pY1aTo8Fa2g

## Part B. Actuating Servo motors

### Part 1. Connect the Servo to your breadboard

**a. Which color wires correspond to power, ground and signal?**  
     Brown - ground, Red - power, Yellow - signal

### Part 2. Connect the Servo to your Arduino

**a. Which Arduino pin should the signal line of the servo be attached to?**  
     pin 9

**b. What aspects of the Servo code control angle or speed?**  
     myservo.write(pos);     // tell servo to go to position in variable 'pos'
     delay(15);              // waits 15ms for the servo to reach the position

## Part C. Integrating input and output   

  https://youtu.be/-mU9hBbrFQk

## Part D. Paper puppet  

   https://youtu.be/O5obJsV6nRQ


## Part E. Make it your own  

   I used the accelerometer to control the motor. When abs(acceleration.y) > 8, the pupet would shake its arms freakingly. The idea is to let the pupet react like it's afraid of the extreme tilt. 

**a. Make a video of your final design.**  
   https://youtu.be/O5obJsV6nRQ

 
