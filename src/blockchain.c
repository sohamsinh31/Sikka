#include "core.h"

// Function to initialize an empty blockchain
struct Blockchain createBlockchain()
{
    struct Blockchain blockchain;
    blockchain.head = NULL;
    return blockchain;
}

// Function to add a new block to the blockchain
void addToBlockchain(struct Blockchain *bc, const char *data, int difficulty)
{
    struct Block *newBlock = (struct Block *)malloc(sizeof(struct Block));
    if (newBlock == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newBlock->index = bc->head ? bc->head->index + 1 : 0;
    time_t current_time;
    struct tm *time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(newBlock->timestamp, sizeof(newBlock->timestamp), "%Y-%m-%d %H:%M:%S", time_info);
    strncpy(newBlock->data, data, sizeof(newBlock->data));
    if (bc->head)
    {
        strncpy(newBlock->previousHash, bc->head->hash, sizeof(newBlock->previousHash));
    }
    else
    {
        strncpy(newBlock->previousHash, "0", sizeof(newBlock->previousHash));
    }

    mineBlock(newBlock, difficulty);
    newBlock->next = NULL;

    if (bc->head == NULL)
    {
        bc->head = newBlock;
    }
    else
    {
        struct Block *current = bc->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newBlock;
    }
}

// Function to print the blockchain
void printBlockchain(const struct Blockchain *bc)
{
    struct Block *current = bc->head;
    while (current != NULL)
    {
        printBlock(current);
        current = current->next;
    }
}

// Function to free the blockchain memory
void freeBlockchain(struct Blockchain *bc)
{
    struct Block *current = bc->head;
    while (current != NULL)
    {
        struct Block *temp = current;
        current = current->next;
        free(temp);
    }
    bc->head = NULL;
}
