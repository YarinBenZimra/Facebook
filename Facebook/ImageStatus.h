#ifndef IMAGESTATUS_H
#define IMAGESTATUS_H

#include "Status.h"

class ImageStatus : public Status
{
public:
	
	///// C'tors /////

	ImageStatus(const Date& _date, const Hour& _h, std::vector<const std::string*> _text, bool _color);

	ImageStatus(std::ifstream& inFile);

	///////// ------------------------------------------- /////////

	virtual void printStatus() const override;
		// virtual function that prints the status


private:

};

#endif // !IMAGESTATUS_H
