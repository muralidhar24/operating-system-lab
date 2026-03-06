#include <stdio.h>
#include <stdlib.h>
// Define page size and memory size
#define PAGE_SIZE 4   // Size of each page in KB
#define MEMORY_SIZE 16 // Total physical memory size in KB
void simulatePaging(int logicalAddresses[], int numAddresses, int pageTable[], int numPages);
int main() {
    int numPages = MEMORY_SIZE / PAGE_SIZE;
    // Page table mapping logical pages to physical frames
    int pageTable[] = {3, 1, 4, 2};  // Logical page i is mapped to frame pageTable[i]
   // Logical addresses to translate
    int logicalAddresses[] = {5, 8, 14, 18, 2, 9}; // Logical addresses in KB
    int numAddresses = sizeof(logicalAddresses) / sizeof(logicalAddresses[0]);
    printf("Simulating Paging Technique:\n");
    simulatePaging(logicalAddresses, numAddresses, pageTable, numPages);
    return 0;
}
// Function to simulate paging
void simulatePaging(int logicalAddresses[], int numAddresses, int pageTable[], int numPages) {
    printf("Logical Address -> Physical Address\n");
    int i;
    for (i = 0; i < numAddresses; i++) 
{
        int logicalAddress = logicalAddresses[i];
        int pageNumber = logicalAddress / PAGE_SIZE; 
        int pageOffset = logicalAddress % PAGE_SIZE; 
        if (pageNumber >= numPages)
 {
            printf("Logical Address %d: Invalid (Page number %d out of range)\n", logicalAddress, pageNumber);
        }
 else 
{
            int frameNumber = pageTable[pageNumber]; 

            int physicalAddress = frameNumber * PAGE_SIZE + pageOffset;
            printf("Logical Address %d: Page %d, Offset %d -> Frame %d, Physical Address %d\n",
                   logicalAddress, pageNumber, pageOffset, frameNumber, physicalAddress);
        }
    }
}

