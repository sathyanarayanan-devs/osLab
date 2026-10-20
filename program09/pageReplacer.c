#include <stdio.h> //printf(), scanf()
int main() {
    int pages[100], frames[50]; //variable to store the pages and frames with a default size
    int n, f; //variable to store the number of pages and frames
    int pageFault = 0, index = 0, found; //variable to store the page fault counter, ptr for frames (FIFO), flag for page hit

    //input for number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    //input for page content
    printf("Enter page reference string: ");
    for(int i=0; i<n; i++){
        scanf("%d", &pages[i]);
    }

    //input for number of frames
    printf("Enter number of available frames: ");
    scanf("%d", &f);

    //initialize frames as empty
    for(int j=0; j<f; j++){
        frames[j] = -1;
    }

    //displaying headings
    printf("Pages \t Frames \n");

    for(int i=0; i<n; i++){
        //assuming page hit not found
        found = 0;

        //check if the page already exists
        for(int j=0; j<f; j++){
            if(frames[j] == pages[i]){
                found = 1;
                break;
            }
        }

        //if page doesnt found already
        if(!found){
            //using fifo to replace the old page
            frames[index] = pages[i];

            //move the ptr to next frame
            index = (index + 1) % f;

            //increase the page Fault counter
            pageFault++;
        }

        //displaying the pages
        printf("%d \t ", pages[i]);

        //diplaying the frames
        for(int j=0; j<f; j++){
            //frame is empty
            if(frames[j] == -1){
                printf("- ");
            } else { //frame is occupied
                printf("%d ", frames[j] );
            }
        }

        //display page fault or hit message
        if(!found){
            printf(" (Page Fault)\n");
        } else {
            printf(" (Page Hit)\n");
        }
    }

    //displaying the total page fault and hits
    printf("Total Page Faults = %d\n", pageFault);

    //page hit = n - pageFault
    printf("Total Page Hit = %d\n", (n-pageFault));

    return 0;
}