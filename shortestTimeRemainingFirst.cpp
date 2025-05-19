#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], remaining[n], completion[n];

    // Input arrival and burst times
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (arrival burst): ";
        cin >> arrival[i] >> burst[i];
        remaining[i] = burst[i]; // Initialize remaining time
    }

    int time = 0, completed = 0;

    // SRTF scheduling simulation
    while(completed < n) {
        int shortest = -1, min_rem = 1e9;
        // Find process with shortest remaining time at current time
        for(int i = 0; i < n; i++) {
            if(arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_rem) {
                min_rem = remaining[i];
                shortest = i;
            }
        }
        if(shortest == -1) { // No process is ready, advance time
            time++;
            continue;
        }
        remaining[shortest]--; // Execute for 1 time unit
        time++;
        if(remaining[shortest] == 0) { // If process finished
            completion[shortest] = time;
            completed++;
        }
    }

    // Calculate waiting and turnaround times
    float total_wt = 0, total_tat = 0;
    cout << "\nPID\tArrival\tBurst\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        int tat = completion[i] - arrival[i]; // Turnaround time
        int wt = tat - burst[i];              // Waiting time
        total_tat += tat;
        total_wt += wt;
        cout << i+1 << "\t" << arrival[i] << "\t" << burst[i]
             << "\t" << tat << "\t" << wt << endl;
    }

    // Output averages
    cout.precision(2);
    cout << "\nAverage Waiting Time: " << fixed << total_wt/n << endl;
    cout << "Average Turnaround Time: " << fixed << total_tat/n << endl;

    return 0;
}