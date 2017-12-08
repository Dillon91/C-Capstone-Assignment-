
#include "LinkedList.h"
#include "AddressBook.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>


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

AddressBook::AddressBook() : LinkedList<Address>()
{
	//ctor
}

AddressBook::~AddressBook() 
{
	Node* prev = nullptr;
	Node* it = head;
	while (it != nullptr)
	{
		prev = it;
		it = it->next;
		delete prev;
	}
}

// Print all of the elements in the address book
void AddressBook::print()
{
	Node* it = head;
	while (it != nullptr)
	{
		std::cout << it->val << std::endl;
		it = it->next;
	
	}


}

// Removes the passed in name
void AddressBook::remove(std::string name)
{
	// Start the iterator at the head
	Node* it = head;
	Node* prev = nullptr;

	// While our iterator isnt null
	while (it != nullptr)
	{ 
	if (it == nullptr) return;
	
		// Get the current name out of the node
		std::string curName = ((Address)it->val).name;

		// If the current name and nameToBeDeleted are the same
		if (curName == name)
		
		{
			// If we are at the head, set it's next node to the iterators next value
			if (prev == nullptr)
			{
				head = it->next;
				delete it;
				
			}
			
			// Else set the previous values next value to the iterators next value
			else
			{
				prev->next = it->next;
				delete it;
				it = prev->next;
			}
			// Decrease the length on removal
			length--;
			break;
		}
		// Set the previous node to be the iterator
		prev = it;
		// Set the iterator to the next value
		it = it->next;
	}
}

// Returns the address at the name passed in, or an address whose name is NULL if the name isn't in the address book
Address AddressBook::get(std::string name)
{
	// Set the iterator to the head of the linked list
	Node* it = head;

	// While our name isn't found, and we haven't gone through the whole list
	while (it != nullptr)
	{
		// Extract the iterators name
		std::string curName = ((Address)it->val).name;

		// If the iterators name is equal to the wanted name, then the value is found and returned
		if (curName == name)
		{
			return it->val;
		}
		it = it->next;
	}

	// If the address wasn't found, return the address with the name of NULL
	Address nullAdd;
	nullAdd.name = "NULL";
	return nullAdd;
}

// Go through every address, print out birthday cards with the same date as string passed in
void AddressBook::generateBirthdayCards(std::string date)
{
	// Go through every address
	Node* it = head;
	while (it != nullptr)
	{
		// If it's birthday is equal to the date passed in, print it's birthday card
		Address curAddress = ((Address)it->val);
		if (date == curAddress.birthdayDate)
		{
			printBirthdayCard(curAddress);
		}
		it = it->next;
	}
}

void AddressBook::printBirthdayCard(Address curAddress)
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Dear " << curAddress.name << "," << std::endl << std::endl;
	std::cout << "Hope your birthday is really wonderful and this coming year is the best yet!" << std::endl;
	std::cout << "Love," << std::endl << std::endl;
	std::cout << "Dillon" << std::endl;
}

// Go through every address, print out anniversary cards with the same date as string passed in
void AddressBook::generateAnniversaryCards(std::string date)
{
	// Go through every address
	Node* it = head;
	while (it != nullptr)
	{
		// If it's anniversary is equal to the date passed in, print it's birthday card
		Address curAddress = ((Address)it->val);
		if (date == curAddress.anniversaryDate)
		{
			printAnniversaryCard(curAddress);
		}
		it = it->next;
	}
}

// Add an address to the book, make sure it is sorted alphabetically
void AddressBook::add(Address newAddress)
{
	// Create a new node with our address
	Node* newNode = new Node;
	newNode->val = newAddress;
	newNode->next = nullptr;

	// IF the head is null, the head and tail are both the new node
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		// Create an iterator, and previous iterator
		Node* prev = nullptr;
		Node* it = head;

		// Go through each element
		while (it != nullptr)
		{
			// If the current name is greater than the new name,
			std::string curName = ((Address)it->val).name;
			if (curName > newAddress.name)
			{
				// Add the new node at the last location, then rewire the list
				if (prev == nullptr)
				{
					head = newNode;
					newNode->next = it;
				}
				else
				{
					prev->next = newNode;
					newNode->next = it;
				}
				return;
			}
			else
			{
				// Else we go to the next node
				if (it->next == nullptr)
				{
					it->next = newNode;
					it = newNode->next;
				}
				else
				{
					prev = it;
					it = it->next;
				}

			}

		}
	}
	// Increment the length when an item is added
	length++;
}

void AddressBook::printAnniversaryCard(Address curAddress)
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Dear " << curAddress.name << "," << std::endl << std::endl;
	std::cout << "Hope your anniversary is really wonderful and this coming year is the best yet!" << std::endl;
	std::cout << "Love," << std::endl << std::endl;
	std::cout << "Dillon" << std::endl;
}

// Loads the address book from a properties file
void AddressBook::load()
{
	// Attempt to open the address file
	std::ifstream in;
	in.open("addresses.txt");

	// If the file didn't open, print an error message
	if (!in.good())
	{
		std::cerr << "Cannot open addresses.txt" << std::endl;
		return;
	}

	// While we can read without an error, keep adding addresses to our book
	while (in.good())
	{
		// Create new address, get all 4 elements
		Address* curAddress = new Address;
		std::string temp;

		getline(in, temp);
		curAddress->name = temp;

		getline(in, temp);
		curAddress->streetAddress = temp;

		getline(in, temp);
		curAddress->anniversaryDate = temp;

		getline(in, temp);
		curAddress->birthdayDate = temp;

		// If our input is still good after adding those 4 elements, add the new address.
		if (in.good())
		{
			add(*curAddress);
		}
	}

	// Close the file stream
	in.close();
}

// Save the address book
void AddressBook::save()
{
	// Open the file for our address book
	std::ofstream out;
	out.open("addresses.txt");

	// If it failed to open, print an error and end.
	if (!out.good())
	{
		std::cerr << "Cannot open addresses.txt" << std::endl;
		return;
	}

	// For every address
	Node* it = head;
	while (it != nullptr)
	{
		// Print it's information to a new line of the text file
		Address curAddress = (Address)it->val;
		out << curAddress.name << std::endl;
		out << curAddress.streetAddress << std::endl;
		out << curAddress.anniversaryDate << std::endl;
		out << curAddress.birthdayDate << std::endl;

		// Go to the next node
		it = it->next;
	}

	// Close the outstream
	out.close();
};
