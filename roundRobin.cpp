#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], rt[n], tat[n], wt[n];
    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i]; // Initialize remaining time
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    int time = 0, completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                int exec = min(quantum, rt[i]);
                time += exec;
                rt[i] -= exec;
                if (rt[i] == 0) {
                    tat[i] = time;
                    completed++;
                }
            }
        }
    }

    // Calculate waiting time for each process
    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

    float total_wt = 0, total_tat = 0;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "\nAverage Waiting Time: " << total_wt / n << endl;
    cout << "Average Turnaround Time: " << total_tat / n << endl;
    return 0;
}