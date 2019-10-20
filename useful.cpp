#include <iostream>
#include "Date.hpp"

using namespace std;
using namespace ext;

struct Point
{
	float x;
	float y;
};

bool IsSame(Point a, Point b)
{

}

bool operator == (Point lhs, Point rhs)
{

}

int main()
{
	//void print(Date data, DateFormat format = DateFormat::MonthAsInt);

	//Date date = { 2001, static_cast<Month>(10), 12 };

	Date date = { 2001, Month::March, 12 };
	print(date, DateFormat::MonthAsInt);	// 2001 3 12
	cout << endl;
	print(date);
	cout << endl;
	print(date, DateFormat::MonthAsString);	// 2001 march 12	
	cout << endl;

	//void print(Month month, DateFormat format = DateFormat::MonthAsInt);
	Month month = Month::February;
	print(month, DateFormat::MonthAsInt);	// 2
	cout << endl;
	print(month, DateFormat::MonthAsString);	// february
	cout << endl;

	// bool operator == (const Date lhs, const Date rhs);

	Date first = { 2001, Month::February, 12 };
	Date second = { 2001, Month::February, 12 };
	Date third = { 2001, Month::February, 13 };

	cout << (first == second) << endl; // true
	cout << (first == third) << endl; // false
	
	cout << (first != second) << endl; // false
	cout << (first != third) << endl; // true


	Point a{ 2,2 };
	Point b{ 4,4 };

	if (a == b)
	{
		cout << "points are the same!" << endl;
	}
}
