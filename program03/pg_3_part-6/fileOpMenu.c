#include <stdio.h> //printf(), perror(), fgets(), getchar(), scanf()
#include <stdlib.h> //exit(0)
#include <fcntl.h> //O_CREAT, O_RDONLY, O_WRONLY, O_TRUNC, O_APPEND
#include <unistd.h> //open(), close(), read(), write()
#include <string.h> //strlen()
#include <ctype.h> //tolower()
#include <sys/types.h> //ssize_t

//Defining Macros for the sample file and the buffer size
#define FILE_NAME "Sample.txt"
#define BUFFER_SIZE 1024

//Function to Write to file
void writeToFile() {
    int fd; //file descriptor to handle the file operations
    char buffer[BUFFER_SIZE]; //create a memory buffer to temporarly store the data and write it in file
    ssize_t bufferWritten; //this will used to set the size of the actual characters that are going to written in a file
    char choice; //decision to store the contents in new file or append to existing file

    printf("Would you want to override the file (Y/N):");
    scanf("%s", &choice);

    if(tolower(choice) == 'y'){
        //open a file and erase the existing content or create new file
        fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    } else {
        //open a file and append the content
        fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_APPEND, 0666);
    }

    //check if the file exists
    if(fd < 0){
        perror("Error: File creation failed.\n");
        return ;
    }

    //Get the input to write into the file
    printf("Enter the content to write into the file: ");
    getchar();
    if(fgets(buffer,BUFFER_SIZE,stdin) < 0){
        perror("Error: Unable to read the input.\n");
        return ;
    }

    //writing to the file
    bufferWritten = write(fd, buffer, BUFFER_SIZE);
    if(bufferWritten < 0){
        perror("Error: Unable to write contents into the file\n");
        return ;
    } else {
        printf("Data written Successfully.\n");
    }

    //closing the file descriptor
    close(fd);
}

//Function to read contents from the file
void readFromFile(){
    int fd; //file descriptor to handle communication with the file
    char buffer[BUFFER_SIZE]; //memory to hold for the characters from the file 
    ssize_t bufferRead; //actual number of bytes read from the file

    //opening the file for read-only purpose
    fd = open(FILE_NAME, O_RDONLY);

    //check whether the file is opened or not
    if(fd < 0){
        perror("Error: unable to open the file");
        return ;
    }

    //reading character bytes from the file
    while((bufferRead = read(fd, buffer, BUFFER_SIZE)) > 0){
        buffer[bufferRead] = '\0';
        printf("%s\n", buffer);
    }

    //check if the file contents are retrieved
    if(bufferRead < 0){
        perror("Error: Unable to read contents from the file\n");
        return ;
    }

    //closing the file descriptor
    close(fd);
}

//Main Function
int main(){
    int choice;
    do{
        //Menu
        printf("====== File Operations Menu ======\n");
        printf("1. Write to File\n2. Read from File\n3. Exit the program\n");
        printf("==================================\n");

        //Input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //switch case to call the 2 methods on user's choice
        switch(choice) {
            case 1:
                printf("==== Writing to the File ====\n");
                writeToFile(); //calling the function to write to file
                printf("=============================\n");
                break;

            case 2:
                printf("==== Reading from the File ====\n");
                readFromFile(); //calling the function to read from file
                printf("===============================\n");
                break;

            case 3:
                printf("Exiting the Program.\n");
                exit(0); //this will immediately end the program and exits

            default:
                perror("Error: Invalid Input");
        }
    }while(choice != 3); //The program will run until user wants to exit

    return 0;
}