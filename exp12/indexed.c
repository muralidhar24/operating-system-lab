#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 10  
#define MAX_FILE_SIZE 5  

int disk[MAX_BLOCKS] = {0};
int indexBlock[MAX_FILE_SIZE] = {-1};
void indexedAllocation(int fileSize) 
{
    int blocksRequired = fileSize;
    int indexPointer = 0;
    printf("\nIndexed Allocation:\n");
    int i;
    for (i = 0; i < MAX_BLOCKS && blocksRequired > 0; i++) 
{
        if (disk[i] == 0) {  // If block is free
            disk[i] = 1;  // Allocate the block
            indexBlock[indexPointer++] = i;  // Store the block's index in the index block
            blocksRequired--;
            printf("Block %d allocated at index %d\n", i, indexPointer - 1);
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
    printf("Enter the file size for indexed allocation (number of blocks): ");
    scanf("%d", &fileSize);

    indexedAllocation(fileSize);

    return 0;
}

