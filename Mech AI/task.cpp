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

void printTasks(const vector<Task>& tasks) {
    cout << "\nYour Tasks:" << endl;
    if (tasks.empty()) {
        cout << "No tasks" << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description 
             << " | Due: " << tasks[i].dueDate.toString()
             << (tasks[i].completed ? " (Completed)" : " (Pending)") << endl;
    }
}

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
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, newTask.description);
            newTask.completed = false;
            newTask.dueDate = inputDate();
            tasks.push_back(newTask);
            cout << "Task added successfully with due date: " << newTask.dueDate.toString() << endl;
        } 
        else if (choice == 2) {
            printTasks(tasks);
        } 
        else if (choice == 3) {
            // Show the current tasks first
            printTasks(tasks);
            if (!tasks.empty()) {
                while (true) {
                    cout << "Enter task number to mark as completed: ";
                    cin >> taskNum;
                    if (cin.fail()) {
                        cout << "Invalid input! Please enter a number." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        // Reprint tasks for clarity before retry
                        printTasks(tasks);
                        continue;
                    }
                    if (taskNum > 0 && static_cast<size_t>(taskNum) <= tasks.size()) {
                        tasks[static_cast<size_t>(taskNum) - 1].completed = true;
                        cout << "Task completed!" << endl;
                        break;
                    } else {
                        cout << "Invalid task number! Please choose between 1 and " << tasks.size() << "." << endl;
                        // Reprint tasks for clarity before retry
                        printTasks(tasks);
                    }
                }
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