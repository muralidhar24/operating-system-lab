#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        execlp("ls", "ls", "-l", NULL); // Execute `ls -l`
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for the child process to finish
    } else {
        perror("Fork failed");
    }
    return 0;
}

