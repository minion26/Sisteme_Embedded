#include <8051.h>
// Write a program that reads 4 keys from the keypad (pressed and released sequentially by the user) and then 
// shows them on the 4 displays. 
// This problem does not bring anything new in terms of reading the keypad, but it requires the programmer to 
// carefully manage the keys that have been pressed. The most important issue here is that, when the user presses 
// a key, the program will read a sequence of identical values until the key has been released. For example, if the 
// user presses key '8' at some point, it will take some time before the user releases that key; during this time 
// interval, the program will repeatedly detect key '8' being pressed. It would be an error to consider that the user 
// has pressed key '8' multiple times. 
// The solution is to permanently compare the current situation of the keypad with the previous situation (i.e., the 
// situation recorded the last time when the keypad was previously scanned). The program must consider that a 
// new key was pressed only when both conditions below are met: 
// - In the previous scan no key was pressed. 
// - In the current scan a key is pressed; this is the newly pressed key, which must be stored for later display.


unsigned char digits[12];
unsigned char num[4];
int main()
{
	// digits {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
	// * = 0b01111111
	// # = 0b11111110
	digits[0] = 0b11000000;
	digits[1] = 0b11111001;
	digits[2] = 0b10100100;
	digits[3] = 0b10110000;
	digits[4] = 0b10011001;
	digits[5] = 0b10010010;
	digits[6] = 0b10000010;
	digits[7] = 0b11111000;
	digits[8] = 0b10000000;
	digits[9] = 0b10010000;
	digits[10] = 0b10001001; // = *
	digits[11] = 0b10100001; // = #

	P0_7 = 1; // enable
	P3_4 = 0;
	P3_3 = 0;



	unsigned char lastSymbol = 0b01111111;
	unsigned char pressedFlag;
	unsigned char currentSymbol;
	for (unsigned char i = 0; i < 4; i++)
	{
		currentSymbol = 0b01111111; // o valoare pe care niciun simbol n-o ia

		while (1)
		{
			pressedFlag = 0;

			P0 = 0b11111110;

			if (P0_6 == 0)
			{
				currentSymbol = digits[10];
				pressedFlag = 1;
			}
			else if (P0_5 == 0)
			{
				currentSymbol = digits[0];
				pressedFlag = 1;
			}
			else if (P0_4 == 0)
			{
				currentSymbol = digits[11];
				pressedFlag = 1;
			}

			P0 = 0b11111101;

			if (P0_6 == 0)
			{
				currentSymbol = digits[7];
				pressedFlag = 1;
			}
			else if (P0_5 == 0)
			{
				currentSymbol = digits[8];
				pressedFlag = 1;
			}
			else if (P0_4 == 0)
			{
				currentSymbol = digits[9];
				pressedFlag = 1;
			}

			P0 = 0b11111011;

			if (P0_6 == 0)
			{
				currentSymbol = digits[4];
				pressedFlag = 1;
			}
			else if (P0_5 == 0)
			{
				currentSymbol = digits[5];
				pressedFlag = 1;
			}
			else if (P0_4 == 0)
			{
				currentSymbol = digits[6];
				pressedFlag = 1;
			}

			P0 = 0b11110111;

			if (P0_6 == 0)
			{
				currentSymbol = digits[1];
				pressedFlag = 1;
			}
			else if (P0_5 == 0)
			{
				currentSymbol = digits[2];
				pressedFlag = 1;
			}
			else if (P0_4 == 0)
			{
				currentSymbol = digits[3];
				pressedFlag = 1;
			}

			if ((currentSymbol != lastSymbol) && (pressedFlag == 0) && (currentSymbol != 0b01111111)) //ultimul e necesar, dar nu stiu de ce. observ ca se buguieste cumva si ajunge currentSymbol = lastSymbol si face practic skip din 2 in 2 pasi
				break;
			
		}

		num[i] = currentSymbol;
		lastSymbol = currentSymbol;
		
	}

	while (1)
	{

		for (int i = 3; i >=0; i--)
		{

			if (i == 0)
			{
				P3_4 = 0;
				P3_3 = 0;
			}
			else if (i == 1)
			{
				P3_4 = 0;
				P3_3 = 1;
			}
			else if (i == 2)
			{
				P3_4 = 1;
				P3_3 = 0;
			}
			else if (i == 3)
			{
				P3_3 = 1;
				P3_4 = 1;
			}
			P1 = num[3-i]; // digits[num[i]];

			for (int j = 0; j < 2; j++)
				;
		}
	}

	return 0;
}