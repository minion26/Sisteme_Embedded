#include <8051.h>
#include <math.h>

// a program that gets input as a,b,c and calculates the roots of the equation ax^2+bx+c=0

int main()
{
    // read a,b,c when * is read from keypad

    int start_read = 0;

    int cooef[3] = {0, 0, 0};

    while (1)
    {

        P0 = 0b11111110; // set the 1 line as on

        if (P0_6 == 0)
        {
            start_read = 1;
        }
        P0 = 0b11111111;
         while(P0_6 == 0);

        if (start_read == 1)
        {
            int count = 0;
            // read the numbers from keypad a,b,c
            int end_char = 0;
            while (count < 3)
            {

                int digit_pos = 0;
                int digits[4] = {0, 0, 0, 0};
                while (end_char == 0)
                {

                    // a number can have multiple digits
                    P0 = 0b11111110;
                    if (P0_5 == 0)
                    {
                        digits[digit_pos++] = 0;
                    }
                    else if (P0_4 == 0)
                    {
                        end_char = 1;
                        
                    }

                    P0 = 0b11111101;
                    if (P0_6 == 0)
                    {
                        digits[digit_pos++] = 7;
                    }

                    else if (P0_5 == 0)
                    {
                        digits[digit_pos++] = 8;
                    }

                    else if (P0_4 == 0)
                    {
                        digits[digit_pos++] = 9;
                    }

                    // second line

                    P0 = 0b11111011;
                    if (P0_6 == 0)
                    {
                        digits[digit_pos++] = 4;
                    }

                    else if (P0_5 == 0)
                    {
                        digits[digit_pos++] = 5;
                    }

                    else if (P0_4 == 0)
                    {
                        digits[digit_pos++] = 6;
                    }

                    // third line
                    P0 = 0b11110111;
                    if (P0_6 == 0)
                    {
                        digits[digit_pos++] = 1;
                    }

                    else if (P0_5 == 0)
                    {
                        digits[digit_pos++] = 2;
                    }

                    else if (P0_4 == 0)
                    {
                        digits[digit_pos++] = 3;
                    }

                    // while a button is pressed do nothing
                    while (P0_4 == 0 || P0_5 == 0 || P0_6 == 0)
                        ;
                }
                // form a number from the digits
                int number = 0;
                int i;
                for (i = 0; i < digit_pos; i++)
                {
                    number = number * 10 + digits[i];
                }
                cooef[count++] = number;
                end_char = 0;

            }
        }
        start_read = 0;

        // else compute the square root

        int a = cooef[0];
        int b = cooef[1];
        int c = cooef[2];
        int delta = b * b - 4 * a * c;
        int x1 = 0;
        int x2 = 0;
        int display_err = 0;
        int x1_digits[4] = {0, 0, 0, 0};
        if (delta >= 0)
        {

            x1 = -b/(a+a);
            
            for (int i = 0; i < 4; i++)
            {
                x1_digits[i] = x1 % 10;
                x1 /= 10;
            }
        }

        else
        {
            display_err = 1;
        }

        // display the result on the 7 segment display

        if (display_err)
        {
            // display 111
            for (int i = 0; i < 3; i++)
            {
                P1 = 0b11111001;
                switch (i)
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
                }
            }
        }

        else
        {
            // displat the result

            for (int i = 0; i < 4; i++)
            {
                switch (x1_digits[i])
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

                // switch the panel
                switch (i)
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
    }
}