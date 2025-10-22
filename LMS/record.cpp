#include <iostream>
#include <string>
using namespace std;

// Struct for storing student record
struct Record {
    int rollNo;
    string date;
    string status;  // Present / Absent
    string remarks; // optional remarks
};

void recordMenu() {
    Record records[50];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n--- Record Management Section ---" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Show All Records" << endl;
        cout << "3. Update Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // ------------------ ADD RECORD ------------------
        if (choice == 1) {
            if (count < 50) {
                cout << "\nEnter Student Roll No: ";
                cin >> records[count].rollNo;

                cout << "Enter Date (DD/MM/YYYY): ";
                cin >> records[count].date;

                cout << "Enter Status (Present/Absent): ";
                cin >> records[count].status;

                cout << "Enter Remarks (optional): ";
                cin >> records[count].remarks;

                count++;
                cout << "✅ Record added successfully!\n";
            } else {
                cout << "❌ Cannot add more records. Array full.\n";
            }
        }

        // ------------------ SHOW ALL RECORDS ------------------
        else if (choice == 2) {
            if (count == 0) {
                cout << "No records available.\n";
            } else {
                cout << "\n--- Attendance/Record List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << "Roll No: " << records[i].rollNo 
                         << " | Date: " << records[i].date 
                         << " | Status: " << records[i].status 
                         << " | Remarks: " << records[i].remarks << endl;
                }
            }
        }

        // ------------------ UPDATE RECORD ------------------
        else if (choice == 3) {
            int roll;
            string date;
            bool found = false;

            cout << "Enter Roll No to update: ";
            cin >> roll;
            cout << "Enter Date to update (DD/MM/YYYY): ";
            cin >> date;

            for (int i = 0; i < count; i++) {
                if (records[i].rollNo == roll && records[i].date == date) {
                    cout << "\n✅ Record Found!" << endl;
                    cout << "Current Status: " << records[i].status 
                         << " | Remarks: " << records[i].remarks << endl;

                    cout << "\nEnter New Status (Present/Absent): ";
                    cin >> records[i].status;

                    cout << "Enter New Remarks: ";
                    cin >> records[i].remarks;

                    cout << "✅ Record updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "❌ Record not found.\n";
        }

        // ------------------ DELETE RECORD ------------------
        else if (choice == 4) {
            int roll;
            string date;
            bool found = false;

            cout << "Enter Roll No to delete: ";
            cin >> roll;
            cout << "Enter Date to delete (DD/MM/YYYY): ";
            cin >> date;

            for (int i = 0; i < count; i++) {
                if (records[i].rollNo == roll && records[i].date == date) {
                    for (int j = i; j < count - 1; j++)
                        records[j] = records[j + 1];
                    count--;
                    cout << "✅ Record deleted successfully!\n";
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
