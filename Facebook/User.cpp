#include "User.h"
#include "Status.h"
#include "Fan_Page.h"
#include "Utilities.h"
#include <fstream>

using namespace std;

///// C'tors /////

User::User() { ; }

User::User(const string& _name, const Date& _date, const int _IndexInAllEntitiesArr) : Entity(_name, _IndexInAllEntitiesArr)
{
	SetDateOfBirth(_date);
}

User::User(ifstream& inFile)
{
	string name;
	int day, month, year, indexInAllEntitiesArr;

	getline(inFile, name);
	inFile >> indexInAllEntitiesArr;
	inFile >> day >> month >> year;
	SetName(name);
	SetIndexInAllEntities(indexInAllEntitiesArr);
	SetDateOfBirth(Date(day, month, year));
}

User::~User() { ; }

///// Set Functions /////

void User::SetDateOfBirth(const Date& _date) 
{
	dateOfBirth = _date;
}

///// Get Functions /////

 Date User::GetDateOfBirth() const { return dateOfBirth; }

///////// ------------------------------------------- /////////
 
void User::PrintLastUpdateStatusOfFriends() const
{
	
	cout << endl;
	auto arr = GetEntitiesArr();

	auto Eitr = arr.begin();

	for (; Eitr != arr.end(); ++Eitr)
	{
		if  (typeid(*(*Eitr)) == typeid(User))
		{

			cout << "--------------------------------------------------------------------" << endl << (*Eitr)->GetName() << "'s statuses:" << endl;

			const vector<Status*> billboard = (*Eitr)->GetBillboardArr();

			if (billboard.size() < LastUpdateStatusArrSize)
			{
				(*Eitr)->PrintBillboard();
			}

			else
			{
				auto Bitr = billboard.end() - 1;

				for (int j = 0; j < LastUpdateStatusArrSize; j++)
				{
					(*Bitr)->printStatus();
					Bitr--;
				}
			}
		}
	}
	
}

void User::PrintEntities() const 
{
	auto arr = GetEntitiesArr();

	auto itr = arr.begin();

	cout << endl << GetName() << "'s Friends:" << endl;

	for (; itr != arr.end(); ++itr)
	{
		if (typeid(*(*itr)) == typeid(User))
			cout << (*itr)->GetName() << endl;
	}

	cout << endl << endl;
}

