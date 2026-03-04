   #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
// Thread function
void *printMessage(void *arg) 
{
    int threadId = *(int *)arg;
    printf("Thread %d: Starting execution\n", threadId);
    printf("Thread %d: Finishing execution\n", threadId);
    return NULL;
}

int main()
 {
    const int numThreads = 5; // Number of threads to create
    pthread_t threads[numThreads];
    int threadIds[numThreads];
    int i;
    for (i = 0; i < numThreads; i++) 
{
        threadIds[i] = i + 1;
        if (pthread_create(&threads[i], NULL, printMessage, &threadIds[i]) != 0)
 {
            perror("Failed to create thread");
        }
        printf("Main: Thread %d has been created\n", threadIds[i]);
    }
    // Wait for all threads to complete
    for (i = 0; i < numThreads; i++) 
{
        pthread_join(threads[i], NULL);
        printf("Main: Thread %d has completed\n", threadIds[i]);
    }
    printf("Main: All threads have finished execution\n");
    return 0;
}

