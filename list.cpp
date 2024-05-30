#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description); 
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].isCompleted ? "[Completed] " : "[Pending] ") << tasks[i].description << "\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    cin.ignore(); 
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true; 
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    cin.ignore(); 
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1); 
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void showMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<Task> tasks; 
    int choice;
    do {
        showMenu(); 
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                addTask(tasks); 
                break;
            case 2:
                viewTasks(tasks); 
                break;
            case 3:
                markTaskCompleted(tasks); 
                break;
            case 4:
                removeTask(tasks); 
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5); 
    
    return 0;
}