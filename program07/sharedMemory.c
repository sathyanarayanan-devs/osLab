#include <stdio.h> //printf(), perror(), sprintf()
#include <stdlib.h>
#include <string.h> //strlen()
#include <fcntl.h> //shm_open(), O_CREAT, O_RDWR, open()
#include <sys/mman.h> //mmap(), munmap(), PROT_READ, PROT_WRITE, shm_unlink()
#include <sys/unistd.h> //write(), read(), close(), ftruncate()
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait()
int main(){
    //shared memory region name
    const char *name = "/my_shm";

    //shared memory size
    const int SIZE = 4096;

    //creating variables for shm descriptor, and ptr for addressing the shm
    int shm_fd;
    void *ptr;

    //opening a shm object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    //check whether the shm descriptor is created or not
    if(shm_fd < 0){
        perror("Error: Unable to create shared memory Descriptor.\n");
        return 1;
    } else {
        printf("Success: Created shared memory descriptor.\n");
    }

    //set the size of the shm object
    if(ftruncate(shm_fd, SIZE) < 0){
        perror("Error: Unable to set the shared memory size.\n");
        return 1;
    } else {
        printf("Success: Shared Memory Size is set\n");
    }

    //mapping the shm object to the virtual memory
    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    //check if the mapping is completed or not
    if(ptr == MAP_FAILED){
        perror("Error: Unable to map shm to the virtual memory.\n");
        return 1;
    } else {
        printf("Success: Shared memory object is mapped to the virtual memory\n");
    }

    //variable to store the process id of the parent process
    pid_t pid;

    //creating a new process (child) process
    pid = fork();

    //check whether the child process is created
    if(pid < 0){
        perror("Error: Child creation failed.\n");
        return 1;
    } else if (pid == 0) {
        printf("====== Child Process ======\n");

        //display the message from the shared message
        printf("Child Process: Reads from the shared memory: \"%s\"\n", (char *)ptr);

        //unmaps the child process from the shared memory
        munmap(ptr, SIZE);

        //close the shm object
        close(shm_fd);
    } else {
        printf("====== Parent Process ======\n");

        //data which is going to be written in the shared memory
        char *message = "Hello world from Parent Process.";

        //copies the data to the shared memory
        sprintf(ptr, "%s", message);

        //displays a message in terminal
        printf("Parent Process: Writes to the shared memory: \"%s\"\n", message);

        //unmaps the parent process from the shared memory
        munmap(ptr, SIZE);

        //remove the shared memory object and release the resources
        shm_unlink(name);

        //close the shm object descriptor
        close(shm_fd);
    }

    return 0;
}