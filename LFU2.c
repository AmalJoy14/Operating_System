#include <stdio.h>

void main() {
    int no_frame, no_request, i, pgf = 0;
    
    // Input number of requests
    printf("Enter the number of requests\n");
    scanf("%d", &no_request);
    
    // Input number of frames
    printf("Enter the number of frames\n");
    scanf("%d", &no_frame);
    
    int frame[no_frame], req[no_request], freq[no_frame], time[no_frame];
    
    // Initialize frames, frequency, and time arrays
    for(i = 0; i < no_frame; i++) {
        frame[i] = -1;  // -1 indicates frame is empty
        freq[i] = 0;     // Frequency of each frame
        time[i] = 0;     // Time when each frame was last used
    }
    
    // Input requests
    printf("Enter the requests:\n");
    for(i = 0; i < no_request; i++) {
        scanf("%d", &req[i]);
    }
    
    // Page replacement simulation
    printf("Page replacement:\n");
    for(i = 0; i < no_request; i++) {
        int avail = 0, least = 0;
        printf("%d :", req[i]);
        
        // Check if page is already in frame
        for(int j = 0; j < no_frame; j++) {
            if(frame[j] == req[i]) {
                avail = 1;
                freq[j]++;        // Increase the frequency of the page
                time[j] = i;      // Update the time of the page
                break;
            }
        }
        
        // If page is not in frame, find the least frequently used page to replace
        if(avail == 0) {
            int min_freq = freq[0], oldest = time[0];
            least = 0;
            for(int j = 1; j < no_frame; j++) {
                if(frame[j] == -1) {
                    least = j;   // Found an empty frame
                    break;
                } else if(freq[j] < min_freq || (freq[j] == min_freq && time[j] < oldest)) {
                    least = j;   // Find the page with minimum frequency and oldest time
                    min_freq = freq[j];
                    oldest = time[j];
                }
            }
            frame[least] = req[i];    // Replace the least frequently used page
            freq[least] = 1;          // Initialize the frequency of the new page
            time[least] = i;          // Set the time of the new page
            pgf++;                    // Increment page fault count
        }
        
        // Print current frames
        for(int j = 0; j < no_frame; j++) {
            printf("%d\t", frame[j]);
        }
        printf("\n");
    }
    
    // Output total page faults
    printf("No of page faults = %d\n", pgf);
}
