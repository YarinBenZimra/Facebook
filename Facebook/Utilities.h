#ifndef UTILTIES_H
#define UTILTIES_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>

class Facebook;
class Status;
class Entity;
class Date;
class Hour;

class Utilities
{

public:

	static Entity* ReadUser(const Facebook& f); 
		// reads input from keyboard and creats a new user of Facebook
	
	static Entity* ReadFanPage(const Facebook& f);
		// reads input from keyboard and creats a new fan page of Facebook

	static int ChooseUserByName(const Facebook& f); 
		// reads a name from keyboard and checks if this user exist in Facebook
	
	static int ChooseFanPageByName(const Facebook& f); 
		// reads a name from keyboard and checks if this fan page exist in Facebook

	static int OneForUserZeroForFanPage(); 
		// reads one for user, or zero for fan page from keyboard and return the choice

	static Status* ReadStatus(); 
		// reads input from keyboard and creats a new status

	static void ReadStatusText(Date& date, Hour& hour, std::vector<const std::string*>& text);
		// reads the text of the status that a user wants to upload

	static void MembershipLinkOutputMessage(const Facebook& f, int& location1, int& location2);
		// manages contact with the user about two users he wants them to be friends

	static void MembershipCancellationOutputMessage(const Facebook& f, int& location1, int& location2);
		// manages contact with the user about two friends he wants to cancell their friendship

	static void fanPageAndUserLinkOutputMessage(const Facebook& f, int& location1, int& location2);
		// manages contact with the user about a user he wants him to be a fan of some fan page

	static void fanPageAndUserCancellationOutputMessage(const Facebook& f, int& location1, int& location2);
		// manages contact with the user about a user he wants him to stop being a fan of some fan page
	
	static int findMonth(char* Smonth);
		// returns the index of the corresponding month in the month string array


	

};



#endif // UTILTIES_H
