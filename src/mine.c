#include "core.h"

// Function to mine a block with a given difficulty level
int mineBlock(struct Block *block, int difficulty)
{
    char target[difficulty + 1];
    memset(target, '0', difficulty);
    target[difficulty] = '\0';

    time_t start, end;
    double elapsed;

    start = time(NULL);

    for (int nonce = 0; nonce <= MAX_NONCE; nonce++)
    {
        block->nonce = nonce;
        calculateHash(block);

        if (strncmp(block->hash, target, difficulty) == 0)
        {
            end = time(NULL);
            elapsed = difftime(end, start);
            printf("Block mined! Hash: %s\n", block->hash);
            printf("Elapsed time: %.2f seconds\n", elapsed);
            return 1;
        }
    }

    return 0;
}
