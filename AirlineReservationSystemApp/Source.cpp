#pragma once
#include "InputHelper.h"

using namespace std;

namespace AirlineReservationSystemApp {

	Passenger InputHelper::inputPassengerInfo() {
		Passenger ps;
		PassengerDB pdb;

		string firstName;
		string lastName;
		char sex;
		string birthday;
		string address;
		string phoneNumber;
		string nationality;

		cout << "Please input passenger information" << endl;
		cout << "First Name: ";
		cin >> firstName << endl;
		cout << "Last Name:  ";
		cin >> lastName << endl;
		cout << "Sex/Gender: ";
		cin >> sex << endl;
		cout << "Birthdate:  ";
		cin >> birthday << endl;
		cout << "Address:    ";
		cin >> address << endl;
		cout << "Phone Number:";
		cin >> phoneNumber << endl;
		cout << "Nationality:";
		cin >> nationality << endl;

		ps.setPassengerNumber(int passengerNumber);
		ps.setFirstName(firstName);
		ps.setLastName(lastName);
		ps.setSex(mSex);
		ps.setBirthday(birthday);
		ps.setAddress(address);
		ps.setPhoneNumber(phoneNumber);
		ps.setNationality(nationality);

		pdb.addPassenger(firstName, lastName);

		return ps;
	}
	
	Ticket InputHelper::inputTicketInfo() {

	}

	
}