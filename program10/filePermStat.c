#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int main() {
    char file[100];

    struct stat fileInfo;

    printf("Enter the fileName: ");
    scanf("%s", file);

    if(stat(file, &fileInfo) == -1){
        perror("Error");
    }

    printf("File Size: %ld\n", fileInfo.st_size);
    printf("File Inode Number: %ld\n", fileInfo.st_ino);
    printf("Number of hard links: %ld\n", fileInfo.st_nlink);
    printf("User ID: %d\n", fileInfo.st_uid);
    printf("Group ID: %d\n", fileInfo.st_gid);
    printf("Owner Name: %s\n", getpwuid(fileInfo.st_uid)->pw_name);
    printf("Group Name: %s\n", getgrgid(fileInfo.st_gid)->gr_name);

    printf("Permission: ");

    printf(S_ISDIR(fileInfo.st_mode) ? "d" : "-");

    printf((fileInfo.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileInfo.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileInfo.st_mode & S_IXUSR) ? "x" : "-");

    printf((fileInfo.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileInfo.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileInfo.st_mode & S_IXGRP) ? "x" : "-");

    printf((fileInfo.st_mode & S_IROTH) ? "r" : "-");
    printf((fileInfo.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileInfo.st_mode & S_IXOTH) ? "x" : "-");
    
    printf("\n");

    printf("Last Access TIme: %s", ctime(&fileInfo.st_atime));
    printf("Last Modification Time: %s", ctime(&fileInfo.st_mtime));
    printf("Last Change Time: %s", ctime(&fileInfo.st_ctime));

    return 0;
}