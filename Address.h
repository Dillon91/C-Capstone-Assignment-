#pragma once
#include <iostream>
#include "LinkedList.h"

class Address
{
public:
	// Create an Address using these 4 params
	Address(std::string name = "Not Entered",
		std::string streetAddress = "Not Entered",
		std::string anniversaryDate = "XX-XX-XXXX",
		std::string birthdayDate = "XX-XX-XXXX");
	~Address();
	// Let other files print out addresses
	friend std::ostream& operator<<(std::ostream& os, const Address& curAddress);
	std::string name;
	std::string streetAddress;
	std::string anniversaryDate;
	std::string birthdayDate;

};