// CH4_EX14.cpp : Defines the entry point for the console application.
// Tiara Dalton

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double REG_SERVICE = 10.00;
const int REG_FREE_MIN = 50;
const double REG_OVER_50_MIN = 0.20;

const double PREM_SERVICE = 25.00;
const int PREM_DAY_FREE_MIN = 75;
const double DAY_OVER_75_MIN = 0.10;
const int PREM_NIGHT_FREE_MIN = 100;
const double NIGHT_OVER_100_MIN = 0.05;



int main()
{
	int AccountNo;
	char ServiceType;
	int MinutesUsed;
	int PM_MinutesUsed;

	double AmntDue;

	cout << fixed << showpoint << setprecision(2);
	cout << "Enter account number: ";
	cin >> AccountNo;
	cout << endl;

	cout << "Enter service type: (r or R) for regular, (p or P) for premium service: ";
	cin >> ServiceType;
	cout << endl;

	switch (ServiceType)
	{
		case 'r':
		case 'R':
			cout << "Enter number of minutes service used: ";
			cin >> MinutesUsed;
			cout << endl;
			cout << "Account Number: " << AccountNo << endl;
			cout << "Service Type: Regular" << endl;
			cout << "Minutes Service Used: " << MinutesUsed << endl;
				if (MinutesUsed >= 50)
					AmntDue = REG_SERVICE + ((MinutesUsed - REG_FREE_MIN)*REG_OVER_50_MIN);
				else
					AmntDue = REG_SERVICE;
			cout << "Amount Due: $" << AmntDue << endl;
			break;
		case 'p':
		case 'P':
			cout << "Enter day time minutes used: ";
			cin >> MinutesUsed;
			cout << endl;
			cout << "Enter night time minutes used: ";
			cin >> PM_MinutesUsed;
			cout << endl;
			cout << "Account Number: " << AccountNo << endl;
			cout << "Service Type: Premiun" << endl;
			cout << "Minutes Service Used (Day): " << MinutesUsed << endl;
			cout << "Minutes Service Used (Night): " << PM_MinutesUsed << endl;
				if (MinutesUsed >= 75 && PM_MinutesUsed >= 100)
				AmntDue = PREM_SERVICE + ((MinutesUsed - PREM_DAY_FREE_MIN)*DAY_OVER_75_MIN) + ((PM_MinutesUsed - PREM_NIGHT_FREE_MIN)*NIGHT_OVER_100_MIN);
				else if (MinutesUsed >=75 && PM_MinutesUsed < 100)
				AmntDue = PREM_SERVICE + ((MinutesUsed - PREM_DAY_FREE_MIN)*DAY_OVER_75_MIN);
				else if (MinutesUsed < 75 && PM_MinutesUsed >= 100)
					AmntDue = PREM_SERVICE + ((PM_MinutesUsed - PREM_NIGHT_FREE_MIN)*NIGHT_OVER_100_MIN);
				else
					AmntDue = PREM_SERVICE;
			cout << "Amount Due: $" << AmntDue << endl;
			break;
		default:
			cout << "Invalid Service Type." << endl;

	} //end switch
	

	system("pause");


    return 0;
}

