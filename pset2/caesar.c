#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    else if (argc == 2)
    {
       const int k = atoi(argv[1]);
        bool isKeyValid = true;
        int len = strlen(argv[1]);

        for (int i = 0; i < len; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                isKeyValid = false;

                i = len;
            }
        }
        if (isKeyValid)
        {
            string plain = get_string("Plaintext: ");

            int plainLength = strlen(plain);

            for (int i = 0; i < plainLength; i++)
            {
                if (isupper(plain[i]))
                {
                    if (plain[i] + k > 'Z')
                    {
                        int keyRemainder = (plain[i] + k) - 'Z';
                        if (keyRemainder > 'Z' - 'A')
                        {
                            while (keyRemainder >= ('Z' - 'A'))
                            {
                                keyRemainder -= ('Z' - 'A');
                            }
                            if (plain[i] + keyRemainder > 'Z')
                            {
                                keyRemainder = plain[i] + keyRemainder - 'Z';

                                plain[i] = 'A' + keyRemainder - 1;
                            }
                            else
                            {
                                plain[i] = 'A' + keyRemainder - 1;
                            }
                        }
                        else
                        {
                            plain[i] = 'A' + keyRemainder - 1;
                        }
                    }
                }
                else if (islower(plain[i]))
                {

                }
            }
        }
    }


    if (k < 0)
    {
        printf("Key must be positive\n");
        return 1;
    }

    string plaintext = get_string("Plaintext: ");
    //loop over the plaintext
    printf("ciphertext: ");
    for (int i = 0; len = strlen(plaintext); i < len; i++)
    {
        if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'a' + k) % 26 + 'a');
        }
        else if (isupper (plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'A' + k) % 26 + 'A');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}