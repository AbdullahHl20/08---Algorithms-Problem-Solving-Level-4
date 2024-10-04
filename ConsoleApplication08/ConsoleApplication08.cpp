// ConsoleApplication08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int ReadNumber() {
	int Number;
	cout << "\nEnter a Number? ";
	cin >> Number; return Number;
}


string NumberToText(int  Number) {
	if (Number == 0)
	{
		return"";
	}
	if (Number >= 1 && Number <= 19) {
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return  arr[Number] + " ";
	}
	if (Number >= 20 && Number <= 99) {
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return  arr[Number / 10] + " " + NumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 199) { return"One Hundred " + NumberToText(Number % 100); } if (Number >= 200 && Number <= 999) { return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100); } if (Number >= 1000 && Number <= 1999)
	{
		return"One Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{
		return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999)
	{
		return"One Million " + NumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999) { return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000); }
	if (Number >= 1000000000 && Number <= 1999999999) { return"One Billion " + NumberToText(Number % 1000000000); }
	else { return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000); }
}

#pragma region LeapYear

bool IsLeapYear(short Year)
{ // leap year if perfectly divisible by 400
	//if (Year % 400 == 0) { return true; } // not a leap year if divisible by 100
	//// but not divisible by 400
	//else if (Year % 100 == 0) { return false; } // leap year if not divisible by 100// but divisible by 4e
	//else if (Year % 4 == 0) { return true; } // all other years are not leap years
	//else { return false; }

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}
short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}

#pragma endregion LeapYear


#pragma region YearInSec

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}
short NumberOfHoursInAYear(short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
	return NumberOfHoursInAYear(Year) * 60;
}
int NumberOfSecondsInAYear(short Year)
{
	return NumberOfMinutesInAYear(Year) * 60;
}

#pragma endregion

#pragma region MonthiSec

short ReadMonth()
{
	short Year;
	cout << "\nPlease enter a Month to check? ";
	cin >> Year;
	return Year;
}

short NumberOfDaysInAMonth(short Month, short Year) {
	/*if (Month < 1 || Month>12)
		return  0;
	if (Month == 2)
	{
		return  IsLeapYear(Year) ? 29 : 28;
	}
	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;*/
			//} //if you reach here then its 30 days.return  30; } 
	if (Month < 1 || Month>12)
		return 0;
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31
	};
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

short NumberOfHoursInAMonth(short Month, short Year)
{
	return  NumberOfDaysInAMonth(Month, Year) * 24;
}
int NumberOfMinutesInAMonth(short Month, short Year)
{
	return  NumberOfHoursInAMonth(Month, Year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short Year)
{
	return  NumberOfMinutesInAMonth(Month, Year) * 60;
}

#pragma endregion

#pragma region DayName
short ReaDay()
{
	short Year;
	cout << "\nPlease enter a Day to check? ";
	cin >> Year;
	return Year;
}



string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return arrDayNames[DayOfWeekOrder + 1];
}

#pragma endregion DayName


short GetDayOfWeek(string Day)
{
	string NameOfdays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	for (int i = 0; i < NameOfdays->length(); i++)
	{
		if (NameOfdays[i] == Day)
			return i;
	};
	return 0;
}

void PrintDate(int Year, int Month, int Day)
{
	cout << Day << "/" << Month << "/" << Year;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void  GetDeitles(int Year, int Month, int Day)
{


	PrintDate(Year, Month, Day);

	cout << "\n" << DayShortName(DayOfWeekOrder(Year, Month, Day));
	cout << " \n" << to_string(GetDayOfWeek(DayShortName(DayOfWeekOrder(Year, Month, Day))));
}
#pragma region Calendar
string MonthShortName(short MonthNumber)
{
	string Months[12] = { "Jan", "Feb", "Mar",
	"Apr", "May", "Jun",
	"Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
	};
	return (Months[MonthNumber - 1]);
}
void PrintMonthCalendar(short Month, short Year)
{
	int NumberOfDays;
	// Index of the day from 0 to 6
	int current = DayOfWeekOrder(1, Month, Year);
	NumberOfDays = NumberOfDaysInAMonth(Month, Year);
	// Print the current month name
	printf("\n _______________%s_______________\n\n",
		MonthShortName(Month).c_str());
	// Print the columns
	printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	// Print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
		printf("    ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n _________________________________\n");
}
void PrintAllMonth(short Year)
{
	printf("           Calendar - %d\n", Year);
	printf("  _________________________________\n");
	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);
	}
	return;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0; for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}
#pragma endregion Calendar

#pragma  region ProblemsFrom#11to#20

struct sDate { short Year; short Month; short Day; };


sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;

	short RemainingDays = DateOrderInYear;

	short MonthDays = 0;
	Date.Year = Year;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

#pragma endregion ProblemsFrom#11to#20

	int main()
	{
		std::cout << "Hello World!\n";


		int year = ReadYear();
		int Month = ReadMonth();
		int Day = ReaDay();

		cout << to_string(NumberOfDaysFromTheBeginingOfTheYear(year, Month, Day));
		//cout << GetDayName(Number);
		//PrintAllMonth(year);
		//GetDeitles(year, Month, Day);
		system("pause>0");
		return 0;
	}

	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
