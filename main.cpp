
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int SIZE = 9;
    const int MINES = 10;

    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};

    srand(time(0));

    // Initialize board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '0';
        }
    }

    // Place mines
    int count = 0;

    while (count < MINES)
    {
        int r = rand() % SIZE;
        int c = rand() % SIZE;

        if (board[r][c] != '*')
        {
            board[r][c] = '*';
            count++;
        }
    }

    // Calculate nearby mines
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '*')
                continue;

            int mines = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int r = i + x;
                    int c = j + y;

                    if (r >= 0 && r < SIZE && c >= 0 && c < SIZE)
                    {
                        if (board[r][c] == '*')
                            mines++;
                    }
                }
            }

            board[i][j] = '0' + mines;
        }
    }

    int safeCells = 0;

    cout << "===== MINESWEEPER GAME =====\n";

    while (safeCells < SIZE * SIZE - MINES)
    {
        cout << "\n   ";

        for (int j = 0; j < SIZE; j++)
            cout << j + 1 << " ";

        cout << "\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i + 1 << "  ";

            for (int j = 0; j < SIZE; j++)
            {
                if (revealed[i][j])
                    cout << board[i][j] << " ";
                else
                    cout << "# ";
            }

            cout << "\n";
        }

        int row, col;

        cout << "\nEnter row (1-9): ";
        cin >> row;

        cout << "Enter column (1-9): ";
        cin >> col;

        if (row < 1 || row > 9 || col < 1 || col > 9)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        row--;
        col--;

        if (revealed[row][col])
        {
            cout << "This cell is already opened!\n";
            continue;
        }

        if (board[row][col] == '*')
        {
            cout << "\nBOOM! You hit a mine. GAME OVER!\n";
            break;
        }

        revealed[row][col] = true;
        safeCells++;

        cout << "\nSafe! Nearby mines: " << board[row][col] << "\n";
    }

    if (safeCells == SIZE * SIZE - MINES)
        cout << "\nCongratulations! YOU WIN!\n";

    cout << "\n===== GAME FINISHED =====\n";

    return 0;
}
