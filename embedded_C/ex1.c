#include <8051.h>

// void setdigit(unsigned int value);
// void setCycleDigit(unsigned char value);
// unsigned int setdisplay(unsigned char value);
// unsigned char div(unsigned char a, unsigned char b);
// cerinta 1: sa se afiseze pe displayul din dreapta numere intre 0 si 9
// cerinta 2: sa se afiseze pe displayul din dreapta numerele conform cu ce se alege de la switch
// cerinta 3: sa se afiseze un numar din mai multe cifre

unsigned char digits[10];
unsigned char num[3];
int main()
{
	// digits {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};

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

	P0_7 = 1;
	P3_4 = 1;
	P3_3 = 1;

	// num[0] = 227%10;
	// num[1] = 0;
	// num[2] = 19/10;

	num[0] = 0;
	num[1] = 0;
	num[2] = 0;

	unsigned char aux = 123;
	// unsigned char digit = 0;
	// unsigned char index = 0;

	
	// while (aux > 0)//JUR PE CE AM MAI SFANT COMPILATORUL SE BUGUIESTE
	// {
	// 	num[index] = aux % 10;
	// 	aux = aux / 10;
	// 	index += 1;
	// }

	num[0] = aux % 10; //DAR CU ASTA NU ARE NICIO PROBLEMA, SCARBA DRACU C-AM PIERDUT 2 ORE SI TOT NU VREA
	aux/=10;
	num[1] = aux % 10;
	aux/=10;
	num[2] = aux % 10;

	while (1)
	{
		//while-ul de mai sus poate fi pus aici sa scoata cifrele

		for (int i = 0; i < 3; i++)
		{

			P1 = digits[num[i]];
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

			for (int j = 0; j < 2; j++)
				;
		}
	}

	return 0;
}

/// unsigned int setdisplay(unsigned char value)
// {
// 	if (value == 0)
// 	{
// 		P3_4 = 0;
// 		P3_3 = 0;
// 	}
// 	if (value == 1)
// 	{
// 		P3_4 = 0;
// 		P3_3 = 1;
// 	}
// 	if (value == 2)
// 	{
// 		P3_4 = 1;
// 		P3_3 = 0;
// 	}
// 	if (value == 3)
// 	{
// 		P3_4 = 1;
// 		P3_3 = 1;
// 	}
// 	return 0;
// }

// void setdigit(unsigned int value)
// {
// 	if (value == 0)
// 		P1 = 0b11000000;
// 	if (value == 1)
// 		P1 = 0b11111001;
// 	if (value == 2)
// 		P1 = 0b10100100;
// 	if (value == 3)
// 		P1 = 0b10110000;
// 	if (value == 4)
// 		P1 = 0b10011001;
// 	if (value == 5)
// 		P1 = 0b10010010;
// 	if (value == 6)
// 		P1 = 0b10000010;
// 	if (value == 7)
// 		P1 = 0b11111000;
// 	if (value == 8)
// 		P1 = 0b10000000;
// 	if (value == 9)
// 		P1 = 0b10010000;
// }
