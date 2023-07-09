#include <8051.h>

// cerinta: sa se spinuiasca motorul o data intr-o directie si alta data in alta directie, cu un interval, cu switch pe P2_0
int main()
{
	while (1)
	{
		if (P2_0)
		{
			P3_0 = 1;
			P3_1 = 0;
		}
		else
		{
			P3_1 = 1;
			P3_0 = 0;
		}
	}

	return 0;
}