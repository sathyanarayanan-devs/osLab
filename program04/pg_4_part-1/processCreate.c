#include <stdio.h> //printf(), perror()
#include <unistd.h> //getpid(), getppid()
#include <sys/types.h> //pid_t
int main() {
    //variable to store process id
    pid_t pid;

    //creating a child process from the parent process using fork()
    pid = fork();

    //check whether the child process is created
    if(pid < 0){
        perror("Error: child process creation failed.\n");
        return 1;
    } else if (pid == 0) { //child process
        printf("==== Child Process ====\n");
        printf("1. Child Process ID: %d\n", getpid());
        printf("2. Parent Process ID: %d\n", getppid());
        printf("=======================\n");
    } else { //parent process
        printf("==== Parent Process ====\n");
        printf("1. Parent Process: %d\n2. Child Process: %d\n", getpid(), pid);
        printf("========================\n");
    }

    return 0;
}