#include <iostream>
#include <stdlib.h>
#include <string>
#include "LinkedList.h"
#include "AddressBook.h"
#include "Address.h"

using namespace std;
void mainMenu(AddressBook& addresses);
void enterName(AddressBook& addresses);
void remove(AddressBook& addresses);
void changeName(AddressBook& addresses);
void generateBirthdayCards(AddressBook& addresses);
void generateAnniversaryCards(AddressBook& addresses);


void resetInput();

int main()
{
	// Load the address book
	AddressBook addresses;
	addresses.load();

	// Start the mainMenu loop
	mainMenu(addresses);
	return 0;
}

void mainMenu(AddressBook& addresses)
{
	// Display main menu
	cout << "------------------Main menu------------------" << endl;
	cout << "[1]: Enter a new name into the address book" << endl;
	cout << "[2]: Delete a name from the address book" << endl;
	cout << "[3]: Change a name or date in the address book" << endl;
	cout << "[4]: Generate birthday cards" << endl;
	cout << "[5]: Generate anniversary cards" << endl;
	cout << "[6]: Save and exit the card program" << endl;
	cout << "[7]: Print address book." << endl;

	// Prompt for user input.
	cout << "Enter selection: ";

	// Cleanup to make sure cin is working before gathering user input
	resetInput();

	int code;
	cin >> code;
	cout << endl;

	// If their input failed, as they entered a word instead of a number
	while (cin.fail())
	{
		// Cleanup to make sure cin is working before gathering user input
		resetInput();

		// Prompts that input failed, trys to recollect input
		cout << "Input failed. Enter code here: ";
		cin >> code;
		cout << endl;
	}

	// Start the corresponding function the code that was entered.
	switch (code)
	{
	case 1:
		cout << "-----------------Enter Name------------------" << endl;
		enterName(addresses);
		break;
	case 2:
		cout << "-----------------Delete Name-----------------" << endl;
		remove(addresses);
		break;
	case 3:
		cout << "-----------------Change Name-----------------" << endl;
		changeName(addresses);
		break;
	case 4:
		cout << "---------------Birthday Cards----------------" << endl;
		generateBirthdayCards(addresses);
		break;
	case 5:
		cout << "-------------Anniversary Cards---------------" << endl;
		generateAnniversaryCards(addresses);
		break;
		// Saves and exits the program
	case 6:
		cout << "Now closing..." << endl;
		addresses.save();// Saves the addresses to the text file
		exit(0);// Exits the program
		break;
	case 7:
		cout << "----------------Address List-----------------" << endl;
		addresses.print();
		break;
	default:
		// The default operation will print wrong number.
		cerr << "Sorry, wrong number." << endl;
		break;
	};
	mainMenu(addresses);
}

void enterName(AddressBook& addresses)
{
	// Cleanup to make sure cin is working before gathering user input
	resetInput();

	// Fill out form, for name, address, anniversary date, and birthday
	Address cur;
	cout << "Enter name: ";
	getline(cin, cur.name);

	cout << "Enter Address: ";
	getline(cin, cur.streetAddress);

	cout << "Enter Anniversary Date: ";
	getline(cin, cur.anniversaryDate);

	cout << "Enter Birthday Date: ";
	getline(cin, cur.birthdayDate);

	cout << endl;

	// We then add the newly created address to the address book
	addresses.add(cur);
}

void remove(AddressBook& addresses)
{
	// Cleanup to make sure cin is working before gathering user input
	resetInput();

	// Get name to delete
	string name;
	cout << "Enter name to delete: ";
	getline(cin, name);

	// Get the address with the specific name
	Address addressToBeDeleted = addresses.get(name);

	// If the address is NULL, the entered name doesn't exist. Exit the function.
	if (addressToBeDeleted.name == "NULL")
	{
		cerr << "Entered name does not exist!" << endl;
		return;
	}


	// New Address that is being formed
	Address* changeAddress = new Address;
	changeAddress->streetAddress = addressToBeDeleted.streetAddress;
	changeAddress->anniversaryDate = addressToBeDeleted.anniversaryDate;
	changeAddress->birthdayDate = addressToBeDeleted.birthdayDate;

	// Remove it from the address book
	addresses.remove(name);
}

void changeName(AddressBook& addresses)
{
	// Cleanup to make sure cin is working before gathering user input
	resetInput();

	// Get name to rename
	string name;
	cout << "Enter name to rename: ";
	cin >> name;

	// Get the address with the specific name
	Address addressToBeDeleted = addresses.get(name);

	// If the address is NULL, the entered name doesn't exist. Exit the function.
	if (addressToBeDeleted.name == "NULL")
	{
		cerr << "Entered name does not exist!" << endl;
		return;
	}


	// New Address that is being formed
	Address* changeAddress = new Address;
	changeAddress->streetAddress = addressToBeDeleted.streetAddress;
	changeAddress->anniversaryDate = addressToBeDeleted.anniversaryDate;
	changeAddress->birthdayDate = addressToBeDeleted.birthdayDate;

	// Remove the old address
	addresses.remove(name);

	// Get the new name
	cout << "Enter new name: ";
	getline(cin, name);
	cout << endl;
	changeAddress->name = name;

	// Add the new address to the address book
	addresses.add(*changeAddress);
}

void generateBirthdayCards(AddressBook& addresses)
{
	// Cleanup to make sure cin is working before gathering user input
	resetInput();

	// Get date
	string date;
	cout << "Enter date: ";
	cin >> date;

	// Generate birthday cards for the date
	addresses.generateBirthdayCards(date);
}

void generateAnniversaryCards(AddressBook& addresses)
{
	// Cleanup to make sure cin is working before gathering user input
	resetInput();

	// Get date
	string date;
	cout << "Enter date: ";
	cin >> date;

	// Generate anniversary cards for the date
	addresses.generateAnniversaryCards(date);
}

// Cleanup to make sure cin is working before gathering user input
void resetInput()
{
	// If it's failed, ignore the whole line
	if (cin.fail())
	{
		// Removes any information user entered.
		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// If the next character is a newline, ignore it.
	if (cin.peek() == '\n')
	{
		cin.ignore();
	}
	

}