/*
ES1036b: Lab 06 Q1
Date : Nov 10, 2017
Name: Amanpreet Gill
Student Number : 250964445
uwo: agill292@uwo.ca
Program’s mission : program that rolls 0, 1, or 2 dice at a time to reach a total dice value of 50
*/

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

int rollDice(int numberOfDice) {
	int x, value;
	//FIX...MUST RECORD TOTAL  1 + rand() % 6
	cout <<  "Total number of dice rolled so far: " << numberOfDice << endl;
	for (int i = 1; i < numberOfDice; i++) {
		value = 0;
		value = 1 + rand() % 6;
		cout << "The result of the current roll is: " << value << endl;
		x++;

	}

}

int main()
{
	int dice, results;

	cout << "The goal is a score of: 50" << endl;
	//TELL SCORE
	do {
		cout << "How many dice would you like to roll (0,1,2): " << endl;
		cin >> dice;
	} while ((dice != 0) && (dice != 1) && (dice != 2));
	
	results = rollDice(dice);

    return 0;
}

