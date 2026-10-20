#include <stdio.h> //printf()
#include <stdlib.h> //system()
int main() {
    printf("=== Present Working Directory ===\n");
    system("pwd");

    printf("=== Listing the file ===\n");
    system("ls -l");

    printf("=== Creating a new Directory ===\n");
    system("mkdir Demo");

    printf("=== Listing the files again ===\n");
    system("ls");

    printf("=== Removing the new Directory ===\n");
    system("rmdir Demo");

    return 0;
}