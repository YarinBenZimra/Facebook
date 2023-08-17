#include "Entity.h"
#include "Exceptions.h"
#include "Status.h"

using namespace std;

///// C'tors /////

Entity::Entity() { ; }

Entity::Entity(const string& _name, const int _index) 
{ 
	SetName(_name);
	SetIndexInAllEntities(_index);
}

Entity::~Entity()
{
	DeleteBillboard();
}

///// Operators /////

Entity& Entity::operator+=(const Entity& _entity)
{
	AddEntity(_entity);
	return *this;
}

bool Entity::operator>(const Entity& _entity)
{
	return entities.size() > _entity.GetEntitiesSize();
}

///// Set Functions /////

void Entity::SetName(const string& _name)
{
	if (_name.size() == 0)
		throw Exceptions("Invalid Name");

	name = _name;
}

void Entity::SetIndexInAllEntities(const int _index)
{
	if (_index < 0)
		throw Exceptions("ERROR");

	IndexInAllEntitiesArr = _index; 
}

///// Get Functions /////

inline const string& Entity::GetName() const { return name; }

int Entity::GetEntitiesSize() const { return entities.size(); }

const vector<const Entity*>& Entity::GetEntitiesArr() const { return entities; }

const vector<Status*>& Entity::GetBillboardArr() const { return billboard; }

int Entity::GetIndexInAllEntities() const { return IndexInAllEntitiesArr; }




///////// ------------------------------------------- /////////

bool Entity::AddEntity(const Entity& _entity)
{
	if (IsEntityExistInEntitiestArr(_entity) == entities.end() && name != _entity.GetName())
	{
		entities.push_back(&_entity);
		return true;
	}

	return false;
}

vector<const Entity*>::iterator Entity::IsEntityExistInEntitiestArr(const Entity& _entity)
{
	auto itr = entities.begin();
	
	for (; itr!= entities.end(); ++itr)
	{
		if (*itr == &_entity)
			return itr;
	}

	return entities.end();
}

void Entity::DeleteEntity(const string& name)
{
	auto itr = entities.begin();

	for(; itr != entities.end(); ++itr)
	{
		if( (*itr)->GetName() == name )
		{
			entities.erase(itr);
			break;
		}
	}
}

void Entity::AddStatusToBillboard(Status &_status)
{
	billboard.push_back(&_status);
} 

void Entity::PrintBillboard() const
{
	auto itr = billboard.begin();
	cout << endl << endl;

	for (int i = 0; itr != billboard.end(); ++itr, ++i)
	{
		cout << "-------- Status #" << i+1 << " --------" <<endl<<endl;
		(*itr)->printStatus();
		
		//Video And Photos
		
		if (GetIndexInAllEntities() == 0 && i == 1)
		{
			system("start blueskypicture.jpg");
		}
		if (i == 1 && GetIndexInAllEntities() == 6)
		{
			system("start michaelvideo.mov");
		}
	}

	cout << endl;
} 

void Entity::DeleteBillboard()
{
	auto itr = billboard.begin();

	for (; itr != billboard.end(); ++itr)
	{
		delete* itr;
	}
	billboard.resize(0);
}
