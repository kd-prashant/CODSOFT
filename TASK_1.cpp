#include <iostream>   
#include <cstdlib>    
#include <ctime>      
#include <limits>    

using namespace std;

void clripstream() {
    cin.clear(); // Clear any error in the input stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  
    int num= rand() % 100 + 1;  
    int guess= 0;  
    int attempt= 0;  

    cout<< "**************************************************\n"
        << "   Welcome to the Ultimate Number Guessing Game!\n"
        << "**************************************************\n"
        << "   I'm thinking of a number between 1 and 100.\n"
        << "    Can you guess WHAT it is? Let's Find out!\n"
        << "**************************************************\n";

    while (true) {
        cout<< "\nEnter Your guess: ";
        cin>> guess;

        if (cin.fail() || guess < 1 || guess > 100) {
            clripstream();
            cout<< "Invalid input!!!! Please enter a number between 1 and 100.";
            continue;
        }

        attempt++;

        if (guess > num) {
            cout<< "Too high!!! The number is LOWER than " << guess << ". Try again!!!";
        } else if (guess < num) {
            cout<< "Too low! The number is HIGHER than " << guess << ". Give it another Shot!";
        } else {
            cout<< "\nCongratulations!! You've guessed the correct number: " << num << "\n"
                << "It took you " << attempt << (attempt == 1 ? " attempt" : " attempts") << " to guess the right number.\n"
                << "\n*********************************************************\n"
                << "Thank You for Playing!!!! Play again to beat your record.\n"
                << "*********************************************************\n";
            break;
        }

        if (attempt == 4) {
            cout<< "\nHint: Don't worry, You'll get it! Keep trying!!!";
        } else if (attempt == 6) {
            cout<< "\nYou're getting CLOSER!! Stay FOCUSED!!";
        } else if (attempt == 8) {
            cout<< "\nAlmost there!! You're doing great!!!!";
        }
    }

    return 0;
}
