#include <iostream>
using namespace std;
char board[4][4] = {{"   "}, {"   "}, {"   "}};

void drawBoard()
{
    cout << board[0][0] << '|' << board[0][1] << '|' << board[0][2]
         << "\n-----\n"
         << board[1][0] << '|' << board[1][1] << '|' << board[1][2]
         << "\n-----\n"
         << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << '\n';
}

void inputXO(int player)
{
    bool taken;
    int xo;
    if (player == 1)
        xo = 'X';
    else
        xo = 'O';
    int pos;
    do
    {
        taken = false;
        cin >> pos;

        switch (pos)
        {
        case 1:
            if (board[0][0] == ' ')
                board[0][0] = xo;
            else
                taken = true;
            break;
        case 2:
            if (board[0][1] == ' ')
                board[0][1] = xo;
            else
                taken = true;
            break;
        case 3:
            if (board[0][2] == ' ')
                board[0][2] = xo;
            else
                taken = true;
            break;
        case 4:
            if (board[1][0] == ' ')
                board[1][0] = xo;
            else
                taken = true;
            break;
        case 5:
            if (board[1][1] == ' ')
                board[1][1] = xo;
            else
                taken = true;
            break;
        case 6:
            if (board[1][2] == ' ')
                board[1][2] = xo;
            else
                taken = true;
            break;
        case 7:
            if (board[2][0] == ' ')
                board[2][0] = xo;
            else
                taken = true;
            break;
        case 8:
            if (board[2][1] == ' ')
                board[2][1] = xo;
            else
                taken = true;
            break;
        case 9:
            if (board[2][2] == ' ')
                board[2][2] = xo;
            else
                taken = true;
            break;
        }
        if (taken)
            cout << "That spot is taken\n";
    } while (taken && pos>0 && pos < 9);
}

int line()
{
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][2] == board[i][1] &&
            board[i][0] != ' ')
            if (board[i][0] == 'X')
                return 1;
            else
                return 2;

    return 0;
}
int column()
{

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            if (board[0][i] == 'X')
                return 1;
            else
                return 2;
    return 0;
}
int diagonal()
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        if (board[0][0] == 'X')
            return 1;
        else
            return 2;
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][0] &&
             board[0][1] != ' ')
        if (board[0][0] == 'X')
            return 1;
        else
            return 2;
    return 0;
}
int winningPlayer()
{
    if (line() == 1 || column() == 1 || diagonal() == 1)
        return 1;
    else if (line() == 2 || column() == 2 || diagonal() == 2)
        return 2;
    return 0;
}

int main()
{
    bool won = false;
    drawBoard();
    int player = 1;
    while (!won)
    {
        cout << "Player " << player << ": ";
        inputXO(player);
        drawBoard();
        if (winningPlayer() == 1)
        {
            cout << "Player 1 has won!";
            won = true;
        }
        else if (winningPlayer() == 2)
        {
            cout << "Player 2 has won!";
            won = true;
        }
        if (player == 1)
            player++;
        else
            player--;
    }
}
