#include <stdio.h> //printf() perror()

//structure datatype to hold the process info
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

//main function
int main() {
    //variable to store number of process
    int n;

    //variable to store the total turnaround and waiting time
    float total_tat = 0, total_wt = 0;

    //getting number of processes from the user
    printf("Enter number of processes: ");
    scanf("%d", &n);

    //check if the input for n is valid
    if(n <= 0){
        perror("Error: Invalid number of processes.\n");
        return 1;
    }

    //creating the process object
    struct Process p[n];

    //getting input for arrival time and burst time 
    for(int i=0; i<n; i++){
        p[i].id = (i+1);

        //use input
        printf("Enter arrival and burst time for the process - %d: ", p[i].id);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    //sort the processes in order of their arrival time (Bubble Sort)
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    //calculating the CPU Schedueling metrics
    int current_time = 0;
    for(int i=0; i<n; i++){
        //check if the cpu is ideal and change the time to the arrival of the next process
        if(current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        //cpu schedueling metrics: Completion, Turnaround, Waiting time
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

        //to get the total work time of the cpu
        current_time = p[i].completion_time;
    }

    //Output Matrix of the cpu metrics
    printf("%-10s %-10s %-10s %-12s %-12s %-10s\n", "Process", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");

    for(int i=0; i<n; i++){
        printf("%-10d %-10d %-10d %-12d %-12d %-10d\n", 
            p[i].id,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].completion_time,
            p[i].turnaround_time,
            p[i].waiting_time
        );
    }

    printf("Program Completed successfully\n");
    return 0;
}