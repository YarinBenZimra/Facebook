#include "Hour.h"
#include "Exceptions.h"


///// C'tors /////

Hour::Hour() { ; }

Hour::Hour(const int _hour, const int _min, const int _sec)
{
	SetHour(_hour);
	SetMin(_min);
	SetSec(_sec);
}

///// Set Functions /////

void Hour::SetHour(const int _hour) 
{ 
	if (_hour <= 0)
		throw Exceptions("Invalid Hour");

	hour = _hour; 
}

 void Hour::SetMin(const int _min) 
 {
	  if (_min < 0)
		throw Exceptions("Invalid Hour");
 
		min = _min; 
 } 

 void Hour::SetSec(const int _sec)
 { 
	 if (_sec < 0)
		throw Exceptions("Invalid Hour");

	sec = _sec;
}

///// Get Functions /////

 int Hour::getHour() const { return hour; }

 int Hour::getMin() const { return min; }

 int Hour::getSec() const { return sec; }