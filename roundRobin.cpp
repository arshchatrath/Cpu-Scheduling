#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, quantum;
    // Input number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], rt[n], tat[n], wt[n]; // bt: burst time, rt: remaining time, tat: turnaround time, wt: waiting time

    // Input burst times for each process
    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i]; // Initialize remaining time
    }

    // Input time quantum
    cout << "Enter time quantum: ";
    cin >> quantum;

    int time = 0; // Current time
    bool done;
    // Round Robin Scheduling Loop
    do {
        done = true; // Assume all processes are done
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) { // If process is not finished
                done = false; // At least one process is left
                int exec = min(quantum, rt[i]); // Time to execute in this round
                time += exec; // Advance current time
                rt[i] -= exec; // Decrease remaining time
                if (rt[i] == 0)
                    tat[i] = time; // If finished, record turnaround time
            }
        }
    } while (!done); // Repeat until all processes are done

    // Calculate waiting time for each process
    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

    float total_wt = 0, total_tat = 0;
    // Output results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    // Output averages
    cout << "\nAverage Waiting Time: " << total_wt / n << endl;
    cout << "Average Turnaround Time: " << total_tat / n << endl;
    return 0;
}