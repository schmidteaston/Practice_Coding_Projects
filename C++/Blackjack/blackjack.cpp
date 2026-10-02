#include <iostream>
#include <random>
using namespace std;

int static getCardValue(int card) {
    if (card == 1) {
        return 11;
    }
    else if (card >= 11) {
        return 10;
    }
    else {
        return card;
    }
}

int main() {
    float userBalance = 1000, wager;
    string playAgain = "y";

    cout << "Welcome to Blackjack!" << endl;

    while (playAgain != "n") {
        cout << "Your Balance is: $" << userBalance << endl;
        cout << "How Much Would You Like to Wager? - $";
        cin >> wager;

        if (wager > userBalance) {
            cout << "You cannot wager more than your balance! Try again." << endl;
            continue;
        }
        cin.ignore();
        userBalance = userBalance - wager;
        cout << endl;

        // Random Card Generator
        random_device cardGenerator;
        default_random_engine eng(cardGenerator());
        uniform_int_distribution <int> cardRank(1, 13);

        // generate the users hand and value
        int playerCard1 = cardRank(cardGenerator);
        int playerCard2 = cardRank(cardGenerator);
        int playerValue1 = getCardValue(playerCard1);
        int playerValue2 = getCardValue(playerCard2);
        int playerTotal = playerValue1 + playerValue2;

        // change hand value if user has 2 aces
        int playerAces = 0;

        if (playerCard1 == 1) {
            playerAces++;
        }
        if (playerCard2 == 1) {
            playerAces++;
        }

        // Change an ace from 11 to 1 when needed
        while (playerTotal > 21 && playerAces > 0) {
            playerTotal -= 10;
            playerAces--;
        }

        // generate the dealers hand and value
        int dealerCard1 = cardRank(cardGenerator);
        int dealerCard2 = cardRank(cardGenerator);
        int dealerValue1 = getCardValue(dealerCard1);
        int dealerValue2 = getCardValue(dealerCard2);
        int dealerTotal = dealerValue1 + dealerValue2;

        // change hand value if user has 2 aces
        int dealerAces = 0;

        if (dealerCard1 == 1) {
            dealerAces++;
        }
        if (dealerCard2 == 1) {
            dealerAces++;
        }

        // Change an ace from 11 to 1 when needed
        while (dealerTotal > 21 && dealerAces > 0) {
            dealerTotal -= 10;
            dealerAces--;
        }

        cout << "The dealer is showing a " << dealerValue1 << endl;
        cout << "Your hand is " << playerTotal << endl << endl;

        while (playerTotal < 21) {
            if (dealerTotal == 21) {
                break;
            }
            char playerchoice;
            cout << "Would you like to hit or stand? (h/s): ";
            cin >> playerchoice;
            cout << endl;

            while (playerchoice != 'h' && playerchoice != 's') {
                cout << "You Entered an invalid choice, please enter h/s" << endl;
            }

            if (playerchoice == 's') {
                cout << "You Stood" << endl << endl;
                break;
            }

            if (playerchoice == 'h') {
                int playerHit = cardRank(cardGenerator);
                int playerHitValue = getCardValue(playerHit);
                playerTotal += playerHitValue;

                if (playerHit == 1) {
                    playerAces++;
                }
                while (playerTotal > 21 && playerAces > 0) {
                    playerTotal -= 10;
                    playerAces--;
                }
                if (playerTotal > 21) {
                    cout << "You busted!" << endl;
                    break;
                }
                cout << "Your hand is now: " << playerTotal << endl << endl;
            }
        }

        while (dealerTotal < 17 && playerTotal < 21) {
            int dealerHit = cardRank(cardGenerator);
            int dealerHitValue = getCardValue(dealerHit);
            dealerTotal += dealerHitValue;

            if (dealerHit == 1) {
                dealerAces++;
            }
            while (dealerTotal > 21 && dealerAces > 0) {
                dealerTotal -= 10;
                dealerAces--;
            }
            if (dealerTotal > 21) {
                dealerTotal -= dealerTotal;
                break;
            }
        }

        if (dealerTotal == 0) {
            cout << "The Dealer Busted" << endl;
        }

        else if (dealerTotal == 21) {
            cout << "Dealer Blackjack!" << endl << endl;
        }
        else {
            cout << "The Dealer had: " << dealerTotal << endl;
        }

        cout << "You had: " << playerTotal << endl;

        if (playerTotal > dealerTotal && playerTotal <=21) {
            cout << "You win!" << endl << endl;
            userBalance += (wager*2);
        }
        else if (playerTotal == 21) {
            cout << "Blackjack! You win!" << endl << endl;
            userBalance += (wager*2.5);
        }
        else if (playerTotal == dealerTotal) {
            cout << "You Tied!" << endl << endl;
            userBalance += wager;
        }
        else {
            cout << "You lose!" << endl << endl;
        }
        cout << "Your Balance is now: $" << userBalance << endl << endl;

        if (userBalance <=0) {
            cout << "Your Balance is: $" << userBalance << endl;
            cout << "You went broke!";
            break;
        }
        cout << "Would You Like to Play Again? (y/n)";
        cin >> playAgain;
        cout << endl;
    }
    return 0;
}