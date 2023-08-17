#include "Facebook.h"
#include <iostream>
#include <string.h>
#include "User.h"
#include "Status.h"
#include "ImageStatus.h"
#include "VideoStatus.h"
#include "Fan_Page.h"
#include "Utilities.h"
#include "Entity.h"
#include "Exceptions.h"
#include <fstream>

using namespace std;

///// C'tors /////

Facebook::Facebook() { ; } 

Facebook::~Facebook()   
{
	auto itr = allEntities.begin();

	for (; itr != allEntities.end(); ++itr)
	{
		delete (*itr);
	}

	allEntities.resize(0);
}  

///////// ------------------------------------------- /////////

void Facebook::WriteToFile(string AllEntitiesData, string ConnectionsData) const
{
	
	ofstream file1(AllEntitiesData);
	ofstream file2(ConnectionsData);

	if (!file1.is_open() || !file2.is_open())
		throw Exceptions("Can Not Open File");

	file1 << allEntities.size() << endl;

	for (Entity* entity : allEntities)
	{
		file2 << entity->GetIndexInAllEntities() << endl;

		if (typeid(*entity) == typeid(User))
		{
			file1 << "U" << endl;                              
			file1 << entity->GetName() << endl;
			file1 << entity->GetIndexInAllEntities() << endl;

			Date Udate = (dynamic_cast<User*>(entity))->GetDateOfBirth();
			file1 << Udate.GetDay() << " " << (int)(Udate.GetMonth()) << " " << Udate.GetYear() << endl;
		}

		else
		{
			file1 << "F" << endl;
			file1 << entity->GetName() << endl;
			file1 << entity->GetIndexInAllEntities() << endl;
		}

		WriteBillboardOfEntityToFile(file1, entity->GetBillboardArr());
		
		WriteToConnectionsDataFile(file2, entity->GetEntitiesArr());
		
	}

	file1.close();
	file2.close();
}

void Facebook::WriteBillboardOfEntityToFile(ofstream& file, const vector<Status*>& billboard) const
{
	file << billboard.size()<< endl;

	for (auto status : billboard)
	{
		if (typeid(*status) == typeid(Status))
			file << "T" << endl;
		else if (typeid(*status) == typeid(ImageStatus))
			file << "I" << endl;
		else
			file << "V" << endl;

		Date Sdate = status->GetDate();
		file << Sdate.GetDay() << " " << (int)(Sdate.GetMonth()) << " " << Sdate.GetYear() << endl;

		Hour hour = status->GetHour();
		file << hour.getHour() << " " << hour.getMin() << " " << hour.getSec() << endl;

		file << status->GetColor() << endl;

		const vector<const string*> text = status->GetText();

		file << text.size() << endl;

		for (auto str : text)
		{
			file << *str << endl;
		}
	}
}

void Facebook::WriteToConnectionsDataFile(ofstream& file2, const vector<const Entity*>& Friends) const
{
	file2 << Friends.size() << endl;

	for (const Entity* f : Friends)
	{
		file2 << f->GetIndexInAllEntities() << " ";
	}

	file2 << endl;
}

void Facebook::LoadFromFile(string AllEntitiesData, string ConnectionsData)
{
	Status* s;
	string type;
	int allEntitiesSize, billboardSize;

	ifstream inFile1(AllEntitiesData);
	ifstream inFile2(ConnectionsData);

	inFile1 >> allEntitiesSize;
	inFile1.ignore();

	allEntities.reserve(allEntitiesSize);

	for(int i = 0; i < allEntitiesSize; ++i)
	{
		getline(inFile1, type);

		if (type[0] == 'U')
			allEntities.push_back(new User(inFile1));
		
		else
			allEntities.push_back(new FanPage(inFile1));

		
		inFile1 >> billboardSize;
		inFile1.ignore();

		for(int b = 0; b < billboardSize; ++b)
		{
			getline(inFile1, type);

			if (type[0] == 'T')
				s = new Status(inFile1);

			else if(type[0] == 'V')
				s = new VideoStatus(inFile1);
			else	
				s = new ImageStatus(inFile1);
			
			allEntities[i]->AddStatusToBillboard(*s);
		}
	}

	LoadFromConnectionsDataFile(inFile2, allEntitiesSize);

	inFile1.close();
	inFile2.close();
}

void Facebook::LoadFromConnectionsDataFile(ifstream& inFile2, int allEntitiesSize) 
{
	int indexInAllEntitiesArr, FriendsSize, connectionIndex;

	for (int i = 0; i < allEntitiesSize; ++i)
	{
		inFile2 >> indexInAllEntitiesArr >> FriendsSize;

		for (int j = 0; j < FriendsSize; ++j)
		{
			inFile2 >> connectionIndex;
			(*allEntities[indexInAllEntitiesArr]) += (*allEntities[connectionIndex]);
		}
	}
}

const string& Facebook::GetEntityName(const int location) const
{
	return allEntities[location]->GetName();
}

int Facebook::IsEntityExistInAllUsersArray(string _name) const
{
	auto itr = allEntities.begin();
	
	
	for (int count = 0; itr != allEntities.end(); ++itr, ++count)
	{
		if (_name == (*itr)->GetName())
		{
			return count;
		}
	}
	
	if (itr == allEntities.end())
		return NotFound;
}

bool Facebook::IsEntitiesConnected(int location1, int location2) const
{
	Entity* e1 = allEntities[location1];
	Entity* e2 = allEntities[location2];

	auto itr = e1->GetEntitiesArr().begin();
	
	for (; itr != (e1->GetEntitiesArr()).end(); ++itr)
	{
		if ((*itr) == e2)
			return true;
	}
	return false;
}

char Facebook::TypeOfEntity(int location) const
{

	if (typeid(*(allEntities[location])) == typeid(User))
		return 'U';
	
	else if (typeid(*(allEntities[location])) == typeid(FanPage))
		return 'F';

	else
	{
		throw Exceptions("An error occured, please enter again");
	}
}

void Facebook::AddUser()
{
	Entity* pEntity;
	
	pEntity = Utilities::ReadUser(*this);
	pEntity->SetIndexInAllEntities(allEntities.size());
	
	allEntities.push_back(pEntity);
	
	cout << endl << "Registration succeeded, welcome to \033[34mFacebook\033[0m :)" << endl << endl;

}

void Facebook::AddFanPage()
{
	Entity* pEntity;
	
	pEntity = Utilities::ReadFanPage(*this);
	pEntity->SetIndexInAllEntities(allEntities.size());

	allEntities.push_back(pEntity);

	cout << endl << "Registration succeeded, welcome to \033[34mFacebook\033[0m :)" << endl << endl;

}

void Facebook::AddStatus()
{
	Status* st;

	int location, choice;

	choice = Utilities::OneForUserZeroForFanPage();

	if (choice == UserChoose)
		location = Utilities::ChooseUserByName(*this);
	else
		location = Utilities::ChooseFanPageByName(*this);

	st = Utilities::ReadStatus();

	allEntities[location]->AddStatusToBillboard(*(st));

	cout << endl << "The status has been uploaded successfully" << endl << endl;

}

void Facebook::PrintStatuses() const
{
	int location, choice;

	choice = Utilities::OneForUserZeroForFanPage();

	if (choice == UserChoose)
		location = Utilities::ChooseUserByName(*this);
	else
		location = Utilities::ChooseFanPageByName(*this);

	allEntities[location]->PrintBillboard();
}

void Facebook::PrintAllUserFriendsLastStatus() const
{
	int location = Utilities::ChooseUserByName(*this);

	allEntities[location]->PrintLastUpdateStatusOfFriends();
}

void Facebook::PrintAllEntities() const
{
	auto itr = allEntities.begin();
	cout << endl;
	cout << " ----Users----" <<endl<<endl;

	for (; itr != allEntities.end(); ++itr)
	{
		if(typeid(*(*itr)) == typeid(User))
			cout << (*itr)->GetName() << endl;
	}

	cout << endl << " ----Fan Pages----" << endl << endl;

	for (itr = allEntities.begin(); itr != allEntities.end(); ++itr)
	{
		if(typeid(*(*itr)) == typeid(FanPage))
			cout << (*itr)->GetName() << endl;
	}

	cout << endl;
}

void Facebook::membershipLink()  
{
	int location1, location2;

	Utilities::MembershipLinkOutputMessage(*this, location1, location2);

	*(allEntities[location1]) += *(allEntities[location2]);
	*(allEntities[location2]) += *(allEntities[location1]);

	cout << endl << "The users " << GetEntityName(location1) << " and "
		<< GetEntityName(location2) << " are now friends" << endl << endl << endl;
}

void Facebook::membershipCancellation()  
{
	int location1, location2;

	Utilities::MembershipCancellationOutputMessage(*this, location1, location2);
	
	const string name1 = allEntities[location1]->GetName();
	const string name2 = allEntities[location2]->GetName();


	allEntities[location1]->DeleteEntity(name1);
	allEntities[location2]->DeleteEntity(name2);

	cout << endl << "The users " << name1 << " and "
		<< name2 << " are no longer friends" << endl << endl << endl;
	
}

void Facebook::fanPageAndUserLink()
{
	int location1, location2;

	Utilities::fanPageAndUserLinkOutputMessage(*this, location1, location2);

	*(allEntities[location1]) += *(allEntities[location2]);
	*(allEntities[location2]) += *(allEntities[location1]);
	
	cout << endl << endl << "The user " << GetEntityName(location1) << " is now fan of " <<
		GetEntityName(location2) << " fan page " << endl << endl << endl;
}

void Facebook::fanPageAndUserCancellation()
{
	int location1, location2;

	Utilities::fanPageAndUserCancellationOutputMessage(*this, location1, location2);

	const string name1 =allEntities[location1]->GetName();
	const string name2 =allEntities[location2]->GetName();


	allEntities[location1]->DeleteEntity(name1);
	allEntities[location2]->DeleteEntity(name2);

	cout << endl << endl << "The user " << name1 << " does not like " <<
		name2 << " fan page any more " << endl << endl << endl;
	
}

void Facebook::PrintAllFriends() const
{
	int choice;
	
	choice = Utilities::OneForUserZeroForFanPage();

	if (choice == UserChoose)
		PrintUserFriendsArr();
	else if (choice == FanPageChoose)
		PrintFanPageFriendsArr();
}

void Facebook::PrintUserFriendsArr() const
{
	cout << "Please enter the user you want to represent all his friends" << endl << endl; 
	int location = Utilities::ChooseUserByName(*this);
	cout << endl;
	allEntities[location]->PrintEntities();
}

void Facebook::PrintFanPageFriendsArr() const
{
	cout << "Please enter the fan page you want to represent all his friends" << endl << endl;
	int location = Utilities::ChooseFanPageByName(*this);
	allEntities[location]->PrintEntities();
}

void Facebook::ExitSystem() 
{
	cout << endl << endl << "Thank you for using Facebook" <<endl<<endl;
}

void Facebook::Menu()
{
	
	bool end = false;
	int answer;
	
	
	cout << "----- WELCOME TO FACEBOOK ----- " << endl << endl << endl << endl;
	do
	{
		try
		{
			cout << ("***MENU***") << endl << endl;
			cout << "1. Add user" << endl
				<< "2. Add fan page" << endl
				<< "3. Add status to user / fan page" << endl
				<< "4. Show all user's statuses / fan page's statuses" << endl
				<< "5. Show all last update statuses of user's friends" << endl
				<< "6. Membership Link between two users" << endl
				<< "7. Membership cancelleation between two users" << endl
				<< "8. Add user to fan page fans" << endl
				<< "9. Remove user from fan page fans" << endl
				<< "10. Show all users and fan pages in the system" << endl
				<< "11. Show all user's friends / fan page's fans" << endl
				<< "12. Exit" << endl;

			cin >> answer;
			cin.ignore();

			switch (answer)
			{

			case 1:

				AddUser();
				break;

			case 2:

				AddFanPage();
				break;

			case 3:

				AddStatus();
				break;

			case 4:

				PrintStatuses();
				break;

			case 5:

				PrintAllUserFriendsLastStatus();
				break;

			case 6:

				membershipLink();
				break;

			case 7:

				membershipCancellation();
				break;

			case 8:

				fanPageAndUserLink();
				break;

			case 9:

				fanPageAndUserCancellation();
				break;

			case 10:

				PrintAllEntities();
				break;

			case 11:

				PrintAllFriends();
				break;

			case 12:
				ExitSystem();
				end = true;
				break;

			default:
                cout << endl << "Invalid choice, Please enter new one" << endl << endl << endl;
				break;

			}

		}
		
		catch (Exceptions& ex)
		{
			cout << endl << ex.what() << endl << endl << endl;
		}
		catch (const bad_alloc& e)
		{
			cout << endl << "Allocation failed: " << e.what()  << endl << endl << endl;
			exit(1);
		}
		catch (...)
		{
			cout << endl << endl << "An error occured, please enter again" << endl << endl;
		}

	} while (end == false);
}