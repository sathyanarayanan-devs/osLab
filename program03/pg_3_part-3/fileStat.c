#include <stdio.h> //printf(), perror()
#include <sys/stat.h> //struct stat, stat()
int main(){
    int fd; //file descriptor
    struct stat fileInfo; //stat structure to store the metadata of the file

    printf("========= Getting the information of the file ===========\n");
    //check whether the stat() method can get the file's metadata
    if(stat("Test.txt", &fileInfo) == 0){
        printf("1. File Size: %ld bytes \n", fileInfo.st_size);
        printf("2. Number of Hard Links: %ld\n", fileInfo.st_nlink);
        printf("3. File Permissions: %o\n", fileInfo.st_mode);
        printf("==========================================================\n");
    } else {
        perror("Error: Unable to get the information of the file.\n");
        printf("==========================================================\n");
    }

    return 0;
}
