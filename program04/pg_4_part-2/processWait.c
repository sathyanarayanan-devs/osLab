#include <stdio.h> //print(), perror()
#include <unistd.h> //getpid()
#include <sys/wait.h> //wait()
#include <sys/types.h> //pid_t
int main() {
    //create a variable to store the process ID
    pid_t pid;

    //creating a child process from the parent process
    pid = fork();

    //check whether the child process is created or not
    if(pid < 0){
        perror("Error: Unable to create a child process");
        return 1;
    } else if(pid == 0) {
        printf("==== Child Process ====\n");
        printf("Child Process ID: %d\n", getpid());

        //child process will pause for 3 seconds and complete the process
        sleep(3);

        printf("Child Process completed.\n");
        printf("========================\n");
    } else {
        printf("Parent process is waiting for the child process to complete\n");

        //parent process will wait for the child process to complete
        wait(NULL);

        printf("==== Parent Process ====\n");
        printf("Process process: %d\n", getpid());
        printf("Parent process resumed.\n");
        printf("=========================\n");
    }

    return 0;
}