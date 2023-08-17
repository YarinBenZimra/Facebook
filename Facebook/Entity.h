#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>

const int InitialIndex = 0;
class Status;

class Entity
{

private:

	std::string                name;

	std::vector <Status*>      billboard;
	
	std::vector<const Entity*> entities;

	int                        IndexInAllEntitiesArr;


public:

	///// C'tors /////

	Entity();

	Entity( const std::string& _name, const int _index = InitialIndex );

	virtual ~Entity();

	///// Operators /////

	Entity& operator+=(const Entity& _entity); // calls AddEntity 

	bool operator>(const Entity& _entity); 
		// returns true if my size of entities vector is greater than _entity's size of entities vector
	
	///// Set Functions /////

	void SetName(const std::string & _name);

	void SetIndexInAllEntities(const int _index);

	///// Get Functions /////

	inline const std::string& GetName() const;

	int GetEntitiesSize() const;

	const std::vector<const Entity*>& GetEntitiesArr() const;

	const std::vector<Status*>& GetBillboardArr() const;

	int GetIndexInAllEntities() const;



	///////// ------------------------------------------- /////////

	bool AddEntity(const Entity& _entity);
		// adds new entity to the entities vector 

	std::vector<const Entity*>::iterator IsEntityExistInEntitiestArr(const Entity& _entity); 
		// checks if _entity exists in entities vector

    void DeleteEntity(const std::string& name); 
		// deletes _entity from entities vector

	void PrintBillboard() const; 
		// prints statuses of entity

	void AddStatusToBillboard(Status& _status); 
		// adds status to billboard vector

	void DeleteBillboard(); 
		// deletes the pointers of billboard vector

	virtual void PrintLastUpdateStatusOfFriends() const = 0; 
		// prints ten last update statuses of all entity's friends

	virtual void PrintEntities() const = 0; 
		// prints all member names of the entity
};

#endif // !ENTITY_H
