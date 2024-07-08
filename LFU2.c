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
        for(int a = 0; a < no_frame; a++) {
            if(frame[a] == req[i]) {
                avail = 1;
                freq[a]++;        // Increase the frequency of the page
                time[a] = i;      // Update the time of the page
                break;
            }
        }
        
        // If page is not in frame, find the least frequently used page to replace
        if(avail == 0) {
            int min_freq = freq[0], oldest = time[0];
            least = 0;
            for(int a = 1; a < no_frame; a++) {
                if(frame[a] == -1) {
                    least = a;   // Found an empty frame
                    break;
                } else if(freq[a] < min_freq || (freq[a] == min_freq && time[a] < oldest)) {
                    least = a;   // Find the page with minimum frequency and oldest time
                    min_freq = freq[a];
                    oldest = time[a];
                }
            }
            frame[least] = req[i];    // Replace the least frequently used page
            freq[least] = 1;          // Initialize the frequency of the new page
            time[least] = i;          // Set the time of the new page
            pgf++;                    // Increment page fault count
        }
        
        // Print current frames
        for(int a = 0; a < no_frame; a++) {
            printf("%d\t", frame[a]);
        }
        printf("\n");
    }
    
    // Output total page faults
    printf("No of page faults = %d\n", pgf);
}
