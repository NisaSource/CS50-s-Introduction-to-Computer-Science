#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;
    do
    {
        // prompts user for pyramid height between 1 and 8
        input = get_int("Height: ");
    }
    while (input < 1 || input > 8);

    if (input > 0 || input < 9)
    {
        int counter = 0;
        // for loops specifying number of spaces and hashes per line
        for (int i = 0; i < input; i++)
        {
            if (counter != input)
            {
                //for loop to print out the spaces
                for (int j = (input - 1) - counter; j > 0; j--)
                {
                    printf(" ");
                }
                //for loop to print out the hashes
                for (int k = 0; k <= counter; k++)
                {
                    printf("#");
                }
                printf("\n");
                counter++;
            }
        }
    }
}