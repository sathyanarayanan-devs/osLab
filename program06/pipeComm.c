#include <stdio.h> //printf(), perror()
#include <unistd.h> //open(), fork(), write(), read(), close()
#include <string.h> //strlen()
#include <sys/types.h> //pid_t
int main() {
    //file descriptor for the pipe to create write and read ends
    int fd[2];
    
    //variable to store process ID
    pid_t pid;

    //creating a memory buffer to temperarly hold the characters
    char buffer[100];

    //variable to store the messsage written in the pipe 
    char message[] = "Hello From Parent Process.";

    //creating pipe
    //f[0] = read end used by child process; f[1] = write end used by the parent process
    if(pipe(fd) == -1){
        perror("Error: Unable to create a pipe.");
        return 1;
    }

    //creating a child process
    pid = fork();

    //checking whether the child process is created
    if(pid < 0){
        perror("Error: Unable to create the child process.\n");
        return 1;
    } else if (pid == 0) {
        //child Process
        //closing the write end
        close(fd[1]);

        //actual bytes read from the pipe's read end
        int bytes = read(fd[0], buffer, sizeof(buffer));

        //marking the last byte as the null terminator, so the child process can read only upto the string stored in the pipe
        buffer[bytes] = '\0';

        //displaying the contents in the read end
        printf("Child Process Reads: \"%s\"\n", buffer);

        //closing the read end to release resources
        close(fd[0]);
    } else {
        //Parent process
        //closing the read end
        close(fd[0]);

        //write the contents into the pipe
        write(fd[1], message, strlen(message)+1);

        //displaying a confimationn message
        printf("Parent process writes the message in the pipe.\n");

        //closing the write end of the pipe
        close(fd[1]);
    }

    return 0;
}