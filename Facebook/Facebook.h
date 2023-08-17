#ifndef FACEBOOK_H
#define FACEBOOK_H
 

#include <vector>
#include <string>

#pragma warning(disable: 4996)
 
const int Color = 1, NonColor = 0, UserChoose = 1, FanPageChoose = 0,
			TextStatusChoose = 1, ImageStatusChoose = 2 , VideoStatusChoose = 3, NotFound = -1;

class Entity;
class Status;

class Facebook
{
private:

	 std::vector<Entity*> allEntities;

public:

	 
	///// C'tors /////

	 Facebook();

	 ~Facebook();

	 Facebook(const Facebook& f) = delete;

	 ///// Operators /////

	 Facebook& operator=(const Facebook& f) = delete;

	 ///////// ------------------------------------------- /////////
	 
	 void WriteToFile(std::string AllEntitiesData, std::string ConnectionsData) const;
	   // The function writes all Facebook data to a text file

	 void WriteBillboardOfEntityToFile(std::ofstream& file1, const std::vector<Status*>& billboard) const;
	   // The function writes a user's statuses to a text file

	 void WriteToConnectionsDataFile(std::ofstream& file2, const std::vector<const Entity*>& Friends) const;
	    // The function writes all the friends of a user to a text file 

	 void LoadFromFile(std::string AllEntitiesData, std::string ConnectionsData);
		// The function loads all the data of facebook from the two text files

	 void LoadFromConnectionsDataFile(std::ifstream& inFile2, int allEntitiesSize);
		// The function loads all the friends of the users in facebook

	 const std::string& GetEntityName(const int location) const;
		// The function gets a location in the allEntities arr and returns the name of the entity

	 int IsEntityExistInAllUsersArray(std::string _name) const;
		// The function gets a name and checks if this name was chosen for a user 

	 bool IsEntitiesConnected(int location1, int location2) const;
		// The function returns true if two entities are connected 

	 char TypeOfEntity(int location) const;
		// returns 'U' if the entity is a user or 'F' if the entity is a fan page

	 void AddUser();
		// The function adds a user to the allEntities arr

	 void AddFanPage();
		// The function adds a fan page to the allEntities arr

	 void AddStatus();
		// The function adds a status to an entity

	 void PrintStatuses() const;
		// The function prints all entity's statuses

	 void PrintAllUserFriendsLastStatus() const;
		// The function prints all last update statuses of a user's friends

	 void PrintAllEntities() const;
		// The function prints the allEntities arr

	 void membershipLink(); 
		// The function creats friendship between two users

	 void membershipCancellation(); 
		// The function cancells friendship between two users

	 void fanPageAndUserLink(); 
		// The function creats the connection between fan page and a user

	 void fanPageAndUserCancellation(); 
		// The function cancells the connection between fan page and a user

	 void PrintAllFriends() const;
		// The function prints all entity's friends
	 
	 void PrintUserFriendsArr() const;
		// The function prints all user's friends

	 void PrintFanPageFriendsArr() const;
		// The function prints all fan page's fans

	 void ExitSystem();
		// Exit system

	 void Menu();
		// The menu of facebook
};



#endif // !FACEBOOK_H
