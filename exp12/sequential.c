#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 10
int disk[MAX_BLOCKS] = {0};
void sequentialAllocation(int fileSize) {
    int blocksRequired = fileSize;
    printf("\nSequential Allocation:\n");

    // Find contiguous free blocks for the file
    int i;
    for (i = 0; i < MAX_BLOCKS && blocksRequired > 0; i++) {
        if (disk[i] == 0) {  // If the block is free
            disk[i] = 1;  // Allocate the block
            blocksRequired--;
            printf("Block %d allocated\n", i);
        }
    }

    if (blocksRequired > 0)
 {
        printf("Not enough space for the file.\n");
    } else {
        printf("File allocated successfully.\n");
    }
}

int main() 
{
    int fileSize;
    printf("Enter the file size for sequential allocation (number of blocks): ");
    scanf("%d", &fileSize);
    sequentialAllocation(fileSize);
    return 0;
}

