/////////////////KEYPAD INTERFACING///////////////

#include<reg51.h>    //include 8051 header file.
#define DATA P2			//Select port2 as a data output pin.
#define input P3		//Select port3 as a keypad input pin.
unsigned int i,j,k;

sbit rs=P1^0;      //select the pin P1.0 for register select.
sbit rw=P1^1;			 //select the pin P1.1 for read/write.
sbit en=P1^2;			 //select the pin P1.2 for Enable.
sbit clr=P1^3;		 //select the pin P1.3 for clear the Display.	
unsigned int check[]={0xFE,0xFD,0xFB,0xF7};
unsigned int numb[]={0x7E,0xBE,0xDE,0xEE,0x7D,0xBD,0xDD,0xED,0x7B,0xBB,0xDB,0xEB,0x77,0xB7,0xD7,0xE7};
unsigned char val[]={"123A456B789C*0#D"};
unsigned char key[]={"key press= "};

void delay(unsigned int x) //Delay Function
{
	for(i=0;i<x;i++)
		for(j=0;j<1275;j++);
}

void lcddata(unsigned char dat) // Function for LCD data.
{
	DATA=dat;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;	
}

void lcdcmd(unsigned char comnd) // Function for LCD Command.
{
DATA=comnd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}

void main(){
	  	input=0xff;	
			lcdcmd(0x38);   //select the pin P3.2 for Enable.
			delay(10);
			lcdcmd(0x0E);		//Command for : Display ON,Cursor ON.
			delay(10);
			lcdcmd(0x06);	 //Command for : Entry MOde.
			delay(15);
			lcdcmd(0x80);		//Command for : Force Cursor to beginning of 1st row.
			for(k=0;k<11;k++){    // Call key[] array.
				lcddata(key[k]);					
			}	
		lcdcmd(0x8c);			//Command for : Force Cursor to 12th no matrix of 1st row outof 16th matrix.
	while(1){
		
				input=0xFE;    // send 0 to the 1st row of keypad.
		if(input!=0xFE){
				if(input==0x7E){
					lcddata(val[3]);
				break;
				}
				if(input==0xBE){
					lcddata(val[2]);
					break;
				}
				if(input==0xDE){
				lcddata(val[1]);
					break;
				}
				if(input==0xEE){
				lcddata(val[0]);
					break;
				}
			
		}
				input=0xFD;		// send 0 to the 2nd row of keypad.
		if(input!=0xFD){
				if(input==0x7D){
					lcddata(val[7]);
					break;
				}
				if(input==0xBD){
				lcddata(val[6]);
					break;
				}
				if(input==0xDD){
					lcddata(val[5]);
					break;
				}
				if(input==0xED){
				lcddata(val[4]);
					break;
				}
			
		}
				input=0xFB;		// send 0 to the 3rd row of keypad.
		if(input!=0xFB){
			if(input==0x7B){
				lcddata(val[11]);
					break;
				}
				if(input==0xBB){
					lcddata(val[10]);
					break;
				}
				if(input==0xDB){
				lcddata(val[9]);
					break;
				}
				if(input==0xEB){
					lcddata(val[8]);
					break;
				}
			
		}
		input=0xF7;					// send 0 to the 4th row of keypad.
		if(input!=0xF7){
			if(input==0x77){
				lcddata(val[15]);
					break;
				}
				if(input==0xB7){
					lcddata(val[14]);
					break;
				}
				if(input==0xD7){
					lcddata(val[13]);
					break;
				}
				if(input==0xE7){
					lcddata(val[12]);
					break;
				}
			
		}
		
		if(clr==0){
				lcdcmd(0x01);    //Command for : Clear Display Screen.
			delay(10);
			break;
		}

}
	}
