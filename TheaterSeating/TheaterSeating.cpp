//==========================================
//Title: Theater Seating Program
//Author: Jason Nelson, Leanne Keenan, 
// Brandy London, Alan Dunaway, Luis Campos
// Learning Team: A
//Date:   22 June 2017
//==========================================
#include <iostream>
#include <string>
#include "windows.h"
// include the header file for the bulk of the program
#include "Chart.h"

// using namespace std to avoid having to type std:: every few lines for standard stuff like cout.
using namespace std;



// main entry point
int main()
{
	// declare variables and pointers we will be using.
	string seats_display[12][10];
	int many_tickets = 0;
	int choice1 = 0;
	int choice2 = 0;
	char loop_choice;
	// assigns a pointer to our string array
	string (*pseats_display)[12][10] = &seats_display;

	
	
	cout << "This is a theater ticket selling program." << endl;
	// put the user in a do / while loop until they wish to stop buying tickets
	do
	{
		
		// instantiate the Chart class
		Chart c;

		cout << "How many tickets would you like to purchase? They are currently $45.99" << endl;
		// gathers how many tickets the user wants to buy
		cin >> many_tickets;
		// calls ChartDisplay in Chart.cpp and lets it run through and then calls SetPurchase also in Chart.cpp (check header file to see declarations)
		c.ChartDisplay(*pseats_display, &choice1, &choice2);
		// calls SetPurchase
		c.SetPurchase(&many_tickets, &choice1, &choice2, *pseats_display);
		// clears the screen to avoid crowding
		system("cls");
		// calls ChartDisplay with the new data gathered from SetPurchase, a new chart will be drawn.
		c.ChartDisplay(*pseats_display, &choice1, &choice2);
		// calls SeatsAvailability, which displays useful information such as total ticket sales.
		c.SeatsAvailability(*pseats_display);
		cout << "Would you like to buy more tickets? y/n" << endl;
		// if the user chooses 'n' they will exit the program
		cin >> loop_choice;
	} while (loop_choice == 'y');
	cout << "Thank you for using the theater ticket selling program." << endl;
	system("pause");
    return 0;
}

