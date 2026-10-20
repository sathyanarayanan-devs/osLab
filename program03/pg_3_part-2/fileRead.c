#include <stdio.h> //printf()
#include <fcntl.h> //O_RDONLY
#include <unistd.h> //open() and read()
int main() {
    int fd; //file descriptor
    char buffer[100]; //memory to hold the text read from the file
    int bytes; //number of bytes actually read from the file

    printf("======= Reading contents from the file =====\n");

    fd = open("Text.txt", O_RDONLY);

    if(fd < 0){
        perror("Error: Unable to open the file");
        return 1;
    }

    bytes = read(fd, buffer, sizeof(buffer)-1);
    if(bytes < 0){
        perror("Error: Unable to read the text content from the file");
        return 1;
    }

    //manually giving a null terminator at the end of the buffer to stop if the character length is smallaer than the buffer size
    buffer[bytes] = '\0'; 

    printf("%s\n", buffer);

    printf("====== Data read from the file successfully=======\n");

    //closing the file descriptor
    close(fd);

}