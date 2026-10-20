#include <stdio.h> //printf()
#include <signal.h> //signal(), raise(), SIGINT
#include <unistd.h> //getpid()

//function to capture and display the signal number
void signalHandler(int signal_number){
    printf("Signal received from the process\n");
    printf("Signal Number: %d\n", signal_number);
}

//Main Function
int main() {
    //Using the signal() method to capture and send the signal number to the custom signal handler
    //SIGINT: signal Interrupt, a process getting interrupted while execution like pressing Ctrl + C
    signal(SIGINT, signalHandler);

    printf("ID of the Current running Process: %d\n", getpid());

    //Using the raise() method to generate a SIGINT and send it to the signal() method
    printf("Generating a SIGINT using the raise() method\n");
    raise(SIGINT);

    printf("Program Completed Successfully\n");

    return 0;
}
