//-------------------------------------------------------------------------------
//       ECE 3362   Project 2   redone for Project 5 in C language
//
//       When the code starts, the 2 top pushbuttons represent a two bit
//       number, and the 2 bottom pushbuttons represent a second two bit
//       number. The top button is the most significant bit, and the bottom
//       button is the least significant bit (for each pair of buttons).
//       The display displays whether or not the first number is greater
//       than, less than, or equal to the second number.
//
//       Mason Marnell - November 28th, 2020 - Revision number 1.0
//
//       Company: ECE, Texas Tech University
//
//       Adapted from MarnellMP2 by me, which was adapted from example code from
//       Dr. M. Helm - "DemoWith_1_digitExpansionBdRevised"
//
//       Target: TI LaunchPad (MSP-EXP430GET version) development board with 
//           MSP430G2553 device installed
//
//       Assembler/IDE:  IAR Embedded Workbench 7.12 Kickstart version
//       HW I/O assignments:


//       P1.0    (output) LED1 LaunchPad bd (active high)
//       P1.1    (input)  pushbutton (top) (active low) expansion bd 
//       P1.2    (input)  pushbutton (second from top) (active low) expansion bd 
//       P1.3    (input)  pushbutton on LaunchPad bd (active low)
//       P1.4    (input) pushbutton (third from top) (active low) expansion bd
//       P1.5    (input) pushbutton (bottom) (active low) expansion bd 
//       P1.6    (output) LED2 LaunchPad bd (active high)  
//       P1.7    (not used)  
//
//       P2.0    (output) Segment A (active high) drives display board
//       P2.1    (output) Segment B (active high) drives display board
//       P2.2    (output) Segment C (active high) drives display board
//       P2.3    (output) Segment D (active high) drives display board
//       P2.4    (output) Segment E (active high) drives display board
//       P2.5    (output) Segment F (active high) drives display board
//       P2.6    (output) Segment G (active high) drives display board
//       P2.7    (output) Segment DP (active high) drives display board
//
//
//
//*******************************************************************************

#include <msp430g2553.h>

#define SEG_A 0x01u //Port pin position P2.0
#define SEG_B 0x02u //Port pin position P2.1
#define SEG_C 0x04u //Port pin position P2.2
#define SEG_D 0x08u //Port pin position P2.3
#define SEG_E 0x10u //Port pin position P2.4
#define SEG_F 0x20u //Port pin position P2.5
#define SEG_G 0x40u //Port pin position P2.6
#define SEG_DP 0x80u //Port pin position P2.7


#define PB_0 0x02u //Port pin position P1.1
#define PB_1 0x04u //Port pin position P1.2   
#define PB_2 0x10u //Port pin position P1.4   
#define PB_3 0x20u //Port pin position P1.5
#define PB_LPBD 0x08u //Port pin position P1.3 (on LaunchPad bd)

#define SEG_PORT P2OUT
#define PB_PORT P1IN

#define GREATER 0x6Fu
#define LESS 0x38u
#define EQUAL 0x49u

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  //P1DIR |= 0x41;                            // P1.0, P1.6 output
  
  
  // necessary to set up the pullup resistor for the pushbutton
  
  SEG_PORT = 0;
  P1REN |= 0xBEu;
  P1OUT  |= 0xBEu;
  P2DIR = 0xFFu;
  P2SEL = 0xC0u;
  
  
  while(1){
  
  if(PB_PORT - 0xBEu == 0){
    SEG_PORT = EQUAL;
  }

  if(PB_PORT - 0xBCu == 0){//1
    SEG_PORT = GREATER; 
  }
  
  if(PB_PORT - 0xBAu == 0){//2
    SEG_PORT = GREATER;
  }

  if(PB_PORT - 0xB8u == 0){//3
    SEG_PORT = GREATER;
  }

  if(PB_PORT - 0xAEu == 0){//4
    SEG_PORT = LESS;
  }

  if(PB_PORT - 0xACu == 0){//5
    SEG_PORT = EQUAL;
  }

  if(PB_PORT - 0xAAu == 0){//6
    SEG_PORT = LESS;
  }

  if(PB_PORT - 0xA8u == 0){//7
    SEG_PORT = GREATER;
  }

  if(PB_PORT - 0x9Eu == 0){//8
    SEG_PORT = LESS;
  }

  if(PB_PORT - 0x9Cu == 0){//9
    SEG_PORT = GREATER;
  }

  if(PB_PORT - 0x9Au == 0){//10 A
    SEG_PORT = EQUAL;
  }

  if(PB_PORT - 0x98u == 0){//11 B
    SEG_PORT = GREATER;
  }

  if(PB_PORT - 0x8Eu == 0){//12 C
    SEG_PORT = LESS;
  }

  if(PB_PORT - 0x8Cu == 0){//13 D
    SEG_PORT = LESS;
  }

  if(PB_PORT - 0x8Au == 0){//14 E
    SEG_PORT = LESS;
  }

  if(PB_PORT - 0x88u == 0){//15 F
    SEG_PORT = EQUAL;
  }
 }
  
}



/*

  while(1) {
    P1OUT ^= 0x01;   // toggle the LED on P1.0
    for(int i = 0; i < 30000;i++);   // delay for a while
    
    //a++;
  
    if(P1IN & 0x08){  // test the Pushbutton
      P1OUT ^= 0x40;       // toggle  the other LED
      for(int i = 0; i < 30000;i++);   // delay for a while
      for(int i = 0; i < 30000;i++);   // delay for a while
      for(int i = 0; i < 30000;i++);   // delay for a while
      for(int i = 0; i < 30000;i++);   // delay for a while
    }
  }  // end while
  

*/