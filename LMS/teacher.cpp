#include <iostream>
#include <string>
using namespace std;

/// Struct to store teacher details
struct Teacher {
    int id;
    string name;
    string subject;
};

// Function to handle teacher operations
void teacherMenu() {
    Teacher teachers[50];  // Array to store up to 50 teachers
    int count = 0;         // How many teachers are stored
    int choice;

    while (true) {
        cout << "\n--- Teacher Section ---" << endl;
        cout << "1. Add Teacher" << endl;
        cout << "2. Show All Teachers" << endl;
        cout << "3. Search Teacher by ID" << endl;
        cout << "4. Update Teacher Info" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // ------------------ ADD TEACHER ------------------
        if (choice == 1) {
            if (count < 50) {
                cout << "\nEnter Teacher ID: ";
                cin >> teachers[count].id;

                cout << "Enter Teacher Name: ";
                cin >> teachers[count].name;

                cout << "Enter Subject: ";
                cin >> teachers[count].subject;

                count++;
                cout << "✅ Teacher added successfully!\n";
            } else {
                cout << "❌ Cannot add more teachers. Array full.\n";
            }
        }

        // ------------------ SHOW ALL TEACHERS ------------------
        else if (choice == 2) {
            if (count == 0) {
                cout << "No teachers available.\n";
            } else {
                cout << "\n--- Teacher List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << "ID: " << teachers[i].id 
                         << " | Name: " << teachers[i].name 
                         << " | Subject: " << teachers[i].subject << endl;
                }
            }
        }

        // ------------------ SEARCH TEACHER ------------------
        else if (choice == 3) {
            int searchId;
            bool found = false;
            cout << "Enter ID to search: ";
            cin >> searchId;

            for (int i = 0; i < count; i++) {
                if (teachers[i].id == searchId) {
                    cout << "\nTeacher Found!\n";
                    cout << "ID: " << teachers[i].id << endl;
                    cout << "Name: " << teachers[i].name << endl;
                    cout << "Subject: " << teachers[i].subject << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Teacher not found.\n";
            }
        }

        // ------------------ UPDATE TEACHER ------------------
        else if (choice == 4) {
            int updateId;
            bool found = false;
            cout << "Enter Teacher ID to update: ";
            cin >> updateId;

            for (int i = 0; i < count; i++) {
                if (teachers[i].id == updateId) {
                    cout << "\nTeacher Found!" << endl;
                    cout << "Current Name: " << teachers[i].name << endl;
                    cout << "Current Subject: " << teachers[i].subject << endl;

                    cout << "\nEnter new name (or same to keep): ";
                    cin >> teachers[i].name;

                    cout << "Enter new subject (or same to keep): ";
                    cin >> teachers[i].subject;

                    cout << "✅ Teacher information updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Teacher not found.\n";
            }
        }

        // ------------------ EXIT TO MAIN MENU ------------------
        else if (choice == 5) {
            cout << "Returning to main menu...\n";
            break;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
