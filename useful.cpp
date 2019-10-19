#include "Date.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ext
{
	string monthToString(Month month)
	{
		switch (month)
		{
		case ext::Month::January:
			return "january";			
		case ext::Month::February:
			return "february";
		case ext::Month::March:
			return "march";
		case ext::Month::April:
			return "april";
		case ext::Month::May:
			break;
		case ext::Month::June:
			break;
		case ext::Month::July:
			break;
		case ext::Month::August:
			break;
		case ext::Month::September:
			break;
		case ext::Month::October:
			break;
		case ext::Month::Novemver:
			break;
		case ext::Month::December:
			break;
		default:
			break;
		}
	}


	void print(Date data, DateFormat format)
	{
		cout << data.year << " ";
		if (format == DateFormat::MonthAsInt)
		{
			cout << static_cast<int>(data.month) << " ";
		}
		else if(format == DateFormat::MonthAsString)
		{
			switch (data.month)
			{
			case Month::January:
				cout << "january";
				break;
			case Month::February:
				cout << "february";
				break;
			case Month::March:
				cout << "march";
				break;
			case Month::April:
				cout << "april";
				break;
			default:
				break;
			}
			cout << " ";
		}
		cout << data.day;
	}
}
