#include <iostream>

using namespace std;

int main()
{
    char board[3][3] =
    {
        {'#', '#', '#'},
        {'#', '#', '#'},
        {'#', '#', '#'}
    };
    char player = 'X', winner = '#';

    // Using a while loop so we only increment moves on VALID turns
    int totalMoves = 0;
    while (totalMoves < 9)
    {
        // 1. Display the board correctly
        cout << "\nCurrent Board:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        int row, column;
        cout << "Player " << player << ", enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> column;

        // 2. Validate input range and empty spot
        if (row < 1 || row > 3 || column < 1 || column > 3 || board[row - 1][column - 1] != '#')
        {
            cout << "Invalid move! Try again." << endl;
            continue; // Go back to start of while loop WITHOUT incrementing totalMoves
        }

        board[row - 1][column - 1] = player;
        totalMoves++;

        bool gameEnded = false;

        // 3. Check Rows and Columns in one loop
        for (int i = 0; i < 3; i++)
        {
            // Vertical check
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                gameEnded = true;
            // Horizontal check
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                gameEnded = true;
        }

        // 4. Check Diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            gameEnded = true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            gameEnded = true;

        if (gameEnded)
        {
            winner = player;
            break;
        }

        // 5. Switch Player (Always use uppercase '0' or 'O' to match your win check)
        player = (player == 'X') ? '0' : 'X';
    }

    // Final result
    if (winner != '#')
        cout << "\nPlayer " << winner << " has won!" << endl;
    else
        cout << "\nIt's a tie!" << endl;

    return 0;
}