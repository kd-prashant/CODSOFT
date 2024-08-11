#include <iostream>
using namespace std;

char BOARD[3][3];
char currentPlayer;

void initializeBOARD() {    // Function to initialize the board with numbers 1-9
    int count= 1;
    for (int i= 0; i < 3; i++) {
        for (int j= 0; j < 3; j++) {
            BOARD[i][j]= '0' + count++;
        }
    }
    currentPlayer= 'X';
}

void displayBOARD() {   // Function to display the current board
    cout<< "-------------\n";
    for (int i= 0; i < 3; i++) {
        cout<< "| ";
        for (int j= 0; j < 3; j++) {
            cout<< BOARD[i][j] << " | ";
        }
        cout<< "\n-------------\n";
    }
}

bool checkWin() {   // Function to check if the current player has won
    for (int i= 0; i < 3; i++) {
        if (BOARD[i][0] == BOARD[i][1] && BOARD[i][1] == BOARD[i][2])
            return true;
        if (BOARD[0][i] == BOARD[1][i] && BOARD[1][i] == BOARD[2][i])
            return true;
    }
    if (BOARD[0][0] == BOARD[1][1] && BOARD[1][1] == BOARD[2][2])
        return true;
    if (BOARD[0][2] == BOARD[1][1] && BOARD[1][1] == BOARD[2][0])
        return true;   
    return false;
}

bool checkDraw() {  // Function to check if the game is a draw
    for (int i= 0; i < 3; i++) {
        for (int j= 0; j < 3; j++) {
            if (BOARD[i][j] != 'X' && BOARD[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void playerMove() { // Function to handle the player's move
    int move;
    cout<< "\nPlayer " << currentPlayer << ", enter your move (1-9): ";
    cin>> move;

    int row= (move - 1) / 3;       // Calculate the row and column from the move
    int col= (move - 1) % 3;

    if (move < 1 || move > 9 || BOARD[row][col] == 'X' || BOARD[row][col] == 'O') {
        cout<< "Invalid Move!!! Try again.\n";
        playerMove();  // Retry the move
    } 
    else {
        BOARD[row][col]= currentPlayer;  // Update the board with the move
    }
}

void switchPlayer() {   // Function to switch the current player
    currentPlayer= (currentPlayer == 'X') ? 'O' : 'X';
}

void startGame() {   // Function to play a single game
    initializeBOARD();
    bool gameWon= false;
    bool gameDraw= false;

    while (!gameWon && !gameDraw) {
        displayBOARD();
        playerMove();
        gameWon= checkWin();
        if (!gameWon) {
            gameDraw= checkDraw();
            if (!gameDraw) {
                switchPlayer();
            }
        }
    }

    displayBOARD();

    if (gameWon) {
        cout<< "\nPlayer " << currentPlayer << " WINs the game!!\n";
    } 
    else if (gameDraw) {
        cout<< "The Game is a DRAW!!!\n";
    }
}


int main() {
    cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        << "   Welcome to the Ultimate Tic-Tac-Toe Game!\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    char startAgain;
    do {
        startGame();
        cout<< "\nDo you want to play again? (y/n): ";
        cin>> startAgain;
    } while (startAgain == 'y' || startAgain == 'Y');

    cout<<"\n***********************************\n"
        <<"Thank you for playing Tic-Tac-Toe!!\n"
        <<"***********************************\n";
    return 0;
}
