#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], remaining[n], completion[n], tat[n], wt[n];

    // Input process details
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (arrival burst): ";
        cin >> arrival[i] >> burst[i];
        remaining[i] = burst[i];
    }

    int time = 0, completed = 0;

    // Simulation loop
    while(completed < n) {
        int shortest = -1;
        int min_remaining = 9999;

        // Find process with shortest remaining time
        for(int i = 0; i < n; i++) {
            if(arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_remaining) {
                min_remaining = remaining[i];
                shortest = i;
            }
        }

        if(shortest == -1) {
            time++;
            continue;
        }

        // Execute process for 1 time unit
        remaining[shortest]--;
        time++;

        // Process completed
        if(remaining[shortest] == 0) {
            completion[shortest] = time;
            completed++;
        }
    }

    // Calculate metrics
    float total_wt = 0, total_tat = 0;
    for(int i = 0; i < n; i++) {
        tat[i] = completion[i] - arrival[i];
        wt[i] = tat[i] - burst[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display results
    cout << "\nPID\tArrival\tBurst\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << i+1 << "\t" << arrival[i] << "\t" << burst[i] 
             << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    cout << fixed;
    cout.precision(2);
    cout << "\nAverage Waiting Time: " << total_wt/n << endl;
    cout << "Average Turnaround Time: " << total_tat/n << endl;

    return 0;
}