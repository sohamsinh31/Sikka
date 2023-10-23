#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BLOCK_SIZE 64
#define MAX_NONCE 1000000

// Define a block structure
struct Block
{
    int index;
    char timestamp[20];
    char data[255];
    char previousHash[65];
    char hash[65];
    int nonce;
    struct Block *next; // for the linked list in blockchain
};

// Define a blockchain structure
struct Blockchain
{
    struct Block *head;
};

// Functions from block.c
void printBlock(const struct Block *block);
struct Block createBlock(int index, const char *data, const char *previousHash);
void calculateHash(struct Block *block);

// Functions from mine.c
int mineBlock(struct Block *block, int difficulty);

// Functions from blockchain.c
struct Blockchain createBlockchain();
void addToBlockchain(struct Blockchain *bc, const char *data, int difficulty);
void printBlockchain(const struct Blockchain *bc);
void freeBlockchain(struct Blockchain *bc);

#endif
