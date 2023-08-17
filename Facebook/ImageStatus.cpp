#include "ImageStatus.h"


ImageStatus::ImageStatus(const Date& _date, const Hour& _h, std::vector<const std::string*> _text, bool _color) : Status(_date, _h, _text, _color) { ; }

ImageStatus::ImageStatus(std::ifstream& inFile) : Status(inFile) { ; }

void ImageStatus::printStatus() const 
{
	std::cout << "This is a picture about ";
	Status::printStatus();
	std::cout << "This picture was shot in a simple program " << std::endl;
}
