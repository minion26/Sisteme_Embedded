#include <8051.h>
int main()
{
    // ex 1 : o singura tasta, trb sa o identific si sa o afisez pe display

    while (1)
    {
        P0_7 = 0;
        P3_4 = 1;
        P3_3 = 0;

        P0_4 = 1;
        P0_5 = 1;
        P0_6 = 1;

        P0 = 0b11111110;
        // cifra 0
        if (P0_5 == 0)
        {
            // cifra 0
            P1 = 0b11000000;
        }

        P0 = 0b11111101;
        if (P0_4 == 0)
        {
            // cifra 9
            P1 = 0b10010000;
        }
        else if (P0_5 == 0)
        {
            // cifra 8
            P1 = 0b10000000;
        }
        else if (P0_6 == 0)
        {
            // cifra 7
            P1 = 0b11111000;
        }

        P0 = 0b11111011;
        if (P0_4 == 0)
        {
            // cifra 6
            P1 = 0b10000010;
        }
        else if (P0_5 == 0)
        {
            // cifra 5
            P1 = 0b10010010;
        }
        else if (P0_6 == 0)
        {
            // cifra 4
            P1 = 0b10011001;
        }

        P0 = 0b11110111;
        if (P0_4 == 0)
        {
            // cifra 3
            P1 = 0b10110000;
        }
        else if (P0_5 == 0)
        {
            // cifra 2
            P1 = 0b10100100;
        }
        else if (P0_6 == 0)
        {
            // cifra 1
            P1 = 0b11111001;
        }

        for (int j = 0; j < 2; j++)
            ;
    }

    return 0;
}