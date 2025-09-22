#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

struct Date {
    int day, month, year;
    
    string toString() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << day << "/" 
           << setfill('0') << setw(2) << month << "/" 
           << year;
        return ss.str();
    }
};

struct Task {
    string description;
    bool completed;
    Date dueDate;
};

bool isValidDate(int day, int month, int year) {
    if (year < 2024 || month < 1 || month > 12 || day < 1) return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29;
    }
    
    return day <= daysInMonth[month - 1];
}

Date inputDate() {
    Date date;
    do {
        cout << "Enter due date (DD MM YYYY): ";
        cin >> date.day >> date.month >> date.year;
        
        if (!isValidDate(date.day, date.month, date.year)) {
            cout << "Invalid date! Please enter a valid date (DD MM YYYY)." << endl;
        }
    } while (!isValidDate(date.day, date.month, date.year));
    
    return date;
}

int main() {

    int choice;
    int taskNum;
    Task newTask;

    vector<Task> tasks;
    

    cout << "=== Welcome to MECH AI Your Personal AI Assistant ===" << endl;
    
    do {
        cout << "\n1. Add a Task\n2. View Tasks\n3. Complete a Task\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task and due date: ";
            cin.ignore();
            getline(cin, newTask.description);
            newTask.completed = false;
            newTask.dueDate = inputDate();
            tasks.push_back(newTask);
            cout << "Task added successfully with due date: " << newTask.dueDate.toString() << endl;
        } 
        else if (choice == 2) {
            cout << "\nYour Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i].description 
                     << " | Due: " << tasks[i].dueDate.toString()
                     << (tasks[i].completed ? " (Completed)" : " (Pending)") << endl;
            }
            if (tasks.empty()) cout << "No tasks yet" << endl;
        } 
        else if (choice == 3) {
            cout << "Enter task number to mark as completed: ";
            cin >> taskNum;
            if (taskNum > 0 && static_cast<size_t>(taskNum) <= tasks.size()) {
                tasks[static_cast<size_t>(taskNum) - 1].completed = true;
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