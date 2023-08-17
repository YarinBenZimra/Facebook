#include "Facebook.h"
#include "Exceptions.h"

int main()
{
	
	Facebook web;
	
	try
	{
		web.LoadFromFile("AllEntitiesData.txt", "ConnectionsData.txt");
	}
	catch(Exceptions& ex)
	{
		std::cout<<ex.what();
		exit(1);
	}
	catch (...)
	{
		std::cout <<"ERROR IN LOAD FILE";
		exit(1);
	}

	web.Menu();
	web.WriteToFile("AllEntitiesData.txt", "ConnectionsData.txt");
	return 0;
}