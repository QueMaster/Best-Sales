// BestSales.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	const int SIZE = 12;
	double highestSales = 0;
	string company = "";
	double bestSales = 0;
	string highestSalesMonth = "";
	double total[SIZE] = {};
	int monthNum = 0;
	double vodacom[SIZE] = {
	
		13000.00, 21000.00, 45000.00, 33000.00, 78000.00, 65000.00,
		24000.00, 98000.00, 53000.00, 45980.00, 76654.00, 44636.00,
	};

	double cellc[SIZE] = {
	
		23000.00, 31000.00, 15000.00, 03000.00, 48000.00, 25000.00,
		24640.00, 98770.00, 58900.00, 45970.00, 74554.00, 89636.00,
	};

	double mtn[SIZE] = {
	
		20000.00, 39000.00, 80000.00, 78000.00, 90000.00, 12600.00,
		94640.00, 78770.00, 48900.00, 85970.00, 94554.00, 80936.00,
	};

	string months[SIZE] = {
		
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	for (int i = 0; i < SIZE-1; i++)
	{
		total[i] = vodacom[i] + cellc[i] + mtn[i];

		if (vodacom[i] > cellc[i] && vodacom[i] > mtn[i])
		{
			highestSales = vodacom[i];
			highestSalesMonth = months[i];
		}else if (cellc[i] > vodacom[i] && cellc[i] > mtn[i])
		{
			highestSales = cellc[i];
			highestSalesMonth = months[i];
		} else if (mtn[i] > cellc[i] && mtn[i] > vodacom[i])
		{
			highestSales = mtn[i];
			highestSalesMonth = months[i];
		}
	}

	cout << "The hiegest sales was obtained in " << highestSalesMonth << endl;
	cout << "Enter a month number to search (0-11: index): ";
	cin >> monthNum;

	if (vodacom[monthNum] > cellc[monthNum] && vodacom[monthNum] > mtn[monthNum])
	{
		bestSales = vodacom[monthNum];
		company = "Vodacom";
	} else if (cellc[monthNum] > vodacom[monthNum] && cellc[monthNum] > mtn[monthNum])
	{
		bestSales = cellc[monthNum];
		company = "Cell C";
	} else if (mtn[monthNum] > cellc[monthNum] && mtn[monthNum] > vodacom[monthNum])
	{
		bestSales = mtn[monthNum];
		company = "MTN";
	}

	cout<< "The best sales for " << months[monthNum] << " was " << company << " (R" << bestSales << ")" << endl;

	system("pause");
	return 0;
}