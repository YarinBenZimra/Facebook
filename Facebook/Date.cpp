#include "Date.h"
#include <iostream>
#include "Exceptions.h"

///// C'tors /////

Date::Date() { ; }

Date::Date(const int _day, const int _month, const int _year)
{
	SetDay(_day);
	SetMonth(_month);
	SetYear(_year);
}

///// Set Functions /////

 void Date::SetDay(const int _day) 
{
	if (_day <= 0 || _day > 31)
		throw Exceptions("Invalid Date");

	day = _day; 
}

 void Date::SetMonth(const int _month) 
 { 
	if (_month <= 0 || _month > 12)
		throw Exceptions("Invalid Date");

	 month = (Month)_month; 
 }

 void Date::SetYear(const int _year) 
{
	 if (_year > currYear || _year < 1000)
		throw Exceptions("Invalid Date");

	year = _year;
}

///// Get Functions /////

 int Date::GetDay() const { return day; }

 Date::Month Date::GetMonth() const { return month; }

 int Date::GetYear() const { return year; }
 


