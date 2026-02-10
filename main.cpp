#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_STUDENTS 5

struct Student {
    int studentId;
    string studentName;
    float studentGrades;
};

void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int choice;

    students[0] = { 99, "Guadalupe Mendez", 67 };
    students[1] = { 73, "Javon Lee", 55 };
    students[2] = { 100, "Natalia Sanchez", 94 };
    students[3] = { 86, "Demi Jimenez", 91 };
    students[4] = { 92, "Madeline Monroe", 88 };

    int count = 5;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: highestGrade(students, count); break;
            case 2: lowestGrade(students, count); break;
            case 3: averageGrade(students, count); break;
            case 4: printStudentId(students, count); break;
            case 5: printStudentName(students, count); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void printMenu() {
    cout << "\n=== Student Record System ===\n";
    cout << "1. Find student with the highest grade\n";
    cout << "2. Find the student with the lowest grade\n";
    cout << "3. Find the average grade in the class\n";
    cout << "4. Print all the student's ID\n";
    cout << "5. Print all the student's names\n";
    cout << "6. Exit\n";
}

void highestGrade(Student students[], int count) {
    if (count == 0) return;

    int highestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].studentGrades > students[highestIndex].studentGrades) {
            highestIndex = i;
        }
    }
    cout << "The student with the highest grade is: " << students[highestIndex].studentName 
         << " with a grade of " << students[highestIndex].studentGrades << endl;
}

void lowestGrade(Student students[], int count) {
    if (count == 0) return;

    int lowestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].studentGrades < students[lowestIndex].studentGrades) {
            lowestIndex = i;
        }
    }
    cout << "The student with the lowest grade is: " << students[lowestIndex].studentName 
         << " with a grade of " << students[lowestIndex].studentGrades << endl;
}

void averageGrade(Student students[], int count) {
    if (count == 0) return;

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].studentGrades;
    }
    cout << fixed << setprecision(2);
    cout << "The average grade in the class is: " << (sum / count) << endl;
}

void printStudentId(Student students[], int count) {
    cout << "--- Student IDs ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].studentId << endl;
    }
}

void printStudentName(Student students[], int count) {
    cout << "--- Student Names ---\n";
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].studentName << endl;
    }
}
