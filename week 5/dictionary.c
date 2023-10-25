// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include "dictionary.h"


bool loaded = false;
int word_count = 0;
const int hashtable_size = 25000;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *hashtable[hashtable_size] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char *word_cpy = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        word_cpy[i] = tolower(word[i]);
    }
    word_cpy[len] = '\0';

    node *cursor = hashtable[hash(word_cpy)];

    while (cursor != NULL)
    {
        if (strcasecmp(word_cpy, cursor->word) == 0)
        {
            free(word_cpy);
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    free(word_cpy);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_id = 0;
    unsigned int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        hash_id = (hash_id << 2) ^ word[i];
    }
    return hash_id % hashtable_size;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Can not open dictionary!");
        return false;
    }
 
    // scan each word in a dictionary
    while (fscanf(file, "%s", word) != EOF)
    {

        // malloc a new node
        node *new_node = malloc(sizeof(node));
        
        if (new_node == NULL)
        {
            printf("Can not create new node!");
            return false;
        }
        
        strcpy(new_node->word, word);

        int hash_id = hash(new_node->word);

        if (hashtable[hash_id] == NULL)
        {
            hashtable[hash_id] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = hashtable[hash_id];
            hashtable[hash_id] = new_node;
        }

        word_count++;
    }
    loaded = true;
    fclose(file);
    return true;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    // TODO
    for (int i = 0; i <= hashtable_size; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    loaded = false;
    return true;
}