//==========================================
//Title: Theater Seating Program
//Author: Jason Nelson, Leanne Keenan, 
// Brandy London, Alan Dunaway, Luis Campos
// Learning Team: A
//Date:   22 June 2017
//==========================================
#pragma once
#ifndef CHART_H
#define CHART_H

using namespace std;

class Chart
{
public:
	// declares what we will be using.
	void ChartDisplay(string pseats_display[12][10], int *choice1, int *choice2);
	void SeatsAvailability(string pseats_display[12][10]);
	void SetPurchase(int *many_tickets,int *choice1,int *choice2, string pseats_display[12][10]);

};

#endif