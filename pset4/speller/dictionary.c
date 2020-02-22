// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int count = 0;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        // create a temporary node
        node *temp = malloc(sizeof(node));

        strncpy(temp->word, word, sizeof(word));

        // implement hash function to get the index
        int index = hash(word);

        // if the corresponding index in hashtable is empty, assign it to the temp node
        if (hashtable[index] == NULL)
            hashtable[index] = temp;

        // else append temp to the start of the linked list
        else
        {
            temp->next = hashtable[index];
            hashtable[index] = temp;
        }
        // count words
        count++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // allocate memory to our checker
    node* checker = malloc(sizeof(node));

    // determine in which bucket is the word
    int bucket = hash(word);

    // situation of the word in our checdker
    checker = hashtable[bucket];

    while (checker != NULL)
    {
        // use strcasecmp to be case insensitive
        if (strcasecmp(checker->word, word) == 0)
        {
            return true;
        }
        checker = checker->next;
    }
    free(checker);
    return false;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // for (int i = 0; i < N; i++)
    // {
    //     // initiate a cursor
    //     node *cursor;

    //     // place the cursor inside the hashtable
    //     cursor = hashtable[i];

    //     while (cursor)
    //     {
    //         node* tmp = cursor;
    //         cursor = cursor->next;
    //         free(tmp);
    //         return true;
    //     }

    //     // clean the hashtable
    //     hashtable[i] = NULL;
    // }
    // return false;
    return true;
}
