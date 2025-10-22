#include <iostream>
#include <string>
using namespace std;

// Struct to store assignment data
struct Assignment {
    int id;
    string title;
    string subject;
    string dueDate;
};

void assignmentMenu() {
    Assignment assignments[50];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n--- Assignment Section ---" << endl;
        cout << "1. Add Assignment" << endl;
        cout << "2. Show All Assignments" << endl;
        cout << "3. Update Assignment" << endl;
        cout << "4. Delete Assignment" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // ------------------ ADD ASSIGNMENT ------------------
        if (choice == 1) {
            if (count < 50) {
                cout << "\nEnter Assignment ID: ";
                cin >> assignments[count].id;

                cout << "Enter Title: ";
                cin >> assignments[count].title;

                cout << "Enter Subject: ";
                cin >> assignments[count].subject;

                cout << "Enter Due Date (DD/MM/YYYY): ";
                cin >> assignments[count].dueDate;

                count++;
                cout << "✅ Assignment added successfully!\n";
            } else {
                cout << "❌ Cannot add more assignments.\n";
            }
        }

        // ------------------ SHOW ALL ASSIGNMENTS ------------------
        else if (choice == 2) {
            if (count == 0) {
                cout << "No assignments available.\n";
            } else {
                cout << "\n--- Assignment List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << "ID: " << assignments[i].id 
                         << " | Title: " << assignments[i].title
                         << " | Subject: " << assignments[i].subject
                         << " | Due Date: " << assignments[i].dueDate << endl;
                }
            }
        }

        // ------------------ UPDATE ASSIGNMENT ------------------
        else if (choice == 3) {
            int updateId;
            bool found = false;
            cout << "Enter Assignment ID to update: ";
            cin >> updateId;

            for (int i = 0; i < count; i++) {
                if (assignments[i].id == updateId) {
                    cout << "\n✅ Assignment Found!" << endl;
                    cout << "Current Title: " << assignments[i].title << endl;
                    cout << "Current Subject: " << assignments[i].subject << endl;
                    cout << "Current Due Date: " << assignments[i].dueDate << endl;

                    cout << "\nEnter New Title: ";
                    cin >> assignments[i].title;

                    cout << "Enter New Subject: ";
                    cin >> assignments[i].subject;

                    cout << "Enter New Due Date: ";
                    cin >> assignments[i].dueDate;

                    cout << "✅ Assignment updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "❌ Assignment not found.\n";
        }

        // ------------------ DELETE ASSIGNMENT ------------------
        else if (choice == 4) {
            int deleteId;
            bool found = false;
            cout << "Enter Assignment ID to delete: ";
            cin >> deleteId;

            for (int i = 0; i < count; i++) {
                if (assignments[i].id == deleteId) {
                    for (int j = i; j < count - 1; j++)
                        assignments[j] = assignments[j + 1];
                    count--;
                    cout << "✅ Assignment deleted successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "❌ Assignment not found.\n";
        }

        // ------------------ BACK ------------------
        else if (choice == 5) {
            cout << "Returning to main menu...\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}
