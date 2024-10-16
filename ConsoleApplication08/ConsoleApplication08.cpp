// ConsoleApplication08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)
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
	short Month;
	cout << "\n Please enter a Month to check? ";
	cin >> Month;
	return Month;
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
short ReadDay()
{
	short Year;
	cout << "\n Please enter a Day to check? ";
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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}
#pragma endregion Calendar

#pragma  region ProblemsFrom11to20

struct stDate { short Year; short Month; short Day; };


stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	stDate Date;

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
	return Date;
}

stDate ReadFullDate() {
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IstDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IstDate1EqualDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsLastDay(stDate Date1)
{
	short numberOfda = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
	return  Date1.Day == numberOfda;
}

bool IsLastMonth(stDate Date1)
{
	return  Date1.Month == 12 ? true : false;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDay(Date))
	{
		if (IsLastMonth(Date))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

void  SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate;
	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;
	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;
	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0; short SawpFlagValue = 1;
	if (!IstDate1BeforeDate2(Date1, Date2)) {
		//Swap Dates     
		SwapDates(Date1, Date2);
		SawpFlagValue = -1;
	}
	while (IstDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	} //last check day in date should not exceed max days in the current month// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

stDate IncreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByXMonths(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year += Years;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	//Period of 10years 
	Date.Year += 10; return Date;
}

stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	//Period of 100 years
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	//Period of 1000 years
	Date.Year += 1000; return Date;
}


stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12; Date.Day = 31; Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else {
		Date.Day--;
	} return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	} return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}



stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1) { Date.Month = 12; Date.Year--; }
	else
		Date.Month--; //last check day in date should not exceed max days in the current month// example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year); if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	} return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate
	Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	} return Date;
}


stDate DecreaseDateByOneYear(stDate Date) { Date.Year--; return Date; }
stDate DecreaseDateByXYears(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year -= Years; return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{
	//Period of 10years
	Date.Year -= 10;
	return Date;
}
stDate DecreaseDateByXDecades(short Decade, stDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year -= Decade * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	//Period of 100 years
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	//Period of 1000 years 
	Date.Year -= 1000;
	return Date;
}
short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

short IsEndOfWeek(stDate Date)
{
	return  DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{ //Weekends are Fri and Sat
	short DayIndex = DayOfWeekOrder(Date);
	return  (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{ //Weekends are Sun,Mon,Tue,Wed and Thur/* 
	/*short DayIndex = DayOfWeekOrder(Date);
	return  (DayIndex >= 5 && DayIndex <= 4);*/

	//shorter method is to invert the IsWeekEnd: this will save updating code.
	return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date1)
{
	stDate EndOfMontDate;
	EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
	EndOfMontDate.Month = Date1.Month;
	EndOfMontDate.Year = Date1.Year;
	return GetDifferenceInDays(Date1, EndOfMontDate, true);
}

short DaysUntilTheEndOfYear(stDate Date1)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date1.Year;
	return GetDifferenceInDays(Date1, EndOfYearDate, true);
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			DaysCount++;
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	return DaysCount;
}


stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{

	short WeekEndCounter = 0;

	//in case the data  is weekend keep adding one day util you reach business day
	//we get rid of all weekends before the first business day
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//here we increase the vacation dates to add all weekends to it.

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{

		if (IsWeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//in case the return date is week end keep adding one day util you reach business day
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}


enum enDateCompare { Before = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;
	/*if (IsDate1AfterDate2(Date1, Date2))
		return enDateCompare::After;*/
		//this is faster
	return enDateCompare::After;
}

struct stPeriod { stDate StartDate; stDate EndDate; };

stPeriod ReadPeriod() {
	stPeriod Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before || CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
		return false;
	else
		return true;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

bool PeriodLengthInDays(stPeriod Period, stDate date1)
{
	if (CompareDates(Period.StartDate, date1) == enDateCompare::Before && CompareDates(Period.EndDate, date1) == enDateCompare::After)
		return true;

	return false;
}

bool isDateInPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before || CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	short OverlapDays = 0;

	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (isDateInPeriod(Period1.StartDate, Period2))
				OverlapDays++;
			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}

	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (isDateInPeriod(Period2.StartDate, Period1))
				OverlapDays++;
			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverlapDays;
}

bool isValitDate(stDate date)
{
	short NumberofDays = NumberOfDaysInAMonth(date.Month, date.Year);

	if (0 > date.Day || date.Day > NumberofDays)
		return false;

	if (date.Month > 12 || date.Month < 0)
		return false;

	return true;

}

bool IsValidDate2(stDate Date)
{
	if (Date.Day < 1 || Date.Day>31)
		return false;
	if (Date.Month < 1 || Date.Month>12)
		return false;
	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}
	short DaysInMonth = NumberOfDaysInAMonth(Date.Month,
		Date.Year);
	if (Date.Day > DaysInMonth)
		return false;
	return true;
}
short ReadDay()

#pragma endregion ProblemsFrom11to20

int main()
{
	std::cout << "Hello World!\n";


	//stPeriod date1 = ReadPeriod();
	stDate date2 = ReadFullDate();
	//int Month = ReadMonth();
	//int Day = ReadDay();
	cout << isValitDate(date2);
	//cout << to_string(NumberOfDaysFromTheBeginingOfTheYear(year, Month, Day));
	//cout << GetDayName(Number);
	//PrintAllMonth(year);
	//GetDeitles(year, Month, Day);

	//cout << to_string(GetDifferenceInDays(date1, date2));
	/*stDate Date1 = ReadFullDate();
	if (IsLastDay(Date1))
		cout << "\n Yes Is last day";
	else
		cout << "\n no Is not last day";

	if (IsLastMonth(Date1))
		cout << "\n Yes Is last Month";
	else
		cout << "\n no Is not last Month";*/
		/*stDate Date2 = ReadFullDate();
		if (IstDate1BeforeDate2(Date1, Date2))
			cout << "\nYes, Date1 is Less than Date2.";
		else
			cout << "\nNo, Date1 is NOT Less than Date2.";*/

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
