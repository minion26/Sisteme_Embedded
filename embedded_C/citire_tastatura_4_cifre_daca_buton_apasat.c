#include <8051.h>

int main()
{

    int numbers[4] = {0, 0, 0, 0};

    while (1)
    {

        int i = 0;
        int nr;
        int count = 0;

        // test if any keypad is press by defining all the cases
        if (P2_7 == 0)
        {
            // daca sw 7 e apasat atunci trebuie sa citesc 4 numere
            // store the numbers in an array
            while (count < 4)
            {

                P0 = 0b11111110;
                if (P0_6 == 0)
                {

                    nr = 0;
                    count++;
                    numbers[i++] = nr;
                }

                if (P0_5 == 0)
                {
                    nr = 0;
                    count++;
                    numbers[i++] = nr;
                }

                else if (P0_4 == 0)
                {
                    nr = 0;
                    count++;
                    numbers[i++] = nr;
                }
                else
                    nr = -1;

                P0 = 0b11111101; // P0_1 = 1;
                // test the column's ports
                if (P0_6 == 0)
                {
                    nr = 7;
                    count++;
                    numbers[i++] = nr;
                }
                if (P0_5 == 0)
                {
                    nr = 8;
                    count++;
                    numbers[i++] = nr;
                }

                else if (P0_4 == 0)
                {
                    nr = 9;
                    count++;
                    numbers[i++] = nr;
                }
                else
                    nr = -1;
                P0 = 0b11111011;

                // test the column's ports
                if (P0_6 == 0)
                {
                    nr = 4;
                    count++;
                    numbers[i++] = nr;
                }
                if (P0_5 == 0)
                {
                    nr = 5;
                    count++;
                    numbers[i++] = nr;
                }

                else if (P0_4 == 0)
                {
                    nr = 6;
                    count++;
                    numbers[i++] = nr;
                }
                else
                    nr = -1;

                P0 = 0b11110111;
                // test the column's ports
                if (P0_6 == 0)
                {
                    nr = 1;
                    count++;
                    numbers[i++] = nr;
                }
                if (P0_5 == 0)
                {
                    nr = 2;
                    count++;
                    numbers[i++] = nr;
                }

                else if (P0_4 == 0)
                {
                    nr = 3;
                    count++;
                    numbers[i++] = nr;
                }
                else
                    nr = -1;

                while (P0_6 == 0 || P0_5 == 0 || P0_4 == 0) // while a button is pressed dont do anything
                    ;
            }
        }

        // display the number on segment 7
        for (int j = 0; j < 4; j++)
        {
            switch (numbers[j])
            {
            case 0:
                P1 = 0b01000000;
                break;
            case 1:
                // display 1
                P1 = 0b11111001;
                break;
            case 2:
                // dispplay 2
                P1 = 0b10100100;
                break;
            case 3:
                // display 3
                P1 = 0b10110000;
                break;
            case 4:
                // display 4
                P1 = 0b10011001;
                break;
            case 5:
                // display 5
                P1 = 0b10010010;
                break;
            case 6:
                // display 6
                P1 = 0b10000010;
                break;
            case 7:
                // display 7
                P1 = 0b11111000;
                break;
            case 8:
                // display 8
                P1 = 0b10000000;
                break;
            case 9:
                // display 9
                P1 = 0b10010000;
                break;
            }

            switch (j)
            {
            case 0:
                P3_3 = 0;
                P3_4 = 0;
                break;

            case 1:
                P3_3 = 1;
                P3_4 = 0;
                break;

            case 2:
                P3_3 = 0;
                P3_4 = 1;
                break;

            case 3:
                P3_3 = 1;
                P3_4 = 1;
                break;
            }
        }
    }
    return 0;
}