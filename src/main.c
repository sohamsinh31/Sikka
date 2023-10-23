#include "core.h"

int main()
{
    struct Blockchain blockchain = createBlockchain();

    addToBlockchain(&blockchain, "Transaction 1", 4);
    addToBlockchain(&blockchain, "Transaction 2", 4);

    printBlockchain(&blockchain);

    freeBlockchain(&blockchain);

    return 0;
}
