# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**  
   <img src="img/soldered_board.jpg">

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**  

   5V

**b. What voltage level do you need to power the display backlight?**  

   3V or 3.3V
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**  

   I did not connect the top 5 columns to the bottom 5 columns of the positive and ground rail and I used the bottom positive and ground rail to power up the LCD, which did not work. I used two wires to connect them in order to fix the problem.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**  

   lcd.print("hello, world!");
   to 
   lcd.print("Yuxin Zhang (Takosan)");
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**  
   see Lowly_Multimeter folder

## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**  
   https://youtu.be/v5jU1C3gEfE




## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**  
   change 
      int noteDuration = 1000 / noteDurations[thisNote];
   to 
      int noteDuration = 1000 / noteDurations[thisNote] / 2;
 
**b. What song is playing?**  
   It's playing Starwars (theme)

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**  
     https://youtu.be/IUFlvdQyQvI

**b. Post a link to the completed lab report your class hub GitHub repo.**  

