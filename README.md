# Keypad_interfacing
<br>
 Steps to interface the keypad :-  S1. First store the characters in an array which displays the LCD display. 
 S2. Write the functions for LCD Data & LCD Command. 
 S3. Start the main function, & initialize port 3 for input  [send 0xff to the port] , port 3 connects to the keypad.   
 S4. Send the Command to the LCD  to Configure the LCD .  
 S5. Start an infinite loop .   
 S6. Send "0" to the row of the 4x4 matrix  keypad  one by one. And check which key is pressed.    
 S7. Then which key pressed this related character data which is stored in the array this is sent to the display as a data. which is displayed in the LCD display.     S8. Here one switch is connected to the P1.3 . If the switch is pressed  the display is cleared
