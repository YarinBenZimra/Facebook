#include "Status.h"
#include "Exceptions.h"
#include "Facebook.h"

using namespace std;

///// C'tors /////

Status::Status() {;}

Status::Status(ifstream& inFile)
{
	string line;
	int day, month, year, hour, min, sec, color, TextSize;
	vector<const string*> temp;

	inFile >> day >> month >> year;
	inFile >> hour >> min >> sec;
	inFile >> color;
	inFile >> TextSize;
	inFile.ignore();
	
	SetDate(Date(day, month, year));
	SetHour(Hour(hour, min, sec));
	SetColor(color);

	for (int k = 0; k < TextSize; ++k)
	{
		getline(inFile, line);
		temp.push_back(new string(line));
	}

	SetText(temp);
}

Status::Status(const Date& _date, const Hour& _h, vector<const string*> _text, bool _color)
{
	SetDate(_date);
	SetHour(_h);
	SetText(_text);
	SetColor(_color);
}


Status::~Status()
{ 	
	for (auto itr = text.begin(); itr != text.end(); ++itr)
	{
		delete *itr;
	}
	text.resize(0);
}



///// Operators /////

bool Status::operator==(const Status& s) const
{
	if (text.size() != s.text.size())
	{
		return false;
	}
	
	auto itrOperation = text.begin();
	auto itrS = s.text.begin();
	
	for (; itrOperation != text.end(); itrOperation++)
	{
		if ((*(*itrOperation)) != (*(*itrS)))
			return false;
	}
	return true;
}

bool Status::operator!=(const Status& s) const
{
	return !((*this) == s);	
}

///// Set Functions /////	

inline void Status::SetDate(const Date& _date) { date = _date; }

inline void Status::SetHour(const Hour& _hour) { hour = _hour; }

inline void Status::SetText(vector<const string*> &_text)
{
	if (_text.size() == 0)
		throw Exceptions("Invalid Status");

	text = _text;
}

inline void Status::SetColor(bool _color) 
{ 
	if ( _color != Color && _color != NonColor )
		throw Exceptions("Invalid Status");

	color = _color; 
}

///// Get Functions /////	

 Date Status::GetDate() const { return date; }

 Hour Status::GetHour() const { return hour; }

 const vector<const string*>& Status::GetText() const { return text; }

 bool Status::GetColor() const { return color; }

///////// ------------------------------------------- /////////

void Status :: printDate() const
{
	int day = date.GetDay();
	enum Date::Month month = date.GetMonth();
	int h = hour.getHour();
	int m = hour.getMin();
	int s = hour.getSec();


	if (day < 10)
		cout << "The status was written on the 0" << day;
	else
		cout << "The status was written on the " << day;

	if ((int)month < 10)
		cout << "/0" << (int)month;
	else
		cout << "/" << (int)month;

	cout << "/" << date.GetYear();

	if (h < 10)
		cout << " at hour 0" << h;

	else
		cout << " at hour " << h;


	if (m < 10)
		cout << ":0" << m << ":";

	else
		cout << ":" << m << ":";

	if (s < 10)
		cout << "0" << s;

	else
		cout << s << endl;


	
	cout << endl;

}

void Status::printStatus() const 
{
	auto itr  = text.begin();

	for (; itr != text.end(); itr++)
	{
		cout << (*(*itr)) << endl;
	}
	cout << endl;
	printDate();
	
	if (color)
		cout << "The text was printed in black & white in a simple program" << endl << endl << endl;

	else
		cout << "The text was printed in color in a simple program" << endl << endl << endl;

}

 

