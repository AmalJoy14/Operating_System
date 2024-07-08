#include <stdio.h>

void main() {
    int no_frame, no_request, i, pgf = 0, k = 0;
    
    // Input the number of page requests
    printf("Enter the number of requests\n");
    scanf("%d", &no_request);
    
    // Input the number of frames available in memory
    printf("Enter the number of frames\n");
    scanf("%d", &no_frame);
    
    int frame[no_frame], req[no_request];
    
    // Initialize all frames to -1 indicating they are empty
    for (i = 0; i < no_frame; i++)
        frame[i] = -1;
    
    // Input the page requests
    printf("Enter the requests:\n");
    for (i = 0; i < no_request; i++) {
        scanf("%d", &req[i]);
    }
    
    // Begin page replacement process
    printf("Page replacement:\n");
    for (i = 0; i < no_request; i++) {
        int avail = 0; // Flag to check if the page is already in a frame
        printf("%d :", req[i]);
        
        // Check if the requested page is already in any of the frames
        for (int j = 0; j < no_frame; j++) {
            if (frame[j] == req[i]) {
                avail = 1; // Page is found in the frame
                break;
            }
        }
        
        // If the page is not found in any frame, replace the oldest page (FIFO)
        if (avail == 0) {
            frame[k] = req[i]; // Replace the page in the frame
            k = (k + 1) % no_frame; // Move to the next frame in a circular manner
            pgf++; // Increment the page fault count
        }
        
        // Print the current state of frames
        for (int j = 0; j < no_frame; j++) {
            printf("%d\t", frame[j]);
        }
        printf("\n");
    }
    
    // Output the total number of page faults
    printf("No of page faults = %d\n", pgf);
}
