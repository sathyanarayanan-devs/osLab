#include <stdio.h> //printf(), perror()
#include <fcntl.h> //O_CREAT, O_WRONLY
#include <unistd.h> //open(), write()
#include <string.h> //strlen()
int main() {
    int fd; //file descriptor
    char data[] = "Linux System call Experiment\n"
            "B.Sc CyberSecurity Laboratory\n";
    
    printf("===== Creating and writing data to a file =====\n");

    fd = open("Test.txt", O_CREAT | O_WRONLY, 0666);

    if(fd < 0){
        perror("Error: Unable to create a file");
        return 1;
    }

    write(fd, data, strlen(data));

    printf("====== Data written successfully ======\n");

    close(fd);

    return 0;
}