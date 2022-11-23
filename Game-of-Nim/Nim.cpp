/*
 * Course: CS215-003
 * Project: Project2
 * File: Nim.cpp
 * Purpose: it declares the class named Nim
 * Name: Tanner Fox
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;

//default constructor
Nim::Nim()
{
	pileSize = 0;
}

//constructor
Nim::Nim(int iniSize)
{
	pileSize = iniSize;
}

//set the current size of the pile 
void Nim::setPileSize(int size)
{
	pileSize = size;
}

//get how many marbles on the pile
int Nim::getPileSize() const
{
	return pileSize;
}

/*
 * It represents the legal move when it is the computer's turn to play
 *               computer's legal move is under either smart-move or
 *               non-smart-move depending on the parameter named smart
 * (Note that the private data member, pileSize, will be modified)
 *@param smart bool: representing the computer takes smart move (if true)
 *                   or non-smart move (if false)
 *@return: void function
 */
 //if it is computer's turn to play
 //it is either under smart mode or non-smart mode
void Nim::computer_play(bool smart)
{	
	// Initialize the amount of marbles that are to be taken from the pile by the computer
	// Initialize the power of two to be used in calculations
	int taken_marbles = 0;
	int power_of_two = 2;
	// if the computer is playing smart
	if (smart == true)
	{
		// loop through the powers of two to determine if the pile size is equal to it
		while (power_of_two < pileSize)
		{
			power_of_two = power_of_two * 2;
		}
		power_of_two = (power_of_two / 2) - 1;
		// if the pile size is equal to a power of two -1 then take at least one but at most half of the marbles 
		if (pileSize == power_of_two)
		{
			taken_marbles = rand() % (pileSize / 2) + 1;
		}
		else
		{
			// else take off enough marbles for it to equal the to one of the power of twos -1
			taken_marbles = pileSize - power_of_two;
		}
	}
	// if the computer is playing not smart
	else
	{
		// taken marbles are equal to a random number taking at least one but at most half of the marbles
		taken_marbles = rand() % (pileSize / 2) + 1;
	}
	int newSize = pileSize - taken_marbles;
	setPileSize(newSize);
	cout << "The Computer takes " << taken_marbles << " marbles." << endl;
}

/*
 * It represents the legal move when it is the user's turn to play the game
 *    (it should repeatedly ask the user to enter how many marbles to take
 *                          until the user makes a legal move.)
 * (Note that the private data member, pileSize, will be modified)
 *@return: void function
 */
//if it is player's (the user's) turn to play
void Nim::player_play()
{	
	// Initialize the max amount that can be taken 
	// Initialize the validation variable
	// define the user input
	int maxAmount = getPileSize() / 2;
	bool valid_input = false;
	int user_input;
	// Do while loop for input validation
	do
	{
		cout << "Your play .. you may take 1 to " << maxAmount << " marbles." << endl;
		cout << "You take: ";
		cin >> user_input;
		// if the user inputs letters instead of numbers then give error
		if (cin.fail())
		{
			cin.clear();
			cout << "Invalid! Please try again..." << endl;
			valid_input = false;
		}
		// else if the user inputs the wrong range
		else if (user_input < 1 || user_input > maxAmount)
		{
			cout << "Oops, you picked too many or not enough." << endl << "Please try again..." << endl;
			valid_input = false;
		}
		// else the number is valid then break the loop
		else
		{
			valid_input = true;
		}
		cin.ignore(256, '\n');
	} while (valid_input == false);
	// output how many marbels the user will take based on their input
	cout << "You will take " << user_input << " marbles." << endl;
	// calculate what the new pile size is
	pileSize = pileSize - user_input;
}

//display the current marbles on the pile
void Nim::print() const
{
	cout << "There are " << pileSize << " marbles in the pile." << endl;
	for (int i = 0; i < pileSize; i++)
	{
		cout << setw(WIDTH) << MARBLE << endl;
	}
}
