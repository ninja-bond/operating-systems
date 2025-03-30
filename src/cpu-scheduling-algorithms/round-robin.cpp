#include <iostream>
using namespace std;

void calculateWaitTime(int tasks[], int count, int duration[], int waitTime[], int timeSlice) {
    int remaining[count];
    for (int i = 0; i < count; i++)
        remaining[i] = duration[i];

    int timeElapsed = 0;

    while (true) {
        bool allDone = true;

        for (int i = 0; i < count; i++) {
            if (remaining[i] > 0) {
                allDone = false;

                if (remaining[i] > timeSlice) {
                    timeElapsed += timeSlice;
                    remaining[i] -= timeSlice;
                } else {
                    timeElapsed += remaining[i];
                    waitTime[i] = timeElapsed - duration[i];
                    remaining[i] = 0;
                }
            }
        }

        if (allDone)
            break;
    }
}

void calculateTurnaroundTime(int tasks[], int count, int duration[], int waitTime[], int turnTime[]) {
    for (int i = 0; i < count; i++)
        turnTime[i] = duration[i] + waitTime[i];
}

void calculateAverageTime(int tasks[], int count, int duration[], int timeSlice) {
    int waitTime[count], turnTime[count], totalWait = 0, totalTurn = 0;

    calculateWaitTime(tasks, count, duration, waitTime, timeSlice);
    calculateTurnaroundTime(tasks, count, duration, waitTime, turnTime);

    cout << "Task\tDuration\tWait Time\tTurnaround Time\n";

    for (int i = 0; i < count; i++) {
        totalWait += waitTime[i];
        totalTurn += turnTime[i];
        cout << " " << i + 1 << "\t\t" << duration[i] << "\t " << waitTime[i] << "\t\t " << turnTime[i] << endl;
    }

    cout << "Average Wait Time: " << (float)totalWait / count << endl;
    cout << "Average Turnaround Time: " << (float)totalTurn / count << endl;
}

int main() {
    int tasks[] = {1, 2, 3};
    int count = sizeof tasks / sizeof tasks[0];

    int durations[] = {10, 5, 8};
    int timeSlice = 2;

    calculateAverageTime(tasks, count, durations, timeSlice);
    return 0;
}
