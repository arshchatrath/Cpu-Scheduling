#include<iostream>
using namespace std;
// Function to find the waiting time for each process
int main(){
    int n, i, j, total = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n], pr[n];
    cout << "Enter the burst time for each process:\n";
    for (i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> bt[i];
    }
    cout << "Enter the priority for each process:\n";
    for (i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> pr[i];
    }
    // Sort processes by priority
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
            }
        }
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
    double avg = (double)total / n;
    cout << "\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << pr[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "\nAverage Turnaround Time: " << avg << endl;
    return 0;
}