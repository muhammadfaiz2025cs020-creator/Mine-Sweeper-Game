
#include <iostream>
using namespace std;

int main()
{
    char board[9][9];

    // Fill the board with hidden cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = '#';
        }
    }

    // Display the board
    cout << "===== MINESWEEPER GAME =====" << endl;
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

    return 0;
}
