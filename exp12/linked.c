#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 10  // Number of available blocks in the disk
int disk[MAX_BLOCKS] = {0};
int nextBlock[MAX_BLOCKS];
void linkedAllocation(int fileSize) 
{
    int blocksRequired = fileSize;
    int firstBlock = -1, prevBlock = -1;
    printf("\nLinked Allocation:\n");

    // Initialize the nextBlock array to -1 (indicating no links)
    int i;
    for (i = 0; i < MAX_BLOCKS; i++)
 {
        nextBlock[i] = -1;
    }
    // Allocate blocks for the file
    for (i = 0; i < MAX_BLOCKS && blocksRequired > 0; i++) 
{
        if (disk[i] == 0) {  // If the block is free
            disk[i] = 1;  // Allocate the block
            if (firstBlock == -1)
 {
                firstBlock = i;  // Set the first block
                printf("File starts at block %d\n", firstBlock);
            }

            if (prevBlock != -1)
 {
                nextBlock[prevBlock] = i;  
                printf("Block %d linked to block %d\n", i, prevBlock);
            }

            prevBlock = i;
            blocksRequired--;
        }
    }

    if (blocksRequired > 0)
 {
        printf("Not enough space for the file.\n");
    }
 else
 {
        printf("File allocated successfully.\n");
    }
}

int main() 
{
    int fileSize;

    printf("Enter the file size for linked allocation (number of blocks): ");
    scanf("%d", &fileSize);
    linkedAllocation(fileSize);
return 0;
}

