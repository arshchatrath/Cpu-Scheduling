#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n], pid[n];

    // Input burst times and assign process IDs
    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> bt[i];
        pid[i] = i + 1;
    }

    // Sort processes by burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    float totalTat = 0;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalTat += tat[i];
        cout << "P" << pid[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Turnaround Time: " << totalTat / n << endl;
    return 0;
}