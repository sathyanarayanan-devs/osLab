#include <stdio.h> //printf(), perror()
#include <dirent.h> //struct dirent, opendir(), readdir(), closedir()
#include <sys/stat.h> //mkdir()
int main(){
    DIR *dir; // directory stream
    struct dirent *entry; //one entry to access the directory contents

    printf("========= Directory Operations ==========\n");
    //creating a new directory using system call mkdir()
    if(mkdir("TestDirectory", 0777) == 0){
        printf("Directory Created successfully.\n");
    } else {
        perror("Error: Unable to create Directory or the Direcotory may already exists\n");
        return 1;
    }

    //using the directory stream to open the current directory
    dir = opendir(".");

    //check if the directory is opened to access
    if(dir == NULL){
        perror("Error: Unable to open the directory\n");
        return 1;
    }

    printf("--- Displaying the directory contents ---\n");

    //displaying the contents of the direcory using the dirent structure object
    while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    printf("--- Directory Operation completed ---\n");

    return 0;
}