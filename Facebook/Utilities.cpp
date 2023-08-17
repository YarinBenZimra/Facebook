#include "Utilities.h"
#include "Facebook.h"
#include "Exceptions.h"
#include "Date.h"
#include "Status.h"
#include "ImageStatus.h"
#include "VideoStatus.h"
#include "User.h"
#include "Fan_Page.h"

using namespace std;

Entity* Utilities::ReadUser(const Facebook& f)
{
	
	int day, month, year, location;
	string name;

	cout << endl << "***USER SIGN-UP PAGE***" << endl << endl;

	cout << endl << "Please enter your name: " << endl;
	getline(cin, name);

	location = f.IsEntityExistInAllUsersArray(name);

	if (location != NotFound)
		throw Exceptions("The name " + name + " already exists in the system ");


	cout << endl << "Please enter your date of birth, day, month and year accordingly: " << endl;

	cin >> day >> month >> year;

	cin.ignore();

	Entity* pNewEntity = new User(name, Date(day, month, year));


	return pNewEntity;
}

Entity* Utilities::ReadFanPage(const Facebook& f)  
{
	int location;
	string name;

	cout << endl << "***FAN PAGE SIGN-UP PAGE***" << endl << endl << endl;


	cout << endl << "Please enter your fan-page name: " << endl << endl;
	getline(cin, name);

	location = f.IsEntityExistInAllUsersArray(name);

	if (location != NotFound)
		throw Exceptions("The name " + name + " already exists in the system");

	Entity* pNewEntity = new FanPage(name);

	return pNewEntity;

}

int Utilities::ChooseUserByName(const Facebook& f) 
{
	string name;
	int location;

	cout << endl << "Please choose a user that exist in the system" << endl << endl;
	getline(cin, name);
		
	location = f.IsEntityExistInAllUsersArray(name);
	
	if (location == NotFound || f.TypeOfEntity(location) != 'U') 
		throw Exceptions("The user doesn't exist in the system");

	return location;
}

int Utilities::ChooseFanPageByName(const Facebook& f) 
{
	string name;
	int location;

	cout << endl << "Please choose a fan page that exist in the system" << endl << endl;
	getline(cin, name);
	
	location = f.IsEntityExistInAllUsersArray(name);
	
	if (location == NotFound || f.TypeOfEntity(location) != 'F')
		throw Exceptions("The fan page doesn't exist in the system");

	return location;
}

int	Utilities::OneForUserZeroForFanPage() 
{
	int choice;
	cout << endl << endl << "Press 0 for fan page, 1 for user " << endl << endl;

	cin >> choice;
	cin.ignore();

	if(choice != FanPageChoose && choice != UserChoose )
		throw Exceptions("Invalid Choice");

	return choice;
}

 Status* Utilities::ReadStatus()
{
	vector<const string*> text;
	string line;
	Date date;
	Hour hour;
	int choice;
	bool c;
	Status* st= nullptr;
	
	cout << endl <<  "Please enter one of the options:" << endl << "1. Text Status" << endl << "2. Image Status" << endl << "3. Video Status" << endl;
	cin >> choice;
	cin.ignore();

	

	if (choice != VideoStatusChoose && choice != TextStatusChoose && choice != ImageStatusChoose)
		throw Exceptions("Invalid Choice");

	cout << endl << "To write text in color please enter 1, otherwise (black & white) 0" << endl;
	cin >> c;
	cin.ignore();

	if (c != Color && c != NonColor)
		throw Exceptions("Invalid Choice");

	else
	{

		switch (choice)
		{
		case 1:
			
			cout << endl << "Please enter your status: " << endl;
			ReadStatusText(date, hour, text);

			st = new Status(date, hour, text, c);
			break;

		case 2:
			cout << endl << "Please describe your image: " << endl;
			ReadStatusText(date, hour, text);

			st = new ImageStatus(date, hour, text, c);
			break;

		case 3:
			cout << endl << "Please describe your video: " << endl;
			ReadStatusText(date, hour, text);

			st = new VideoStatus(date, hour, text, c);
			break;
		}
	}
		
		//do
		//{
		//	getline(cin, line);
		//	string* curr = new string(line);

		//	if (line.size() != 0)
		//		text.push_back(curr);
		//	else
		//		delete curr;

		//} while (line.size() != 0);

		//time_t now = time(0);
		//char* dt = ctime(&now);

		//int year, day, hour, min, sec, month;
		//char Smonth[10];
		//char stam[10];

		//sscanf(dt, "%s %s %d %d:%d:%d %d", stam, Smonth, &day, &hour, &min, &sec, &year);

		//month = findMonth(Smonth);

		//Status* st = new Status(Date(day, month, year), Hour(hour, min, sec), text);

		return st;
	
}


void Utilities::ReadStatusText( Date& date, Hour& hour, vector<const string*>& text )
{
	int year, day, h, min, sec, month;
	char Smonth[10];
	char stam[10];
	string line;

	do
	{
		getline(cin, line);
		string* curr = new string(line);

		if (line.size() != 0)
			text.push_back(curr);
		else
			delete curr;

	} while (line.size() != 0);

	time_t now = time(0);
	char* dt = ctime(&now);

	sscanf(dt, "%s %s %d %d:%d:%d %d", stam, Smonth, &day, &h, &min, &sec, &year);

	month = findMonth(Smonth);

	date = Date(day, month, year);
	hour = Hour(h, min, sec);
}

 void Utilities::MembershipLinkOutputMessage(const Facebook& f, int& location1, int& location2)
 {
	 cout << "Please enter two users you want them to be friends: " << endl << endl;

	 location1 = ChooseUserByName(f);
	 location2 = ChooseUserByName(f);


	 if (location1 == location2)
	 {
		 throw Exceptions("You can not add user to himself");
	 }


	 else if (f.IsEntitiesConnected(location1, location2) == true)
	 {
		 string exceptionStr;
		 exceptionStr += "The users ";
		 exceptionStr += f.GetEntityName(location1);
		 exceptionStr += " and ";
		 exceptionStr += f.GetEntityName(location2);
		 exceptionStr += " are already friends";

		 throw Exceptions(exceptionStr);
	 }
 }

void Utilities::MembershipCancellationOutputMessage(const Facebook& f, int& location1, int& location2)
{
	
	cout << "Please enter two users you want them to cancel their membership: " << endl << endl;

	location1 = ChooseUserByName(f);
	location2 = ChooseUserByName(f);

	if (f.IsEntitiesConnected(location1, location2) == false)
	{
		string exceptionStr;

		exceptionStr += "The users ";
		exceptionStr += f.GetEntityName(location1);
		exceptionStr += " and ";
		exceptionStr += f.GetEntityName(location2);
		exceptionStr += " weren't friends";

		throw Exceptions(exceptionStr);
	}
}

void Utilities::fanPageAndUserLinkOutputMessage(const Facebook& f, int& location1, int& location2)
{
	cout << "Please enter user and fan page for membership: " << endl << endl;

	location1 = ChooseUserByName(f);
	location2 = ChooseFanPageByName(f);

	if (f.IsEntitiesConnected(location1, location2) == true)
	{
		string exceptionStr;

		exceptionStr += "The user ";
		exceptionStr += f.GetEntityName(location1);
		exceptionStr += " already like ";
		exceptionStr += f.GetEntityName(location2);
		exceptionStr += " fan page ";


		throw Exceptions(exceptionStr);
	}

}

void Utilities::fanPageAndUserCancellationOutputMessage(const Facebook& f, int& location1, int& location2)
{
    cout << "Please enter user and fan page to cancel membership: " << endl << endl;
	
	location1 = ChooseUserByName(f);
	location2 = ChooseFanPageByName(f);


	if (f.IsEntitiesConnected(location1, location2) == false)
	{
		string exceptionStr;

		exceptionStr += "The user ";
		exceptionStr += f.GetEntityName(location1);
		exceptionStr += " is not a fan of ";
		exceptionStr += f.GetEntityName(location2);
		exceptionStr += " fan page ";

		throw Exceptions(exceptionStr);
	}

}

int Utilities::findMonth(char* Smonth)
{
	for (int i = 0; i <= 11; i++)
	{
		if (strcmp(Smonth, (Date::eMonthStr)[i]) == 0)
			return i+1;
	}

	return 0;
}

