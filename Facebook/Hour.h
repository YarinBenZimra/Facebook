#ifndef HOUR_H
#define HOUR_H

#include <iostream>

class Hour
{

public:

	///// C'tors /////

	Hour();

	Hour(const int _hour, const int _min, const int _sec);

	///// Set Functions /////

	 void SetHour(const int _hour);

	 void SetMin(const int _min);

	 void SetSec(const int _sec);

	 ///// Get Functions /////

	 int getHour() const;

	 int getMin() const;

	 int getSec() const;
	 

private:

	int hour;
	int min;
	int sec;

};

#endif//!HOUR_H

