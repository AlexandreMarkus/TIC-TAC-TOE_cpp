#include <iostream>
using namespace std;

char boardGame[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int win[8][3] = {{0, 1, 2}, // Check first row.
                {3, 4, 5}, // Check second Row
                {6, 7, 8}, // Check third Row
                {0, 3, 6}, // Check first column
                {1, 4, 7}, // Check second Column
                {2, 5, 8}, // Check third Column
                {0, 4, 8}, // Check first Diagonal
                {2, 4, 6}}; // Check second Diagonal

void display()
{
    cout << endl << "   |   |   \n";
    cout << " " << boardGame[0] << " | " << boardGame[1] << " | " << boardGame[2] << endl;
    cout << "---|---|---\n";
    cout << " " << boardGame[3] << " | " << boardGame[4] << " | " << boardGame[5] << endl;
    cout << "---|---|---\n";
    cout << " " << boardGame[6] << " | " << boardGame[7] << " | " << boardGame[8] << endl;
    cout << "   |   |   \n" << endl;
}

void verifyPlay(char numberToReplace, bool player1Turn)
{
    int index = (numberToReplace - '0') - 1;
    if (boardGame[index] != 'x' and boardGame[index] != 'o')
    {
        if (player1Turn)
        {
            boardGame[index] = 'x';
        }
        else
        {
            boardGame[index] = 'o';
        } 
    }
}

bool verifyWin(bool player1Turn)
{
    char token;
    if (player1Turn)
    {
        token = 'x';
    }
    else
    {
        token = 'o';
    }
    
    for (int i = 0; i < 8; i++)
    {
        if (boardGame[win[i][0]] == token &&
            boardGame[win[i][1]] == token &&
            boardGame[win[i][2]] == token )
            return true;
    }
    return false;
}

void play(string player1, string player2)
{
    bool gameFinished = false;
    bool player1Turn = true;
    for (int i = 0; i < 9; i++)
    {
        char input;
        if (player1Turn)
        {
            cout << player1 << " (x) enter a valid number: ";
        }
        else
        {
            cout << player2 << " (o) enter a valid number: ";
        }
        
        cin >> input;
        verifyPlay(input, player1Turn);
        display();
        gameFinished = verifyWin(player1Turn);
        if (gameFinished)
        {
            break;
        }
        player1Turn = !player1Turn;        
    }
    if (gameFinished)
    {
        if (player1Turn)
        {
            cout << player1 << " won!\n";
        }
        else
        {
            cout << player2 << " won!\n";
        }
    }
    else
    {
        cout << "Game is tie!!\n";
    }
    
    
}

int main()
{
    string player1 = "";
    string player2 = "";

    cout << "Enter name of player 1: ";
    getline(cin, player1);
    cout << "Enter name of player 2: ";
    getline(cin, player2);

    display();
    play(player1, player2);
}