#include <8051.h>

// cerinta: sa se plimbe pe led bank a.i. sa se miste de la dr la stg, cate un singur led on.
unsigned char bitmask;
int main()
{
	while (1)
	{

		bitmask = 1;
		while (1)
		{
			P1 = ~bitmask;
			bitmask = bitmask << 1;
			if (bitmask == 0)
				bitmask = 1;
		}
	}

	return 0;
}