#include <iostream>
#include <string>
using namespace std;

// Structure to store grade data
struct Grade {
    int rollNo;
    string subject;
    float marks;
    char grade;
};

// Function to manage grades
void gradeMenu() {
    Grade grades[50];  // can store up to 50 records
    int count = 0;     // number of grade records
    int choice;

    while (true) {
        cout << "\n--- Grades Section ---" << endl;
        cout << "1. Add Grade" << endl;
        cout << "2. Show All Grades" << endl;
        cout << "3. Update Grade" << endl;
        cout << "4. Delete Grade" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // ------------------ ADD GRADE ------------------
        if (choice == 1) {
            if (count < 50) {
                cout << "\nEnter Student Roll No: ";
                cin >> grades[count].rollNo;

                cout << "Enter Subject: ";
                cin >> grades[count].subject;

                cout << "Enter Marks: ";
                cin >> grades[count].marks;

                // Auto-assign grade based on marks
                if (grades[count].marks >= 85)
                    grades[count].grade = 'A';
                else if (grades[count].marks >= 70)
                    grades[count].grade = 'B';
                else if (grades[count].marks >= 60)
                    grades[count].grade = 'C';
                else if (grades[count].marks >= 50)
                    grades[count].grade = 'D';
                else
                    grades[count].grade = 'F';

                cout << "✅ Grade Assigned: " << grades[count].grade << endl;

                count++;
                cout << "✅ Grade record added successfully!\n";
            } else {
                cout << "❌ Cannot add more grades. Array full.\n";
            }
        }

        // ------------------ SHOW ALL GRADES ------------------
        else if (choice == 2) {
            if (count == 0)
                cout << "No grades available.\n";
            else {
                cout << "\n--- Grades List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << "Roll No: " << grades[i].rollNo
                         << " | Subject: " << grades[i].subject
                         << " | Marks: " << grades[i].marks
                         << " | Grade: " << grades[i].grade << endl;
                }
            }
        }

        // ------------------ UPDATE GRADE ------------------
        else if (choice == 3) {
            int roll;
            bool found = false;
            cout << "Enter Roll No to update grade: ";
            cin >> roll;

            for (int i = 0; i < count; i++) {
                if (grades[i].rollNo == roll) {
                    cout << "\n✅ Record Found!" << endl;
                    cout << "Current Subject: " << grades[i].subject 
                         << " | Marks: " << grades[i].marks 
                         << " | Grade: " << grades[i].grade << endl;

                    cout << "\nEnter New Marks: ";
                    cin >> grades[i].marks;

                    // Recalculate grade
                    if (grades[i].marks >= 85)
                        grades[i].grade = 'A';
                    else if (grades[i].marks >= 70)
                        grades[i].grade = 'B';
                    else if (grades[i].marks >= 60)
                        grades[i].grade = 'C';
                    else if (grades[i].marks >= 50)
                        grades[i].grade = 'D';
                    else
                        grades[i].grade = 'F';

                    cout << "✅ Updated Grade: " << grades[i].grade << endl;
                    cout << "✅ Grade updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "❌ Record not found.\n";
        }

        // ------------------ DELETE GRADE ------------------
        else if (choice == 4) {
            int roll;
            bool found = false;
            cout << "Enter Roll No to delete grade: ";
            cin >> roll;

            for (int i = 0; i < count; i++) {
                if (grades[i].rollNo == roll) {
                    for (int j = i; j < count - 1; j++)
                        grades[j] = grades[j + 1];
                    count--;
                    cout << "✅ Grade deleted successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "❌ Record not found.\n";
        }

        // ------------------ BACK ------------------
        else if (choice == 5) {
            cout << "Returning to main menu...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}
