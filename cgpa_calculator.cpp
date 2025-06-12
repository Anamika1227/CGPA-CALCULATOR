#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <limits>  
using namespace std;


struct Course {
    string name;
    int credit;
    char grade;
    float gradePoint;
};


float getGradePoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 10.0;
        case 'B': return 8.0;
        case 'C': return 6.0;
        case 'D': return 4.0;
        case 'E': return 2.0;
        case 'F': return 0.0;
        default: return -1.0;
    }
}


string gradeFeedback(char grade) {
    switch (toupper(grade)) {
        case 'A': return "Excellent";
        case 'B': return "Very Good";
        case 'C': return "Good";
        case 'D': return "Average";
        case 'E': return "Needs Improvement";
        case 'F': return "Fail";
        default: return "Invalid";
    }
}


string courseDifficulty(int credit) {
    if (credit >= 5) return "Hard";
    else if (credit >= 3) return "Moderate";
    else return "Easy";
}

int main() {
    int n;
    vector<Course> courses;
    float totalCredits = 0, totalPoints = 0;

    cout << "?? CGPA CALCULATOR ??\n";
    cout << "Enter number of courses: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        Course c;
        cout << "\nCourse #" << i + 1 << ":\n";

        cout << "Course Name: ";
        getline(cin, c.name);

        cout << "Credits: ";
        cin >> c.credit;

        cout << "Grade (A-F): ";
        cin >> c.grade;

        c.gradePoint = getGradePoint(c.grade);
        if (c.gradePoint == -1.0) {
            cout << "? Invalid grade entered. Try again.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
            continue;
        }

        courses.push_back(c);
        totalCredits += c.credit;
        totalPoints += c.gradePoint * c.credit;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

   
    cout << "\n?? COURSE REPORT:\n";
    cout << left << setw(20) << "Course"
         << setw(10) << "Credit"
         << setw(10) << "Grade"
         << setw(15) << "Grade Point"
         << setw(15) << "Feedback"
         << setw(15) << "Difficulty" << endl;

    for (const auto& c : courses) {
        cout << left << setw(20) << c.name
             << setw(10) << c.credit
             << setw(10) << c.grade
             << setw(15) << c.gradePoint
             << setw(15) << gradeFeedback(c.grade)
             << setw(15) << courseDifficulty(c.credit) << endl;
    }

    float cgpa = totalPoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\n?? Total Credits: " << totalCredits;
    cout << "\n?? Total Grade Points: " << totalPoints;
    cout << "\n?? CGPA: " << cgpa;

   
    cout << "\n?? Advice: ";
    if (cgpa >= 9) cout << "Outstanding Performance!";
    else if (cgpa >= 8) cout << "Very Good. Keep it up!";
    else if (cgpa >= 6) cout << "Good. Can Improve.";
    else cout << "You need to work hard and seek help.";

    cout << "\n\n? Thank you for using the CGPA Calculator!\n";

    return 0;
}

