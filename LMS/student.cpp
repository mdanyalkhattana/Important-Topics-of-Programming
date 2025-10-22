#include <iostream>
#include <string>
using namespace std;

// Struct to store student data
struct Student {
    int rollNo;
    string name;
    string course;
};

// Function for student operations
void studentMenu() {
    Student students[50];  // Array to store up to 50 students
    int count = 0;
    int choice;

    while (true) {
        cout << "\n--- Student Section ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Show All Students" << endl;
        cout << "3. Search Student by Roll No" << endl;
        cout << "4. Update Student Info" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // ------------------ ADD STUDENT ------------------
        if (choice == 1) {
            if (count < 50) {
                cout << "\nEnter Roll No: ";
                cin >> students[count].rollNo;

                cout << "Enter Name: ";
                cin >> students[count].name;

                cout << "Enter Course: ";
                cin >> students[count].course;

                count++;
                cout << "✅ Student added successfully!\n";
            } else {
                cout << "❌ Cannot add more students. Array full.\n";
            }
        }

        // ------------------ SHOW ALL STUDENTS ------------------
        else if (choice == 2) {
            if (count == 0) {
                cout << "No students available.\n";
            } else {
                cout << "\n--- Student List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << "Roll No: " << students[i].rollNo 
                         << " | Name: " << students[i].name 
                         << " | Course: " << students[i].course << endl;
                }
            }
        }

        // ------------------ SEARCH STUDENT ------------------
        else if (choice == 3) {
            int searchRoll;
            bool found = false;
            cout << "Enter Roll No to search: ";
            cin >> searchRoll;

            for (int i = 0; i < count; i++) {
                if (students[i].rollNo == searchRoll) {
                    cout << "\n✅ Student Found!\n";
                    cout << "Roll No: " << students[i].rollNo << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Course: " << students[i].course << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Student not found.\n";
            }
        }

        // ------------------ UPDATE STUDENT ------------------
        else if (choice == 4) {
            int updateRoll;
            bool found = false;
            cout << "Enter Roll No to update: ";
            cin >> updateRoll;

            for (int i = 0; i < count; i++) {
                if (students[i].rollNo == updateRoll) {
                    cout << "\n✅ Student Found!" << endl;
                    cout << "Current Name: " << students[i].name << endl;
                    cout << "Current Course: " << students[i].course << endl;

                    cout << "\nEnter new name (or same to keep): ";
                    cin >> students[i].name;

                    cout << "Enter new course (or same to keep): ";
                    cin >> students[i].course;

                    cout << "✅ Student information updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Student not found.\n";
            }
        }

        // ------------------ DELETE STUDENT ------------------
        else if (choice == 5) {
            int deleteRoll;
            bool found = false;
            cout << "Enter Roll No to delete: ";
            cin >> deleteRoll;

            for (int i = 0; i < count; i++) {
                if (students[i].rollNo == deleteRoll) {
                     
                    for (int j = i; j < count - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    count--;  // reduce total count
                    cout << "✅ Student deleted successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Student not found.\n";
            }
        }

        // ------------------ EXIT TO MAIN MENU ------------------
        else if (choice == 6) {
            cout << "Returning to main menu...\n";
            break;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
