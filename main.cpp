#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ToDoList {
private:
    vector<string> tasks;
public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << task << endl;
    }
    void showTasks() const {
        if (tasks.empty())
            cout << "No Tasks" << endl;
        else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }
    void removeTask(int ind) {

            if (ind <1 || ind > tasks.size())
                cout << "Invalid Index" << endl;
            else {
                cout << "Removing Task" << endl;
                tasks.erase(tasks.begin()+ind-1);
            }
        }

};
int main() {
    ToDoList todo;
    int choice;
    do {
        cout << "\n=== To-Do List ==="<< endl;
        cout << "1. Add Task" << endl;
        cout << "2. Show Task" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter Task Name" << endl;
                string task;
                getline(cin, task);
                todo.addTask(task);
                break;
            }
            case 2: {
                todo.showTasks();
                break;
            }
            case 3: {
                cout << "Enter Task's number you want to delete" << endl;
                int taskIndex;
                cin >> taskIndex;
                todo.removeTask(taskIndex);
                break;
            }
            case 4: {
                cout << "Bye." << endl;
                break;
                default:
                    cout << "Invalid Choice" << endl;
            }
        }

    }while (choice != 4);
    return 0;
}
