#include "Address.h"
#include "LinkedList.h"

// Can be created with name, address, aniv date, and bday
Address::Address(std::string name, std::string streetAddress, std::string anniversaryDate, std::string birthdayDate)
{
	this->name = name;
	this->streetAddress = streetAddress;
	this->anniversaryDate = anniversaryDate;
	this->birthdayDate = birthdayDate;
}

Address::~Address()
{
	//dtor
}

// Can be printed out by an overloaded operator.
std::ostream& operator<<(std::ostream& os, const Address& curAddress)
{
	os.clear();
	os << "Name:             " << curAddress.name << std::endl
		<< "Address:          " << curAddress.streetAddress << std::endl
		<< "Anniversary Date: " << curAddress.anniversaryDate << std::endl
		<< "Birthday Date:    " << curAddress.birthdayDate << std::endl;
	return os;
};