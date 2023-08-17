#include "Fan_Page.h"
#include <iostream>
#include "User.h"
#include "Status.h"
#include "Utilities.h"
#include <fstream>

using namespace std;

///// C'tors /////

FanPage::FanPage() { ; }

FanPage::FanPage(const string _name, const int _IndexInAllEntitiesArr) : Entity(_name, _IndexInAllEntitiesArr) { ; }

FanPage::FanPage(ifstream& inFile)
{
	string name;
	int indexInAllEntitiesArr;

	getline(inFile, name);
	inFile >> indexInAllEntitiesArr;
	SetName(name);
	SetIndexInAllEntities(indexInAllEntitiesArr);
}

FanPage::~FanPage() { ; }

///////// ------------------------------------------- /////////

 void FanPage::PrintEntities() const
{
	auto arr = GetEntitiesArr();
	
	auto itr = arr.begin();

	cout << endl << GetName() << "'s fans:" << endl;

	for (; itr != arr.end(); itr++)
	{
		cout << (*itr)->GetName() << endl;
	}

	cout << endl << endl;
}

 void FanPage::PrintLastUpdateStatusOfFriends() const { ; }
