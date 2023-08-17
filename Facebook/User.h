#ifndef USER_H
#define USER_H

#include <iostream>
#include "Date.h"
#include "Entity.h"

const int  LastUpdateStatusArrSize = 10;


class FanPage;
class Status;


class User : public Entity
{
	Date dateOfBirth;

public:

	///// C'tors /////

	User();

	User(const std::string& _name, const Date& _date, const int _indexInAllEntitiesArr= InitialIndex);
	
	User (std::ifstream& inFile);

	User (const User& u) = delete;

	virtual ~User();

	///// Operators /////

	User& operator=(const User& u) = delete;

	///// Set Functions /////
    
	void SetDateOfBirth(const Date& _date);

	///// Get Functions /////

	Date GetDateOfBirth() const;
	
	///////// ------------------------------------------- /////////

	virtual void PrintLastUpdateStatusOfFriends() const override; 
		// virtual function that prints all last update statuses of user's friends

	virtual void PrintEntities() const override;
		// virtual function that prints all user's friends

};

#endif // !USER_H