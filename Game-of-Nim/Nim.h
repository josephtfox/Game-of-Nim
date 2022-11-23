#pragma once
/*
 * Course: CS215-003
 * Project: Project 2
 * File: Nim.h
 * Purpose: it declares the class named Nim
 * Author: Tanner Fox
 */
#ifndef NIM_H
#define NIM_H

const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose

class Nim
{
public:
	//default constructor
	Nim();

	//constructor
	Nim(int iniSize);

	//set the current size of the pile 
	void setPileSize(int size);

	//get how many marbles on the pile
	int getPileSize() const;

	/*
	* It represents the legal move when it is the computer's turn to play
	* computer's legal move is under either smart-move or
	* non-smart-move depending on the parameter named smart
	* (Note that the private data member, pileSize, will be modified)
	*@param smart bool: representing the computer takes smart move (if true)
	 * or non-smart move (if false)
	*@return: void function
	*/
	//if it is computer's turn to play
	//it is either under smart mode or non-smart mode
	void computer_play(bool smart);

	/*
	* It represents the legal move when it is the user's turn to play the game
	* (it should repeatedly ask the user to enter how many marbles to take
	* until the user makes a legal move.)
	* (Note that the private data member, pileSize, will be modified)
	*@return: void function
	*/
	//if it is player's (the user's) turn to play
	void player_play();

	//display the current marbles on the pile
	void print() const;

private:
	int pileSize;	// represents how many marbles on the 
};
#endif	/* NIM_H */