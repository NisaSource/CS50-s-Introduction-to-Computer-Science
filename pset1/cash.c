#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_change(float dollars);
int main(void)
{
    float dollars;
    do
    {
        //get number input from the user
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    //The output
    printf("%i\n", get_change(dollars));
}

int get_change(float dollars)
{
    //converting float dollars into cents
    int cents = round(dollars * 100);

    int coins = 0;
    int change[] = {25, 10, 5, 1};
    for (int i = 0; i < 4; i++)
    {
        coins += cents / change[i];
        cents = cents % change[i];
    }
    return coins;
}