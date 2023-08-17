#ifndef FANPAGE_H
#define FANPAGE_H

#include <vector>
#include <string>
#include "Entity.h"


class User;
class Status;

class FanPage : public Entity
{
	
public:

	///// C'tors /////

	 FanPage();

	 FanPage(const std::string _name, const int _IndexInAllEntitiesArr=InitialIndex);

	 FanPage(std::ifstream& inFile);

	 FanPage(const FanPage& fp) = delete;
	
	 virtual ~FanPage();

	 
	 ///// Operators /////

	 FanPage& operator=(const FanPage& fp) = delete;


	 ///////// ------------------------------------------- /////////

	 virtual void PrintEntities() const override;  
		// virtual function that prints all user's friends

	 virtual void PrintLastUpdateStatusOfFriends() const override;

};


#endif // !FANPAGE_H