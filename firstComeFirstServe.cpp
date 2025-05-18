#include<iostream>
using namespace std;

int main() {
    int n, i, j, total = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n];
    cout << "Enter the burst time for each process:\n";
    for (i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> bt[i];
    }
    
    // Calculate waiting time
    wt[0] = 0; // Waiting time for first process is 0
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
    
    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    
    // Calculate average turnaround time
    float avgTat = (float)total / n;
    
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    
    cout << "\nAverage Turnaround Time: " << avgTat << endl;
    
    return 0;
}