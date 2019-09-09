# IDD-Fa18-Lab1: Blink!

**A lab report by John Q. Student**

**Fork** this repository to get a template for Lab 1 for *Developing and Designing Interactive Devices* at Cornell Tech, Fall 2018. You should modify this `README.md` file to delete this paragraph and update below. As the lab asks:

> Include your responses to the bold questions on your own fork of the lab activities. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as `README.md` pages on your GitHub, and post a link to that on your main class hub page.

We've copied the questions from the lab here. Answer them below!

## Part A. Set Up a Breadboard

<img src="img/set_up.jpg">

## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**
     *100 Ohm - brown, black, black, black*
     *220 Ohm - red, red, black, black*
**b. What do you have to do to light your LED?**
     *connect the ardunio and press the button*


## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**
     *line 33 to line 36*
**b. What line(s) of code do you need to change to change the rate of blinking?**
     *line 34 and line 36*
**c. What circuit element would you want to add to protect the board and external LED?**
     *an resistor in series with the LED*
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**
     *I tried 1000ms, 100ms, 50ms, 25ms, 20ms, 15ms and 10ms. At 10ms delay, I can no longer perceive the LED blinking.*
**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**
     


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**
  *Youtube link for the video: https://youtu.be/Ekxh8u181xs* 



## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**
     *No. The LED can glow to the max luminosity but can not be turned off. When the potentiometer is tuned to 0 resistance, the current flow through the LED and voltage across the LED will be enough to make the LED glow at the max luminosity. However when the potentiometer is tuned to maximum resistance which is 10k, there are still current flowing through the LED so the LED whill not be turned off.*


## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**
     *Change the led pin from 9 to 11.*

**b. What is analogWrite()? How is that different than digitalWrite()?**
     *For digitalWrite(), you can only assign high or low to output voltage which is 5V or 0V. However, for analogWrite(), you can output voltages in between 0 to 5V.* 

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**
     *Yes. It's inside the Atmel ATmega32U4 Microcontroller. It's constantly storing memory and extracting memory with a clock.*

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**
     *No.* 

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**
     *The device is powered through USB mini-B. I think te power regulation is down by the USB cable. The voltages used throughout hte system are 5V and ground.* 

**d. Is information stored in your device? Where? How?**
     *Yes. The information is stored in the ATmega32U4 8-bit Microcontroller with 16/32K bytes of ISP Flash and USB Controller.*

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**

### 3. Build your light!
    Youtube link for Frankenlight video: https://youtu.be/8QlvGeleEO0

**Make a video showing off your Frankenlight.**

**Include any schematics or photos in your lab write-up.**
