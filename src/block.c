#include "core.h"

// Function to calculate the basic hash of a block
void calculateHash(struct Block *block)
{
    char combined[BLOCK_SIZE];
    snprintf(combined, sizeof(combined), "%d%s%s%s%d", block->index, block->timestamp, block->data, block->previousHash, block->nonce);

    // Use a simple hash function for demonstration
    int hash = 0;
    for (int i = 0; i < strlen(combined); i++)
    {
        hash += combined[i];
    }
    snprintf(block->hash, sizeof(block->hash), "%d", hash);
}

// Function to create a new block
struct Block createBlock(int index, const char *data, const char *previousHash)
{
    struct Block block;
    block.index = index;
    time_t current_time;
    struct tm *time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(block.timestamp, sizeof(block.timestamp), "%Y-%m-%d %H:%M:%S", time_info);
    strncpy(block.data, data, sizeof(block.data));
    strncpy(block.previousHash, previousHash, sizeof(block.previousHash));
    block.nonce = 0; // Initialize nonce to 0 when creating a new block
    calculateHash(&block);
    return block;
}

// Function to display a block
void printBlock(const struct Block *block)
{
    printf("Block:\n");
    printf("Index: %d\n", block->index);
    printf("Timestamp: %s\n", block->timestamp);
    printf("Data: %s\n", block->data);
    printf("Previous Hash: %s\n", block->previousHash);
    printf("Nonce: %d\n", block->nonce); // Print nonce
    printf("Hash: %s\n", block->hash);
    printf("\n");
}
