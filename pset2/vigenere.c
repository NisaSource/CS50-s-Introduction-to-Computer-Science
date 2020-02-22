#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

bool is_valid_k(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, string args[])
{
    if (argc != 2 || !is_valid_k(args[1]))
    {
        // Error messages
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    string k = args[1];
    //ask the user for the input
    string plaintext = get_string("plaintext: ");
    int k_len = strlen(k);

    //The output
    printf("ciphertext: ");

    //loop over the plaintext
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;

        int pi = plaintext[i] - ascii_offset;
        int kj = toupper(k[j % k_len]) - 65;
        int ci = (pi + kj) % 26;
        j++;

        printf("%c", ci + ascii_offset);
    }

    //line break after output
    printf("\n");
    return 0;
}