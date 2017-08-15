//==========================================
//Title: Theater Seating Program
//Author: Jason Nelson, Leanne Keenan, 
// Brandy London, Alan Dunaway, Luis Campos
// Learning Team: A
//Date:   22 June 2017
//==========================================
#include <iostream>
#include <string>
#include "Chart.h"

using namespace std;

// draws the initial blank seating chart as well as any purchased seats in the chart later when called further into the program
void Chart::ChartDisplay(string pseats_display[12][10], int *choice1, int *choice2)
{
	// runs through two for loops to ensure both rows and columns are filled out
	// cleans up and lines up all elements ensuring no misplaced numbers
	for (int k = 0; k < 11; k++)
	{
		// Places the R to show rows much like the example in the class syllabus
		if (k != 0)
		{
			cout << " " << "R" << k;
		}
		// if it's not the beginning of this, it won't be an R
		else
		{
			cout << "  " << k;
		}
	
		for (int i = 1; i < 10; i++)
		{
			// checks if the choices are blank, if so it will place an available seat there.
			if (*choice1 == 0 && *choice2 == 0)
			{
				pseats_display[k][i] = "#";
			}
			// This ensures that the table is properly lined up and the top row of numbers doesn't end up in any of the rows.
			if (i >= 1 && k >= 1 && k != 10)
			{
				if (i == 1)
				{
					cout << " ";
				}
				cout << " " << pseats_display[k][i];
			}
			else
			{
				// spaces out row 10 and properly writes this row (if this wasn't here it would have the column numbers showing up in row 10 also)
				if (k == 10 && i >= 1)
				{
					cout << " " << pseats_display[k][i];
				}
				else
				{
					if (i == 1)
					{
						cout << " ";
					}
					cout << " " << i;
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Chart::SeatsAvailability(string pseats_display[12][10])
{
	// declare variables
	double total_sales = 0;
	int open_seats = 0;
	// two for loops to fill out the 12 by 10 chart. 
	for (int l = 1; l < 11; l++)
	{
		for (int m = 1; m < 10; m++)
		{
			if (pseats_display[l][m] == "#")
			{
				// increments open_seats to get an accurate count of available seats left
				open_seats++;

			}
		}
	}
	// subtracts open_seats from 90 (there are a total of 90 seats) and multiplies by the ticket price to get the 
	// total amount spent on tickets.
	total_sales = 45.99 * (90 - open_seats);
	// displays useful information such as ticket sales, seats sold, and seats available
	cout << "Total in ticket sales $" << total_sales << endl;
	cout << "Total seats sold " << 90 - open_seats << endl;
	cout << "Total seats available " << open_seats << endl;
}

void Chart::SetPurchase(int *many_tickets, int *choice1, int *choice2, string pseats_display[12][10])
{
	// runs a for loop based on how many tickets the user wants to buy
	for (int k = 1; k <= *many_tickets; k++)
	{
		// puts the user in a do / while to check to see if that seat was already sold
		// if true then the user will have to input a different seat
		do
		{
			cout << "What row would you like for ticket number #" << k << endl;
			cin >> *choice1;
			cout << "What column would you like?" << endl;
			cin >> *choice2;
			cout << endl;
			if (pseats_display[*choice1][*choice2] == "*")
			{
				cout << "Please choose another seat, this one is already sold." << endl;
			}
		} while (pseats_display[*choice1][*choice2] == "*");
		// sets the seat as sold in the array
		pseats_display[*choice1][*choice2] = "*";
		
	}
	
}