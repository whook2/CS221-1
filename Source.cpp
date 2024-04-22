/*
Will Hooker
8-24-2023
CS221
This program prompts the user to input data regarding a basketball player. Once all the data is recieved and stored in a structure, the program calls a function to calculate
the players points per game and minutes per game, and outputs the results. The program then asks if the user would like to test another player, and if not, terminates the program.
*/
#include <iostream>
#include <math.h>
using namespace std;

double ppg(int games, int fieldgoals, int threepoints, int freethrows); //declaration of points per game function
double mpg(int games, int mins); //declaration of minutes per game function

int main() {

	struct {						//declaring a structure to hold all of the records of a certain player. defaults name to unknown and all integer values to 0
		string fname = "unknown";	//strings to hold the players first and last name
		string lname = "unknown";
		int games = 0;				//integers to hold the games played, minutes played, baskets scored, etc
		int mins = 0;
		int fieldgoals = 0;
		int threepoints = 0;
		int freethrows = 0;
		int rebounds = 0;
		int assists = 0;
		int steals = 0;
	} player;
	
	char prompt = NULL;				//This character declaration is the yes or no prompt to determine if the program tests another player or not

	cout << "When prompted, please enter a basketball player's data in the form" << endl;
	cout << "firstname lastname gamesplayed minplayed fieldgoals threepoints freethrowsmade rebounds assists steals" << endl;
	cout << "For Example:" << endl << endl;
	cout << "Kevin Durant 35 1301 375 66 225 264 205 27" << endl << endl;

	do {							// a do-while loop to test the initial player, and then however many other players until the user prompts no
		cout << endl << "Enter player data: ";
			cin >> player.fname >> player.lname >> player.games >> player.mins >> //input for the player's data
			player.fieldgoals >> player.threepoints >> player.freethrows >>
			player.rebounds >> player.assists >> player.steals;
		
		cout << endl << player.fname << " " << player.lname << "'s Points per Game: " << //output for player's points per game. calls the points per game function and passes the information needed for calculation
			ppg(player.games, player.fieldgoals, player.threepoints, player.freethrows)
			<< endl;

		cout << "Minutes per Game: " << mpg(player.games, player.mins) << endl << endl; //output for player's minutes per game. calls the minutes per game function and passes the information needed for calculation
		
		cout << "Do you wish to test another? (y/n) "; //prompting the user if they would like to test another player
			cin >> prompt; 

	} while (prompt == 'y');
	
		cout << "Program Testing Complete" << endl;
	
	return 0;
}

double ppg(int games, int fieldgoals, int threepoints, int freethrows) { //points per game function

	double result = 0.0; //declaration of the resulting points per game

		result = ((((double)fieldgoals - (double)threepoints) * 2.0) + (threepoints * 3.0) + freethrows) / games; //calculating the points per game
	
	return result; //returning the result
}

double mpg(int games, int mins) { //minutes per game function

	double result = 0.0; //declaration of the resulting minutes per game

		result = (double)mins / (double)games; //calculating the minutes per game

	return result; //returning the result
}