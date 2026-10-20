#include <stdio.h> //printf(), perror()
#include <fcntl.h> //open(), O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h> //close(), write()
#include <string.h> //strlen()
int main() {
    //variable to store the result of the file descriptor
    int fd;

    //variable to store how much bytes actually written
    int bytes;
    
    //creating or opening file for writing, if file exists, the contents are erased
    fd = open("OS_Lab.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    //check whether the file created or not
    if(fd == -1){
        perror("Error: Unable to create the file.\n");
        return 1;
    } else {
        printf("File Created Successfully. Started Writting data.\n");
    }

    //message that is going to write into the file
    char message[] = "Linux System Call Experiment.\n"
                    "B.Sc Cyber Security Laboratory.\n";
    
    //bytes written to the file
    bytes = write(fd, message, strlen(message));

    if(bytes == -1){
        perror("Error: Unable to write to the file.\n");
        return 1;
    } else {
        printf("Data Written successfully.\n");
        printf("Bytes Written: %d bytes\n", bytes);
    }

    return 0;
}