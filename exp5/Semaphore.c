#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_PORTS 3 // Maximum number of ports that can be opened concurrently
sem_t port_semaphore; // Semaphore to control port access
void *use_port(void *arg) 
{
    int thread_id = *(int *)arg;
    printf("Thread %d: Waiting to open a port...\n", thread_id);
    sem_wait(&port_semaphore); // Decrement semaphore
    printf("Thread %d: Port opened. Using port...\n", thread_id);
    printf("Thread %d: Done. Closing port...\n", thread_id);
    sem_post(&port_semaphore); // Increment semaphore
    return NULL;
}

int main()
 {
    pthread_t threads[5];
    int thread_ids[5];   
	sem_init(&port_semaphore, 0, MAX_PORTS);
	int i;
    for(i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, use_port, &thread_ids[i]);
    }
    for (i = 0; i < 5; i++) 
{
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&port_semaphore);
    return 0;
}

