
#include <iostream>
using namespace std;

int main()
{
    char board[9][9];

    // Fill board with hidden boxes
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = '#';
        }
    }

    int row, col;

    cout << "===== MINESWEEPER GAME =====" << endl;

    while (true)
    {
        cout << endl;

        cout << "   ";
        for (int j = 0; j < 9; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;

        for (int i = 0; i < 9; i++)
        {
            cout << i + 1 << "  ";

            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;
        cout << "Enter row (1-9): ";
        cin >> row;

        cout << "Enter column (1-9): ";
        cin >> col;

        if (row == 0 && col == 0)
        {
            cout << "Game Ended!" << endl;
            break;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9)
        {
            cout << "Invalid position! Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = 'O';
    }

    return 0;
}
