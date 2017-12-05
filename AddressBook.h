#pragma once
#include "LinkedList.h"
#include "Address.h"
class AddressBook : public LinkedList<Address>
{
public:
	AddressBook();
	~AddressBook();
	void print();// Print the Address Book
	void add(Address curAddress);// Add an address
	void remove(std::string name);// Remove an address associated with the name passed in
	Address get(std::string name);// Get an address by passing in the name of that address
	void generateBirthdayCards(std::string date);// Generate bday cards
	void generateAnniversaryCards(std::string date);// Generate anniversary cards
	void load();// Load the address book
	void save();// Save the address book

private:
	void printBirthdayCard(Address currAdress);
	void printAnniversaryCard(Address currAdress);
};