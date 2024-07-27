#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string description;
    bool isComplete;

public:
    Task(const std::string& desc) : description(desc), isComplete(false) {}

    void markComplete() {
        isComplete = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool getStatus() const {
        return isComplete;
    }
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.emplace_back(desc);
    }

    void markTaskComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markComplete();
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void displayTasks() const {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription()
                      << " [ " << (tasks[i].getStatus() ? "Complete" : "Incomplete") << " ]" << std::endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    std::string description;
    int index;

    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task Complete\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Ignore newline character left in the buffer

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todo.addTask(description);
                break;

            case 2:
                std::cout << "Enter task index to mark as complete: ";
                std::cin >> index;
                todo.markTaskComplete(index - 1);  // Convert to zero-based index
                break;

            case 3:
                todo.displayTasks();
                break;

            case 4:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
