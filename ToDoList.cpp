#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task t;
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, t.name);
    t.completed = false;

    tasks.push_back(t);
    cout << "Task added!\n";
}

void viewTasks() {
    if(tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for(int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;

        if(tasks[i].completed)
            cout << " [Done]";

        cout << endl;
    }
}

void completeTask() {
    int num;
    cout << "Enter task number to mark completed: ";
    cin >> num;

    if(num > 0 && num <= tasks.size()) {
        tasks[num-1].completed = true;
        cout << "Task marked completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask() {
    int num;
    cout << "Enter task number to delete: ";
    cin >> num;

    if(num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void searchTask() {
    string keyword;
    cin.ignore();
    cout << "Enter keyword to search: ";
    getline(cin, keyword);

    bool found = false;

    for(int i = 0; i < tasks.size(); i++) {
        if(tasks[i].name.find(keyword) != string::npos) {
            cout << i + 1 << ". " << tasks[i].name << endl;
            found = true;
        }
    }

    if(!found)
        cout << "No matching task found.\n";
}

void sortTasks() {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.name < b.name;
    });

    cout << "Tasks sorted alphabetically.\n";
}

int main() {

    int choice;

    do {
        cout << "\n====== TO DO LIST MANAGER ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Search Task\n";
        cout << "6. Sort Tasks (A-Z)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: completeTask(); break;
            case 4: deleteTask(); break;
            case 5: searchTask(); break;
            case 6: sortTasks(); break;
        }

    } while(choice != 7);

    cout << "Goodbye!\n";
}