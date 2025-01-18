#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

// Structure of student
struct Student
{
    string name;
    int totalSubjects;
    vector<int> grades;
    float averageGrades;
    bool isPassed;
};

// Menu display
void displayMenu()
{
    cout << "\n\t1. Add a new student." << endl;
    cout << "\t2. Display all students." << endl;
    cout << "\t3. Search student by name." << endl;
    cout << "\t4. Exit." << endl;
}

// Average grade calculate
float averageGradeCalculate(vector<int> &grades)
{
    int total = 0;
    for (int grade : grades)
    {
        total += grade;
    }
    return total / grades.size();
}

// Check student is passed or failed
bool checkStatus(float averageGrade)
{
    return averageGrade >= 60;
}

// Input taking
void inputStudentInfo(vector<Student> &students)
{
    Student newStudent;
    cin.ignore();
    cout << "\n\tStudent Info Input ...." << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter student name :   ";
    getline(cin, newStudent.name);
    cout << "Enter total subjects:  ";
    cin >> newStudent.totalSubjects;
    newStudent.grades.resize(newStudent.totalSubjects);
    for (int i = 0; i < newStudent.totalSubjects; i++)
    {
        do
        {
            cout << "Enter marks of subject " << i + 1 << " :     ";
            cin >> newStudent.grades[i];
            if (newStudent.grades[i] < 0 || newStudent.grades[i] > 100)
            {
                cout << "Invalid grade! Please enter a grade between 0 and 100." << endl;
            }
        } while (newStudent.grades[i] < 0 || newStudent.grades[i] > 100);
    }
    newStudent.averageGrades = averageGradeCalculate(newStudent.grades);
    newStudent.isPassed = checkStatus(newStudent.averageGrades);
    students.push_back(newStudent);
    cout << "Student Added successfully!!" << endl;
    cout << "----------------------------------------------" << endl;
}

// Display student info special
void info(const vector<Student> &students)
{
    for (const Student &student : students)
    {
        cout << "----------------------------------------------" << endl;
        cout << "Name : " << student.name << endl;
        for (int count = 0; count < student.grades.size(); count++)
        {
            cout << "Subject " << count + 1 << " grade : " << student.grades[count] << endl;
        }
        cout << "Average Grade : " << fixed << setprecision(2) << student.averageGrades << endl;
        student.isPassed ? cout << "Status : PASSED\n" : cout << "Status : FAILED\n";
        cout << "----------------------------------------------" << endl;
    }
}

// Display student info
void displayStudentsInfo(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "No student to display.." << endl;
        return;
    }
    cout << "\n\tInformation of students..\n";
    info(students);
}

// Search student by name
void searchStd(const vector<Student> &students)
{
    string searchName;
    cout << "Enter student name to be searched :    ";
    cin.ignore();
    getline(cin, searchName);
    bool isFound = false;
    for (const Student &student : students)
    {
        if (student.name == searchName)
        {
            isFound = true;
            cout << "\n\t Student Found.." << endl;
            cout << "----------------------------------------------" << endl;
            cout << "Name : " << student.name << endl;
            for (int count = 0; count < student.grades.size(); count++)
            {
                cout << "Subject " << count + 1 << " grade : " << student.grades[count] << endl;
            }
            cout << "Average Grade : " << fixed << setprecision(2) << student.averageGrades << endl;
            student.isPassed ? cout << "Status : PASSED\n" : cout << "Status : FAILED\n";
            cout << "----------------------------------------------" << endl;
            break;
        }
    }
    if (!isFound)
    {
        cout << "Student not found!!" << endl;
    }
}

// Main program
int main()
{
    vector<Student> students;
    int choice;
    do
    {
        displayMenu();
        cout << "\nEnter option (1-4) :     ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            inputStudentInfo(students);
            break;
        case 2:
            displayStudentsInfo(students);
            break;
        case 3:
            searchStd(students);
            break;
        case 4:
            cout << "\n\t\tYou Exited!!";
            return 0;
        default:
            cout << "Invalid choice selected. (1-4)!" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
