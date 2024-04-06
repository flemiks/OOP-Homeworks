/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <functional>
#include <stdexcept>
#include <iomanip>
#include <array>

using namespace std;

//----------Task1----------------
constexpr int MONTHS_IN_YEAR = 12;
constexpr array<int, MONTHS_IN_YEAR> DAYS_IN_MONTH = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date(int day, int month, int year) : day(day), month(month), year(year) {
		if (year < 0) throw invalid_argument("Year cannot be less than 0");
		if (month < 1 || month > 12) throw invalid_argument("Month must be between 1 and 12");
		if (day < 1 || day > getMaxDayInMonth(month, year)) throw invalid_argument("Invalid day for given month and year");
	}

	int getYear() const {
		return year;
	}

	int getMonth() const {
		return month;
	}

	int getDay() const {
		return day;
	}

	void print() const {
		cout << "Year: " << year << ", Month: " << month << ", Day: " << day << endl;
	}

	static int getMaxDayInMonth(int month, int year) {
		if (month == 2) {
			return isLeapYear(year) ? 29 : 28;
		}
		return DAYS_IN_MONTH[month - 1];
	}

	static bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	friend Date operator+(const Date& date, int days);
	friend int operator-(const Date& date1, const Date& date2);
};

Date operator+(const Date& date, int daysToAdd) {
	int day = date.getDay();
	int month = date.getMonth();
	int year = date.getYear();

	day += daysToAdd;
	while (day > Date::getMaxDayInMonth(month, year)) {
		day -= Date::getMaxDayInMonth(month, year);
		month++;
		if (month > MONTHS_IN_YEAR) {
			month = 1;
			year++;
		}
	}

	return Date(day, month, year);
}

int operator-(const Date& date1, const Date& date2) {
	auto toDays = [](const Date& date) {
		int days = date.getYear() * 365 + date.getDay();
		for (int m = 1; m < date.getMonth(); ++m) {
			days += Date::getMaxDayInMonth(m, date.getYear());
		}
		return days;
		};

	return toDays(date1) - toDays(date2);
}

//----------Task2----------------

class CustomString {
private:
	string str1;
	string str2;
	string commonCharacters;

public:
	CustomString(string str1, string str2) {
		setStr1(str1);
		setStr2(str2);
		commonCharacters = "";
	}
	void setStr1(string str) {
		if (str.size() == 0) {
			throw invalid_argument("String should contain at least 1 character");
		}
		str1 = str;
	}
	string getStr1() {
		return str1;
	}
	void setStr2(string str) {
		if (str.size() == 0) {
			throw invalid_argument("String should contain at least 1 character");
		}
		str2 = str;
	}
	string getStr2() {
		return str2;
	}
	string findCommonCharacters() {
		commonCharacters = "";
		for (char c1 : str1) {
			for (char c2 : str2) {
				if (c1 == c2 && commonCharacters.find(c2) == string::npos) {
					commonCharacters += c2;
					break;
				}
			}
		}
		return commonCharacters;
	}

	void print() {
		cout << "String1: " << str1 << ", String2: " << str2 << ", Common String for both strings: " << commonCharacters << endl;
	}
};



int main()
{
	Date d1(10, 12, 2023);
	Date d2(18, 01, 2022);

	Date d3 = d1 + 181;
	d3.print();
	int days = d1 - d2;
	cout << days;
	cout << endl;
	CustomString myString("ffgrtd", "hgfqast");
	myString.findCommonCharacters();
	myString.print();
	return 0;

}*/