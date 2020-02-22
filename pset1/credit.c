#include <stdio.h>
#include <cs50.h>

void printCardBrand(long ccn);
bool checksum(long ccn, int len);
bool checkLength(int len);
int length(long n);
void checkValidity(long ccn);
int main(void)
{
    long creditCard;
    do
    {
        //User's input number
        creditCard = get_long("Number: ");
    }
    while (creditCard < 0);

    checkValidity(creditCard);
}

void checkValidity(long ccn)
{
    int len = length(ccn);
    //check if the card is legit
    if (!(checkLength(len) && checksum(ccn, len)))
    {
        printf("INVALID\n");
        return;
    }
    //print out the brand of card used
    printCardBrand(ccn);
}

int length(long n)
{
    int len = 0;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

bool checkLength(int len)
{
    if (len == 13 || len == 15 || len == 16)
    {
        return true;
    }
    return false;
}

bool checksum(long ccn, int len)
{
    int sum = 0;
    //loop through the ccn's length
    for (int i = 0; i < len; i++, ccn /= 10)
    {
        //case when i is even
        if (i % 2 == 0)
        {
            //simply accumulate
            sum += (ccn % 10);
        }
        //case when i is odd
        else
        {
            //need to be careful to accumulating the value
            int digit = (2 * (ccn % 10));
            sum += (digit / 10 + digit % 10);
        }
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

void printCardBrand(long ccn)
{
    //Note that American Express uses 15-digit number
    if ((ccn >= 340000000000000 && ccn < 350000000000000) || (ccn >= 370000000000000 && ccn < 380000000000000))
    {
        printf("AMEX\n");
    }
    ///Note that MasterCard uses 16-digit number
    else if ((ccn >= 5100000000000000 && ccn < 5600000000000000))
    {
        printf("MASTERCARD\n");
    }
    //Note that Visa uses 13- and 16-digit number
    else if ((ccn >= 4000000000000 && ccn < 5000000000000) || (ccn >= 4000000000000000 && ccn < 5000000000000000))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}