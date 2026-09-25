#include <iostream>
#include <vector>
#include <random>
using namespace std;

string userChoice;

int main () {
    string playAgain = "yes";

    cout << "Welcome to Rock Paper Scissors!" << endl;
    cout << "Choose Rock, Paper, or Scissors." << endl;

    while (playAgain == "yes" or playAgain == "Yes") {
        // Receieve the Users Choice
        cout << "Choice: ";
        cin >> userChoice;

        // Generate Random Computer Choice
        vector <string> options = {"Rock", "Paper", "Scissors"};
        random_device rd;
        default_random_engine eng(rd());
        uniform_int_distribution <int> distr(0, options.size() - 1);
        int random_index = distr(eng);

        // Define Losing Situations
        if (userChoice == "Rock" or "rock" && options[random_index] == "Paper") {
            cout << "You Lose!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }
        else if (userChoice == "Scissors" && options[random_index] == "Rock" ) {
            cout << "You Lose!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }
        else if (userChoice == "Paper" && options[random_index] == "Scissors") {
            cout << "You Lose!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }
        // Define Winning Situations
        else if (userChoice == "Scissors" && options[random_index] == "Paper" ) {
            cout << "You Win!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }
        else if (userChoice == "Rock" && options[random_index] == "Scissors" ) {
            cout << "You Win!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }
        else if (userChoice == "Paper" && options[random_index] == "Rock") {
            cout << "You Win!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }
        else if (userChoice == options[random_index]) {
            cout << "You Tied!" << endl;
            cout << "The Computer Chose " << options[random_index] << "!" << endl;
        }

        cout << "Would You Like to Play Again?" << endl;
        cin >> playAgain;
    }
    return 0;
}



