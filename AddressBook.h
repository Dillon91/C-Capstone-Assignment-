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
