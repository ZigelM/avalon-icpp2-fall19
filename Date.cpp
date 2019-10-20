#include "Date.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ext;

namespace ext
{
	string monthToString(Month month)
	{
		switch (month)
		{
		case Month::January:
			return "january";			
		case Month::February:
			return "february";			
		case Month::March:
			return "march";			
		default:
			throw exception("invalid month");
		}
	}

	void print(Date data, DateFormat format)
	{
		cout << data.year << " ";
		print(data.month, format);
		cout << data.day;
	}

	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsInt)
		{
			cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{
			cout << monthToString(month) << " ";
		}
		else
		{
			throw exception("invalid format of month");
		}
	}

	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}

	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
}
