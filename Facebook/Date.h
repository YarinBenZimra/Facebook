#ifndef DATE_H
#define DATE_H

#include <string>
const int currYear = 2023;

class Date
{
public:

	enum class Month { JAN = 1, FAB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
	
	static constexpr const char* eMonthStr[]= {"Jan", "Fab", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	
	///// C'tors /////

	Date();

	Date(const int _day, const int _month, const int _year);

	///// Set Functions /////

	 void SetDay(const int _day);

	 void SetMonth(const int _month);

	 void SetYear(const int _year);

	///// Get Functions /////

	 int GetDay() const;

	 Month GetMonth() const;

	 int GetYear() const;



private:

	int   day;
	Month month;
	int   year;

};


#endif // !DATE_H