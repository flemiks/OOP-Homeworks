#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <functional>
#include <stdexcept>
#include <iomanip>
#include <array>


//80% реалізації взято з передостанньої практичної

using namespace std;


constexpr int MONTHS_IN_YEAR = 12;
constexpr array<int, MONTHS_IN_YEAR> DAYS_IN_MONTH = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date(int day, int month, int year) {
		setYear(year);
		setMonth(month);
		setDay(day);
	}

	int getYear() const {
		return year;
	}
	void setYear(int year) {
		if (year < 0) {
			throw invalid_argument("Year cannot be less than 0");
		}
		this->year = year;
	}
	int getMonth() const {
		return month;
	}
	void setMonth(int month) {
		if (month < 1 || month > 12) {
			throw invalid_argument("Month must be between 1 and 12");
		}
		this->month = month;
	}
	int getDay() const {
		return day;
	}
	void setDay(int day) {
		if (day < 1 || day > getMaxDayInMonth(month, year)) {
			throw invalid_argument("Invalid day for given month and year");
		}
		this->day = day;
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
	friend Date operator+(int daysToAdd, const Date& date);
	friend int operator-(const Date& date1, const Date& date2);
	friend Date operator-(const Date& date, int daysToCut);
	friend istream& operator>>(istream& input, Date& date);
	friend ostream& operator<<(ostream& output, const Date& date);

	Date& operator=(const Date& other) {
		if (*this == other) {
			return *this;
		}
		year = other.year;
		month = other.month;
		day = other.day;
		return *this;
	}
	Date& operator++() {
		*this = *this + 1;
		return *this;
	}
	Date& operator++(int) {
		Date temp = *this;
		*this = *this + 1;
		return temp;
	}
	Date& operator--() {
		*this = *this - 1;
		return *this;
	}
	Date& operator--(int) {
		Date temp = *this;
		*this = *this -1;
		return temp;
	}
	Date& operator+=(int days) {
		*this = *this + days;
		return *this;
	}
	Date& operator-=(int days) {
		*this = *this - days;
		return *this;
	}
	
	bool operator==(const Date& other) const {
		return (day == other.getDay() &&
			month == other.getMonth() &&
			year == other.getYear());
	}
	bool operator!=(const Date& other) const {
		return !(*this == other);
	}
	bool operator>(const Date& other) const {
		if (year != other.getYear()) {
			return year > other.getYear();
		}
		if (month != other.getMonth()) {
			return month > other.getMonth();
		}
		return day > other.getDay(); 
	}
	bool operator<(const Date& other) const {
		if (*this == other) return false;
		return !(*this > other);
	}
	//реалізував через чат томущо не придумав я взагалі можна було використати () в данному випадку
	string operator()(const string& format = "YYYY-MM-DD") const {
		ostringstream formattedDate;
		for (char c : format) {
			switch (c) {
			case 'Y': formattedDate << setw(4) << setfill('0') << year; break;
			case 'M': formattedDate << setw(2) << setfill('0') << month; break;
			case 'D': formattedDate << setw(2) << setfill('0') << day; break;
			default: formattedDate << c;
			}
		}
		return formattedDate.str();
	}

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

Date operator+(int daysToAdd, const Date& date) {
	return date + daysToAdd;
}

Date operator-(const Date& date, int daysToCut) {
	int day = date.getDay();
	int month = date.getMonth();
	int year = date.getYear();

	day -= daysToCut;
	while (day <= 0) {
		month--;
		if (month < 1) {
			month = 12;
			year--;
		}
		day += Date::getMaxDayInMonth(month, year);
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

istream& operator>>(istream& input, Date& date) {
	int day, month, year;
	input >> day >> month >> year;
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
	return input;
}

ostream& operator<<(ostream& output, const Date& date) {
	output << setfill('0') << setw(2) << date.getDay() << '.'
		<< setfill('0') << setw(2) << date.getMonth() << '.'
		<< date.getYear();
	return output;
}


int main()
{
	Date d1(10, 12, 2023);
	Date d2(18, 01, 2022);
	Date d4{1, 1, 1};
	Date d5{1, 1, 1};
	Date d3 = d1 + 181;
	cout << "d3: " << d3 << endl;
	int days = d1 - d2;
	cout << days;
	cout << endl;
	d4 = d2; 
	cout <<"d4: " << d4 << endl;
	cin >> d5;
	cout << "d5: " << d5 << endl;
	d5 += 5;
	cout << "d5: " << d5 << endl;
	d5 -= 8;
	cout << "d5: " << d5 << endl;
	d5++;
	cout << "d5: " << d5 << endl;
	d5--;
	cout << "d5: " << d5 << endl;

	cout << boolalpha << (d2 > d1) << endl;
	cout << boolalpha << (d2 < d1) << endl;
	cout << boolalpha << (d4 == d2) << endl;
	cout << boolalpha << (d4 != d2) << endl;
	cout << "Custom format: " << d5("D/M/Y") << endl;

}