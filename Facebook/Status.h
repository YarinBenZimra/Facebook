#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include "Date.h"
#include "Hour.h"
#include "Utilities.h" 
#include <vector>
#include <string>
#include <fstream>


class Status
{
private:

	std::vector<const std::string*> text;
	Date                            date;
	Hour                            hour;
	bool                            color;

public:

	///// C'tors /////

	Status();

	Status(std::ifstream& inFile);

	Status(const Date& _date, const Hour& _h, std::vector<const std::string*> _text, bool _color = false);

	Status(const Status& s) = delete;

	~Status();

	///// Operators /////

	Status& operator=(const Status& s) = delete;

	bool operator==(const Status& s) const; 
		// returns true if the two statuses are equal

	bool operator!=(const Status& s) const; 
		// returns true if the two statuses are different

	///// Set Functions /////	
	
	inline void SetDate(const Date &_date);

	inline void SetHour(const Hour &_hour);

	inline void SetText(std::vector<const std::string*> &_text);

	inline void SetColor(bool _color);

	///// Get Functions /////
	
	Date GetDate() const;

	Hour GetHour() const;

	const std::vector<const std::string*>& GetText() const;

	bool GetColor() const;

	///////// ------------------------------------------- /////////

	void printDate() const; 
		// prints the date the status was uploaded
	
	virtual void printStatus() const;
		// virtual function that prints the text of the status
	

};
#endif // !STATUS_H