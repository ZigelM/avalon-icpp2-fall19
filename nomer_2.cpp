#pragma once
#include <iostream>
using namespace std;
namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	enum DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	int Month_To_Int(Month mon) {
		switch (mon)
		{
		case Month::January:return 1;break;
		case Month::February:return 2;break;
		case Month::March:return 3;break;
		case Month::April:return 4;break;
		case Month::May:return 5;break;
		case Month::June:return 6;break;
		case Month::July:return 7;break;
		case Month::August:return 8;break;
		case Month::September:return 9;break;
		case Month::October:return 10;break;
		case Month::Novemver:return 11;break;
		case Month::December:return 12;break;
		}
	}

	TimeDelta countJND(Date date)
	{
		int a = (14 - Month_To_Int(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = Month_To_Int(date.month) + 12 * a - 3;
		int answ = (date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045);
		return TimeDelta{ answ };
	}

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta answ = countJND(to) - countJND(from);
		return answ;
	}


	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		cout << data.day << "." << Month_To_Int(data.month) << "." << data.year << endl;
	}
	//void print(Month month, DateFormat format = DateFormat::MonthAsInt);

	void print(TimeDelta delta)
	{
		cout << delta.delta;
	}

	Season getSeason(Date date)
	{
		switch (date.month)
		{
		case ext::Month::January:
		case ext::Month::February:
		case ext::Month::December:
			return Season::Winter;
			break;
		case ext::Month::March:
		case ext::Month::April:
		case ext::Month::May:
			return Season::Spring;
			break;
		case ext::Month::June:
		case ext::Month::July:
		case ext::Month::August:
			return Season::Summer;
			break;
		case ext::Month::October:
		case ext::Month::Novemver:
		case ext::Month::September:
			return Season::Autumn;
			break;
		default:
			break;
		}
	}
	Season getSeason(Month month)
	{
		switch (static_cast<int>(month)) {
		case 1:
		case 2:
		case 12:
			return Season::Winter;
			break;
		case 3:
		case 4:
		case 5:
			return Season::Spring;
			break;
		case 6:
		case 7:
		case 8:
			return Season::Summer;
			break;
		case 9:
		case 10:
		case 11:
			return Season::Autumn;
			break;
		}
	}

	bool operator == (const Date lhs, const Date rhs) {
		if ((lhs.year == rhs.year) && ((static_cast<int>(lhs.month)) == (static_cast<int>(rhs.month))) && (lhs.day == rhs.day)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	}

	bool operator < (const Date lhs, const Date rhs) {
		if ((lhs.year < rhs.year) && ((static_cast<int>(lhs.month)) < (static_cast<int>(rhs.month))) && (lhs.day < rhs.day)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator <= (const Date lhs, const Date rhs) {
		if ((lhs.year <= rhs.year) && ((static_cast<int>(lhs.month)) <= (static_cast<int>(rhs.month))) && (lhs.day <= rhs.day)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator > (const Date lhs, const Date rhs) {
		return !(lhs < rhs);
	}

	bool operator >= (const Date lhs, const Date rhs) {
		if ((lhs.year >= rhs.year) && ((static_cast<int>(lhs.month)) >= (static_cast<int>(rhs.month))) && (lhs.day >= rhs.day)) {
			return true;
		}
		else {
			return false;
		}
	}


	Date ToDate(TimeDelta delta) {
		Date oout;
		int a = delta.delta + 32044;
		int b = ((4 * a) + 3) / 146097;
		int c = a - ((146097 * b) / 4);
		int d = ((4 * c) + 3) / 1461;
		int e = c - ((1461 * d) / 4);
		oout.day = e - ((153 * (((5 * e) + 2) / 153) + 2) / 5) + 1;
		oout.month = static_cast<Month>((((5 * e) + 2) / 153) + 3 - 12 * ((((5 * e) + 2) / 153) / 10));
		oout.year = (100 * b) + d - 4800 + ((((5 * e) + 2) / 153) / 10);
		return oout;
	}


	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta delta1;
		delta1.delta = lhs.delta + rhs.delta;
		return delta1;
	}

	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta1 + delta);
	}

	Date operator + (const TimeDelta delta, const Date date) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta1 + delta);
	}


	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta delta1;
		delta1.delta = lhs.delta - rhs.delta;
		return delta1;
	}

	Date operator - (const Date date, const TimeDelta delta) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta1 - delta);
	}

	Date operator - (const TimeDelta delta, const Date date) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta - delta1);
	}


	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta deltaa;
		deltaa.delta = (delta.delta * multiplier);
		return deltaa;
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		TimeDelta deltaa;
		deltaa.delta = (delta.delta * multiplier);
		return deltaa;
	}

	TimeDelta operator / (const TimeDelta delta, int multiplier)
	{
		TimeDelta deltaa;
		deltaa.delta = (delta.delta / multiplier);
		return deltaa;
	}
	TimeDelta operator / (int multiplier, const TimeDelta delta)
	{
		TimeDelta deltaa;
		deltaa.delta = (delta.delta / multiplier);
		return deltaa;
	}