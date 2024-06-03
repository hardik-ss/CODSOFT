#include <iostream>
using namespace std;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col;
string n1 = " ";
string n2 = " ";
bool tie = false;
char token = 'X';

void DisplayBoard()
{
    cout << "      |    |      \n";
    cout << "  " << space[0][0] << "  " << " | " << space[0][1] << "  " << "| " << space[0][2] << "\n";
    cout << "      |    |      \n";
    cout << "------------------\n";
    cout << "      |    |      \n";
    cout << "  " << space[1][0] << "  " << " | " << space[1][1] << "  " << "| " << space[1][2] << "\n";
    cout << "      |    |      \n";
    cout << "-----------------\n";
    cout << "      |    |      \n";
    cout << "  " << space[2][0] << "  " << " | " << space[2][1] << "  " << "| " << space[2][2] << "\n";
    cout << "      |    |      \n";
}

void Player_Moves()
{
    int digit;

    if (token == 'X')
    {
        cout << "player 1 Enter digit on grid(1-9)= ";
        cin >> digit;
    }
    else if (token == 'O')
    {
        cout << "player 2 Enter digit on grid(1-9)= ";
        cin >> digit;
    }
    if (digit == 1)
    {
        row = 0;
        col = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        col = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        col = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        col = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        col = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        col = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        col = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        col = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        col = 2;
    }
    else if (digit < 1 || digit >> 9)
    {
        cout << " Invalid choice !!!\n";
    }

    if (token == 'X' && space[row][col] != 'X' && space[row][col] != 'O')
    {
        space[row][col] = 'X';
        token = 'O';
    }
    else if (token == 'O' && space[row][col] != 'X' && space[row][col] != 'O')
    {
        space[row][col] = 'O';
        token = 'X';
    }
    else
    {
        cout << "This is not an empty space !" << endl;
        Player_Moves();
    }
    DisplayBoard();
}

bool Check_result()
{
    for (int i = 0; i < 3; i++) // check for row match
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[i][0] == space[2][i])
            return true;
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) // check diagonal match
    {
        return true;
    }

    for (int i = 0; i < 3; i++) // check for empty spaces in grid
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }
    bool tie=true;
    return tie;
}

int main()
{
    cout << "    " << "Tic-Tac-Toe " << endl;
    cout << " " << "================= " << endl;
    string n1 = " ", n2 = " ";
    cout << "Enter Player 1 Name = ";
    cin >> n1;
    cout << "\nEnter Player 2 Name = ";
    cin >> n2;
    cout << n1 << " will play first!\n";
    cout << n2 << " will play Second!\n";
    DisplayBoard();

    while (!Check_result())
    {
        Player_Moves();
        Check_result();
    }
    if (token == 'X' && tie == false)
    {
        cout << n2 << " wins!!!" << endl;
    }
    else if (token == 'O' && tie == false)
    {
        cout << n1 << " wins!!!" << endl;
    }
    else
       {
        cout << "It is draw!" << endl;
       } 
}
