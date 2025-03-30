#include <iostream>
#include <vector>
using namespace std;

struct Task {
    int id, arrival, duration, remaining, waitTime, turnTime, finishTime;
};

int main() {
    int numTasks, currentTime = 0, completedTasks = 0;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;
    vector<Task> tasks(numTasks);
    
    for (int i = 0; i < numTasks; i++) {
        tasks[i].id = i + 1;
        cin >> tasks[i].arrival >> tasks[i].duration;
        tasks[i].remaining = tasks[i].duration;
    }

    while (completedTasks < numTasks) {
        int index = -1;
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].arrival <= currentTime && tasks[i].remaining > 0 && 
                (index == -1 || tasks[i].remaining < tasks[index].remaining)) {
                index = i;
            }
        }
        if (index != -1) {
            tasks[index].remaining--;
            currentTime++;
            if (tasks[index].remaining == 0) {
                tasks[index].finishTime = currentTime;
                tasks[index].turnTime = currentTime - tasks[index].arrival;
                tasks[index].waitTime = tasks[index].turnTime - tasks[index].duration;
                completedTasks++;
            }
        } else {
            currentTime++;
        }
    }

    double totalWait = 0, totalTurn = 0;
    for (auto &task : tasks) {
        totalWait += task.waitTime;
        totalTurn += task.turnTime;
        cout << "Task " << task.id << " | Completion: " << task.finishTime 
             << " | Wait: " << task.waitTime << " | Turnaround: " << task.turnTime << endl;
    }
    cout << "Average Wait Time: " << totalWait / numTasks << endl;
    cout << "Average Turnaround Time: " << totalTurn / numTasks << endl;
}
