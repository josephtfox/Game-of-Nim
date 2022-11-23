/*
 *Course: CS215 - 003
 *Project: Project 2
 *Purpose: It demonstrates the game of Nim played between two computer players
 *         In combinatorial game theory, a two-player deterministic perfect information turn-based game
 *         is a first-player-win if with perfect play the first player to move can always force a win.
 *         This program also shows that the game of Nim is a first-player-win game using two computer players.
 *Author: Tanner Fox
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;

int main()
{
    int seed = static_cast<int>(time(0));
    srand(seed);

    // Generate the initial size of pile (of marbles)
    // at the range of [PILE_MIN, PILE_MAX]
    // for testing purpose only: we set the initial size of pile to a constant PILE_MAX
    //int pileSize = PILE_MAX;

    // comment out the testing purpose at line number 27, enable the following statement, which is the general case
    int pileSize = PILE_MIN + rand() % (PILE_MAX - PILE_MIN + 1);

    // create a Nim object with initial pile size = pileSize
    Nim NimGame(pileSize);

    //Initializes then bool if the computer gets to play first or if the user gets to play first
    bool computer_turn = true;
    //Initalizes the bool for the computers smart or non-smart play
    bool smart = true;

    // generates 0 or 1 to determine if the computer is is smart or non-smart mode 
    // generated 0 or 1 to determine if the user or the computer gets to go first
    int smart_num = rand() % 2;
    int turn_num = rand() % 2;

    if (turn_num == 0)
    {
        computer_turn = true;
    }
    else
    {
        computer_turn = false;
    }
    if (smart_num == 0)
    {
        smart = true;
    }
    else
    {
        smart = false;
    }

    cout << "*****************************************************" << endl;
    cout << "*                The game of Nim                    *" << endl;
    cout << "*    Players alternate taking at least one but at   *" << endl;
    cout << "*    most half of the marbles in the pile.          *" << endl;
    cout << "*    The player who takes the last marble loses.    *" << endl;
    cout << "*    It is written by Tanner Fox                       *" << endl;
    cout << "*    I hope you beat the computer:)                 *" << endl;
    cout << "*    No matter what, have a great day.              *" << endl;
    cout << "*****************************************************" << endl;

    // To determine if the user plays first or if the computer plays first 
    // To determine if the computer is playing in smart mode or not
    if (!computer_turn)
    {
        cout << "You will play first." << endl;
    }
    else
    {
        cout << "The Computer will play first." << endl;
    }
    if (!smart)
    {
        cout << "The Computer will not play smart." << endl;
    }
    else
    {
        cout << "The Computer will play smart." << endl;
    }

    while (NimGame.getPileSize() > 1)
    {
        NimGame.print();
        if (computer_turn) //it is the computers turn to play
        {
            cout << "Computer plays:" << endl;
            NimGame.computer_play(smart);
        }
        else   // it is the users turn to play
        {
            NimGame.player_play();
        }

        computer_turn = !computer_turn;
    }

    //check the which one has to take the last marble to lose the game
    if (computer_turn)  // Computers turn
    {
        cout << "Computer must take the last marble. "
            << "You win!" << endl;
    }
    else   // User's turn
    {
        cout << "You must take the last marble. "
            << "You lose!" << endl;
    }
    return 0;
}