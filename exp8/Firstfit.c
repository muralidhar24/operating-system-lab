#include <stdio.h>
#include <stdlib.h>
// Structure to represent a Partition
typedef struct {
    int size;       
    int isOccupied; 
    int processID;  
} 
Partition;
typedef struct 
{
    int processID;
    int size;
}
 Process;
void firstFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses);
void worstFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses);
void bestFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses);
void printPartitions(Partition partitions[], int numPartitions);

int main() 
{
    Partition partitions[] = 
{
        {100, 0, -1}, {200, 0, -1}, {300, 0, -1}, {150, 0, -1}, {250, 0, -1},
        {120, 0, -1}, {170, 0, -1}, {220, 0, -1}, {50, 0, -1}, {180, 0, -1}
    };
    Process processes[] = {
        {1, 120}, {2, 90}, {3, 180}, {4, 150}, {5, 60}, 
        {6, 110}, {7, 200}, {8, 130}
    };
    int numPartitions = sizeof(partitions) / sizeof(partitions[0]);
    int numProcesses = sizeof(processes) / sizeof(processes[0]);
    printf("First-Fit Allocation:\n");
    firstFit(partitions, numPartitions, processes, numProcesses);
    printPartitions(partitions, numPartitions);
    int i;
    for (i = 0; i < numPartitions; i++) {
        partitions[i].isOccupied = 0;
        partitions[i].processID = -1;
    }
    printf("\nWorst-Fit Allocation:\n");
    worstFit(partitions, numPartitions, processes, numProcesses);
    printPartitions(partitions, numPartitions);
    for (i = 0; i < numPartitions; i++) 
{
        partitions[i].isOccupied = 0;
        partitions[i].processID = -1;
    }
    printf("\nBest-Fit Allocation:\n");
    bestFit(partitions, numPartitions, processes, numProcesses);
    printPartitions(partitions, numPartitions);
    return 0;
}
// First Fit allocation
void firstFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses) 
{
	int i,j;
    for (i = 0; i < numProcesses; i++) 
{
        for (j = 0; j < numPartitions; j++)
 {
            if (partitions[j].isOccupied == 0 && partitions[j].size >= processes[i].size)
 {
                partitions[j].isOccupied = 1;
                partitions[j].processID = processes[i].processID;
                printf("Process %d allocated to Partition %d\n", processes[i].processID, j);
                break;
            }
        }
    }
}

// Worst Fit allocation
void worstFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses) 
{
	int i,j;
    for (i = 0; i < numProcesses; i++) 
{
        int worstIndex = -1;
        int maxDifference = -1;
        for (j = 0; j < numPartitions; j++)
 {
            if (partitions[j].isOccupied == 0 && partitions[j].size >= processes[i].size)
 {
                int difference = partitions[j].size - processes[i].size;
                if (difference > maxDifference)
 {
                    maxDifference = difference;
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) 
{
            partitions[worstIndex].isOccupied = 1;
            partitions[worstIndex].processID = processes[i].processID;
            printf("Process %d allocated to Partition %d\n", processes[i].processID, worstIndex);
        }
    }
}

// Best Fit allocation
void bestFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses)
 {
 	int i,j;
    for (i = 0; i < numProcesses; i++)
 {
        int bestIndex = -1;
        int minDifference = 999999; // Arbitrarily large value

        for (j = 0; j < numPartitions; j++) 
{
            if (partitions[j].isOccupied == 0 && partitions[j].size >= processes[i].size)
 {
                int difference = partitions[j].size - processes[i].size;
                if (difference < minDifference) {
                    minDifference = difference;
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            partitions[bestIndex].isOccupied = 1;
            partitions[bestIndex].processID = processes[i].processID;
            printf("Process %d allocated to Partition %d\n", processes[i].processID, bestIndex);
        }
    }
}

// Function to print the current status of all partitions
void printPartitions(Partition partitions[], int numPartitions) {
	int i;
    for (i = 0; i < numPartitions; i++) 
{
        if (partitions[i].isOccupied == 0)
 {
            printf("Partition %d: Free, Size %d\n", i, partitions[i].size);
        } 
else
 {
            printf("Partition %d: Occupied by Process %d, Size %d\n", i, partitions[i].processID, partitions[i].size);
        }
    }
}

