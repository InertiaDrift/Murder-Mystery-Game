void displayBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n-------------\n";
    }
}

// Function to check if there is a win or a draw
char checkWin(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                draw = false;
                break;
            }
        }
    }
    if (draw) {
        return 'D'; // D is for Draw
    }

    return ' '; // Empty indicates game still running
}

bool tictactoe() {
    char board[3][3] = { {'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'} };

    int row, col;
    char currentPlayer = 'X';
    char result = ' ';

    cout << "Tic-Tac-Toe Game\n";

    do {
        displayBoard(board);

        // Get the current player's move
        int choice;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        // Convert the choice to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the chosen cell is empty
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

            // Check if there is a win or a draw
            result = checkWin(board);
        } else {
            cout << "Invalid move. Try again.\n";
        }

    } while (result == ' ');

    // Display the final result
    displayBoard(board);
    if (result == 'D') {
        cout << "It's a draw!\n";
        return false;
    } else {
        cout << "Player " << result << " wins!\n"; return true;
    }

    return false;
}