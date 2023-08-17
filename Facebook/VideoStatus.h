#ifndef VIDEOSTATUS_H
#define VIDEOSTATUS_H

#include "Status.h"


class VideoStatus : public Status
{

public:

	///// C'tors /////

	VideoStatus(const Date& _date, const Hour& _h, std::vector<const std::string*> _text, bool _color);

	VideoStatus(std::ifstream& inFile);

	///////// ------------------------------------------- /////////
	
	virtual void printStatus() const override;	
		// virtual function that prints the status
	
};


 
#endif // !VIDEOSTATUS_H
