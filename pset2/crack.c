#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

//define a function
bool bruteForce(string givenHash);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //check if there is no hash input
        printf("Usage: ./crack hash\n");
        return 1;
    }
    if (!bruteForce(argv[1]))
    {
        return 1;
    }
}

bool bruteForce(string givenHash)
{
    //all the alphabets lower and uppercase
    string all = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //the password would be no longer than 5 character
    char collect[5];
    char salt[3];
    salt[0] = givenHash[0];
    salt[1] = givenHash[1];
    salt[2] = '\0';

    //single letter
    for (int i = 0; i < 26 + 26; i++) // 26 + 26 because total of lowercase is 26 and total of uppercase is 26 too
    {
        collect[0] = all[i];
        collect[1] = '\0';
        string newHash = crypt(collect, salt);
        if (strcmp(newHash, givenHash) == 0)
        {
            //print out the cracked password
            printf("%s\n", collect);
            return true;
        }
    }

    //two letters
    for (int i = 0; i < 26 + 26; i++) // 26 + 26 because total of lowercase is 26 and total of uppercase is 26 too
    {
        collect[0] = all[i];
        for (int j = 0; j < 26 + 26; j++)
        {
            collect[1] = all[j];
            collect[2] = '\0';

            char *newHash = crypt(collect, salt);
            if (strcmp(newHash, givenHash) == 0)
            {
                printf("%s\n", collect);
                return 0;
            }
        }
    }

    //three letters
    for (int i = 0; i < 26 + 26; i++)
    {
        collect[0] = all[i];
        for (int j = 0; j < 26 + 26; j++)
        {
            collect[1] = all[j];
            for (int k = 0; k < 26 + 26; k++)
            {
                collect[2] = all[k];
                collect[3] = '\0';
                char *newHash = crypt(collect, salt);
                if (strcmp(newHash, givenHash) == 0)
                {
                    printf("%s\n", collect);
                    return true;
                }
            }
        }
    }

    //four letters
    for (int i = 0; i < 26 + 26; i++)
    {
        collect[0] = all[i];
        for (int j = 0; j < 26 + 26; j++)
        {
            collect[1] = all[j];
            for (int k = 0; k < 26 + 26; k++)
            {
                collect[2] = all[k];
                for (int l = 0; l < 26 + 26; l++)
                {
                    collect[3] = all[l];
                    collect[4] = '\0';
                    char *newHash = crypt(collect, salt);
                    if (strcmp(newHash, givenHash) == 0)
                    {
                        printf("%s\n", collect);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}