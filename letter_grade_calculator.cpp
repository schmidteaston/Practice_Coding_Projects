#include <iostream>
using namespace std;

// Define Variables
int scores = 0, num, average;
string grade;

int main() {
    // Loop the cin function until 5 scores have been entered
    cout << "Please enter your scores: " << endl;
    for (int count = 1; count <=5; count++) {
        cout << "Score " << count << ": ";
        cin >> num;
        scores = scores + num;
    }
    average = scores / 5;

    if (average >= 90) {
        grade = "A";
    }
    else if (average >= 80) {
        grade = "B";
        }
    else if (average >= 70) {
        grade = "C";
    }
    else if (average >= 60) {
        grade = "D";
    }
    else {
        grade = "F";
    }

        cout << "Your Average Score is " << average << "!" << endl;
        cout << "Your Letter Grade is " << grade << "!" << endl;
    return 0;
}
