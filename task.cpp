#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};


int main() {

    int choice;
    int taskNum;
    Task newTask;

    vector<Task> tasks;
    

    cout << "=== Welcome to MECH AI Your Personal AI Assistant ===" << endl;
    
    do {
        cout << "\n1. Add a Task\n2. View Tasks\n3. Complete a Task\n4. Exit\n";
        cout << "\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, newTask.description);
            newTask.completed = false;
            tasks.push_back(newTask);
            cout << "Task added successfully!" << endl;
        } 
        else if (choice == 2) {
            cout << "\nYour Tasks:" << endl;
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i].description 
                     << (tasks[i].completed ? " (Completed)" : " (Pending)") << endl;
            }
            if (tasks.empty()) cout << "No tasks yet" << endl;
        } 
        else if (choice == 3) {
            cout << "Enter task number to mark as completed: ";
            cin >> taskNum;
            if (taskNum > 0 && taskNum <= tasks.size()) {
                tasks[taskNum - 1].completed = true;
                cout << "Task completed!" << endl;
            } else {
                cout << "Invalid task number!" << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting MECH AI Assistant. Stay productive!" << endl;
        }
        else {
            cout << "Invalid option, Please try again!" << endl;
        }
    } while (choice != 4);

    return 0;
}