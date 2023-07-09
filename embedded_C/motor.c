#include <8051.h>

//cerinta: sa se spinuiasca motorul o data intr-o directie si alta data in alta directie, cu un interval
int main()
{
	while (1)
	{

		P3_0 = 1;
		P3_1 = 0;

		for (int i = 0; i < 2; i++)
			;

		P3_1 = 1;
		P3_0 = 0;
		
		for (int i = 0; i < 2; i++)
			;
	}

	return 0;
}