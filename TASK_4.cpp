#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task{
    string descr;
    bool completed;

    Task(string descrTask) : descr(descrTask), completed(false) {}
};

void addTask(vector<Task>& tasks){     // Function to add a task to the list
    cout<< "Enter the task descr: ";
    string descr;
    getline(cin, descr);
    tasks.push_back(Task(descr));
    cout<< "Task added successfully!!\n";
}

void viewTasks(const vector<Task>& tasks){     // Function to view all tasks
    if (tasks.empty()){
        cout<< "No tasks available.\n";
        return;
    }

    cout<< "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i){
        cout<< i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].descr << "\n";
    }
}

void markTaskCompleted(vector<Task>& tasks){   // Function to mark a task as completed
    if (tasks.empty()){
        cout<< "No Tasks Available to mark as completed.\n";
        return;
    }

    cout<< "Enter the Task Number to mark as completed: ";
    size_t taskNumber;
    cin>> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()){
        tasks[taskNumber - 1].completed = true;
        cout<< "Task Marked as COMPLETED!!\n";
    } 
    else{
        cout<< "Invalid Task Number!!!\n";
    }
    cin.ignore();
}

void removeTask(vector<Task>& tasks){      // Function to remove a task from the list
    if (tasks.empty()){
        cout<< "No Tasks Available to Remove\n";
        return;
    }

    cout<< "Enter the Task Number to remove: ";
    size_t taskNumber;
    cin>> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()){
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout<< "Task Removed Successfully!!\n";
    } 
    else{
        cout<< "Invalid Task Number!!!\n";
    }
    cin.ignore();
}

int main() {
    vector<Task> tasks;
    char choice;

    do {
        cout<< "\n~~~~~~ To-Do List Manager ~~~~~~\n"
            << "1. Add Task\n"
            << "2. View Tasks\n"
            << "3. Mark Task as Completed\n"
            << "4. Remove Task\n"
            << "5. Exit\n\n"
            << "Choose an option (1-5):";
        cin>> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                markTaskCompleted(tasks);
                break;
            case '4':
                removeTask(tasks);
                break;
            case '5':
                cout<<"\n******************************************\n"
                    <<"  Exiting To-Do List Manager. Goodbye!!!!\n"
                    <<"******************************************\n";
                break;
            default:
                cout<< "Invalid choice!!! Please Try Again.\n";
        }
    } while (choice != '5');
    return 0;
}

