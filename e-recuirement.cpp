#include <iostream>
#include <string>

using namespace std;

// Define a structure for a single requirement
struct Requirement {
    int id;
    string description;
    Requirement* next;

    Requirement(int reqId, const string& reqDesc) : id(reqId), description(reqDesc), next(nullptr) {}
};

class RequirementSystem {
private:
    Requirement* head;

public:
    RequirementSystem() : head(nullptr) {}

    // Function to add a new requirement
    void addRequirement(int id, const string& description) {
        Requirement* newRequirement = new Requirement(id, description);
        newRequirement->next = head;
        head = newRequirement;
        cout << "Requirement added successfully!" << endl;
    }

    // Function to delete a requirement by ID
    void deleteRequirement(int id) {
        Requirement* current = head;
        Requirement* prev = nullptr;

        while (current != nullptr && current->id != id) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Requirement not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Requirement deleted successfully!" << endl;
    }

    // Function to display all requirements
    void displayRequirements() {
        Requirement* current = head;

        if (current == nullptr) {
            cout << "No requirements found." << endl;
            return;
        }

        cout << "Requirements:" << endl;
        while (current != nullptr) {
            cout << "ID: " << current->id << ", Description: " << current->description << endl;
            current = current->next;
        }
    }

    // Destructor to free allocated memory
    ~RequirementSystem() {
        Requirement* current = head;
        Requirement* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    RequirementSystem requirementSystem;

    int choice;
    do {
        cout << "\nRequirement Management System\n";
        cout << "1. Add Requirement\n";
        cout << "2. Delete Requirement\n";
        cout << "3. Display Requirements\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string description;

                cout << "Enter requirement ID: ";
                cin >> id;
                cout << "Enter requirement description: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, description);

                requirementSystem.addRequirement(id, description);
                break;
            }
            case 2: {
                int id;
                cout << "Enter requirement ID to delete: ";
                cin >> id;

                requirementSystem.deleteRequirement(id);
                break;
            }
            case 3:
                requirementSystem.displayRequirements();
                break;
            case 4:
                cout << "Exiting Requirement Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
