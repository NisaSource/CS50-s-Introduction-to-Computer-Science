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
        int numb = 0;
        for (int row = 0; row < input; row++)
        {
            if (numb != input)
            {
                // all of these 3 for loops below is to show 2 sides of the wall
                for (int spaces = (input - 1) - numb; spaces > 0; spaces--)
                {
                    printf(" ");
                }
                for (int hashes = 0; hashes <= numb; hashes++)
                {
                    printf("#");
                }

                printf("  "); // to separate 2 side of the wall

                for (int hashes = 0; hashes <= numb; hashes++) // this for loop is for the right side the wall
                {
                    printf("#");
                }

                printf("\n");
                numb++;
            }
        }
    }
}