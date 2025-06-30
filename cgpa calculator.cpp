#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

int main() {
    int numCourses;
    float grade, totalPoints = 0;
    int credit, totalCredits = 0;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    // Validate course count
    if (numCourses <= 0) {
        cout << "? Invalid number of courses.\n";
        return 1;
    }

    for (int i = 1; i <= numCourses; i++) {
        cout << "\nCourse " << i << ":\n";

        // Grade input with validation (assuming 10-point scale)
        do {
            cout << "Enter grade (0.0 to 10.0): ";
            cin >> grade;
            if (grade < 0.0 || grade > 10.0) {
                cout << "? Invalid grade. Try again.\n";
            }
        } while (grade < 0.0 || grade > 10.0);

        // Credit input with validation
        do {
            cout << "Enter credit hours (positive integer): ";
            cin >> credit;
            if (credit <= 0) {
                cout << "? Credit hours must be positive. Try again.\n";
            }
        } while (credit <= 0);

        totalPoints += grade * credit;
        totalCredits += credit;
    }

    if (totalCredits == 0) {
        cout << "?? No valid credits entered. Cannot calculate GPA.\n";
        return 1;
    }

    float gpa = totalPoints / totalCredits;

    cout << fixed << setprecision(2); // limit to 2 decimal places
    cout << "\n? GPA Calculation Complete:\n";
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalPoints << endl;
    cout << "Your GPA (CGPA): " << gpa << endl;

    return 0;
}

