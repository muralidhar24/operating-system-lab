 #include <stdio.h>
#include <pthread.h>
#include <unistd.h>
typedef struct 
{
    int availablePorts;
    pthread_mutex_t lock;
    pthread_cond_t condition;
} 
PortMonitor;
void initializeMonitor(PortMonitor *monitor, int maxPorts)
 {
    monitor->availablePorts = maxPorts;
    pthread_mutex_init(&monitor->lock, NULL);
    pthread_cond_init(&monitor->condition, NULL);
}

void openPort(PortMonitor *monitor, int threadId) 
{
    pthread_mutex_lock(&monitor->lock);
    while (monitor->availablePorts == 0) 
{
        printf("Thread %d is waiting for a port...\n", threadId);
        pthread_cond_wait(&monitor->condition, &monitor->lock);
    }
    monitor->availablePorts--;
    printf("Thread %d has opened a port. Available ports: %d\n", threadId, monitor->availablePorts);
    pthread_mutex_unlock(&monitor->lock);
}
void closePort(PortMonitor *monitor, int threadId)
 {
    pthread_mutex_lock(&monitor->lock);
    monitor->availablePorts++;
    printf("Thread %d has closed a port. Available ports: %d\n", threadId, monitor->availablePorts);
    pthread_cond_broadcast(&monitor->condition);
    pthread_mutex_unlock(&monitor->lock);
}
void *portUser(void *arg) {
    int threadId = *(int *)arg;
    extern PortMonitor monitor;
    openPort(&monitor, threadId);
    sleep(2); // Simulate using the port
    closePort(&monitor, threadId);
    return NULL;
}
// Global monitor object
PortMonitor monitor;
int main()
 {
    int maxPorts = 3; // Maximum number of ports
    int totalThreads = 5; // Number of threads (users)
    pthread_t threads[totalThreads];
    int threadIds[totalThreads];
    initializeMonitor(&monitor, maxPorts);
	int i;
    // Create threads to simulate port usage
    for (i = 0; i < totalThreads; i++) 
{
        threadIds[i] = i + 1;
        pthread_create(&threads[i], NULL, portUser, &threadIds[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < totalThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the monitor
    pthread_mutex_destroy(&monitor.lock);
    pthread_cond_destroy(&monitor.condition);

    return 0;
}
