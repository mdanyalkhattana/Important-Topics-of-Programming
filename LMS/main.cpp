#include <iostream>
using namespace std;

// Function declarations
void teacherMenu();
void studentMenu();
void assignmentMenu();
void gradeMenu();
void recordMenu();

int main() {
    int choice;

    while (true) {
        cout << "\n===== Learning Management System =====" << endl;
        cout << "1. Teacher Section" << endl;
        cout << "2. Student Section" << endl;
        cout << "3. Assignment Section" << endl;
        cout << "4. Grades Section" << endl;
        cout << "5. Record Management" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            teacherMenu();
        else if (choice == 2)
            studentMenu();
        else if (choice == 3)
            assignmentMenu();
        else if (choice == 4)
            gradeMenu();
        else if (choice == 5)
            recordMenu();
        else if (choice == 6) {
            cout << "Exiting program... Goodbye!\n";
            break;
        } else
            cout << "Invalid choice! Try again.\n";
    }

    return 0;
}
