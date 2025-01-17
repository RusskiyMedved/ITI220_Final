#include <msp430.h> 

//defines leds

//(Name = Player Number + Spot (1-9) number)
//Pin 1
#define P1S1 BIT1
#define P1S2 BIT2
#define P1S3 BIT3
#define P1S4 BIT4
#define P1S5 BIT5
#define P1S6 BIT6
#define P1S7 BIT7
//Pin 2
#define P1S8 BIT1
#define P1S9 BIT2

//Player 2
//Pin 6
#define P2S1 BIT0
#define P2S2 BIT1
#define P2S3 BIT2
#define P2S4 BIT3
#define P2S5 BIT4
//Pin 4
#define P2S6 BIT0
#define P2S7 BIT4
#define P2S8 BIT6
#define P2S9 BIT7

//Sets output for p1 bit 1-7
#define SETP1(a, b, c ,d ,e ,f, h) (P1DIR |= ((a) | (b) | (c)| (d) | (e) | (f) | (h)))
//Sets output for p2 bit 8-9
#define SETP2(a, b) (P2DIR |= ((a) | (b)))


//Sets output for p6 bit 1-5
#define SETP6(a, b, c, d, e) (P6DIR |= ((a) | (b) | (c) | (d)))
//Sets output for p4 bit 6-9
#define SETP4(a, b, c, d) (P4DIR |= ((a) | (b) | (c)))



//Player 1 spots 1-9 are covered by pins 1 and 2 P2.3 is unused
#define ONP1(x) (P1OUT |= (x))
#define OFFP1(x) (P1OUT &= ~(x))
#define ONP2(x) (P2OUT |= (x))
#define OFFP2(x) (P2OUT &= ~(x))

//Player 2 spots 1-9 are covered by pin 6 (bit 0-5) and pin 4 (bit 0 & 4 & 6 - 7)
#define ONP4(x) (P4OUT |= (x))
#define OFFP4(x) (P4OUT &= ~(x))
#define ONP6(x) (P6OUT |= (x))
#define OFFP6(x) (P6OUT &= ~(x))


void setup();
void allOff();

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	setup();


	return 0;

}
void setup(){
    PM5CTL0 &= ~LOCKLPM5;
    //Set output
    SETP1(P1S1, P1S2, P1S3, P1S4, P1S5, P1S6, P1S7);
    SETP2(P1S8, P1S9);

    SETP6(P2S1, P2S2, P2S3, P2S4, P2S5);
    SETP4(P2S6, P2S7, P2S8, P2S9);

    //Button Pin 5.0
    P5DIR |= ~BIT0;
    P5OUT |= BIT0;
    P5IES |= BIT0;
    P5IFG &= ~BIT0;
    P5IE |= BIT0;
    //Button Pin 5.1
    P5DIR |= ~BIT1;
    P5OUT |= BIT1;
    P5IES |= BIT1;
    P5IFG &= ~BIT1;
    P5IE |= BIT1;
    //Button Pin 5.2
    P5DIR |= ~BIT2;
    P5OUT |= BIT2;
    P5IES |= BIT2;
    P5IFG &= ~BIT2;
    P5IE |= BIT2;
    //Button Pin 5.3
    P5DIR |= ~BIT3;
    P5OUT |= BIT3;
    P5IES |= BIT3;
    P5IFG &= ~BIT3;
    P5IE |= BIT3;
    //Button Pin 5.4
    P5DIR |= ~BIT4;
    P5OUT |= BIT4;
    P5IES |= BIT4;
    P5IFG &= ~BIT4;
    P5IE |= BIT4;
    //Button Pin 5.5
    P5DIR |= ~BIT5;
    P5OUT |= BIT5;
    P5IES |= BIT5;
    P5IFG &= ~BIT5;
    P5IE |= BIT5;
    //Button Pin 3.1
    P3DIR |= ~BIT1;
    P3OUT |= BIT1;
    P3IES |= BIT1;
    P3IFG &= ~BIT1;
    P3IE |= BIT1;


    allOff();
}

void allOff(){
    //Player 1
    OFFP1(P1S1);
    OFFP1(P1S2);
    OFFP1(P1S3);
    OFFP1(P1S4);
    OFFP1(P1S5);
    OFFP1(P1S6);
    OFFP1(P1S7);
    OFFP2(P1S8);
    OFFP2(P1S9);

    //Player 2
    OFFP6(P2S1);
    OFFP6(P2S2);
    OFFP6(P2S3);
    OFFP6(P2S4);
    OFFP6(P2S5);
    OFFP4(P2S6);
    OFFP4(P2S7);
    OFFP4(P2S8);
    OFFP4(P2S9);
}
