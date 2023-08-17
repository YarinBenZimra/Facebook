#include "VideoStatus.h"

VideoStatus::VideoStatus(const Date& _date, const Hour& _h, std::vector<const std::string*> _text, bool _color) : Status(_date, _h, _text, _color) { ; }

VideoStatus::VideoStatus(std::ifstream& inFile) : Status(inFile) { ; }

void VideoStatus::printStatus() const
{
	std::cout << "This is a video about ";
	Status::printStatus();
	std::cout << "This video was shot in a MP4 program " << std::endl;

}