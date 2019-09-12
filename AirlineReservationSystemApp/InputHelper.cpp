#pragma once
#include "PassengerDB.h"
#include "Passenger.h"
#include "FlightScheduleDB.h"
#include "TicketDB.h"
#include "FlightSchedule.h"
#include "Ticket.h"
#include "InputHelper.h"

using namespace std;

namespace AirlineReservationSystemApp {

	Passenger InputHelper::inputPassengerInfo(PassengerDB& pdb) {

		string firstName;
		string lastName;
		string sex;
		string birthday;
		string address;
		string phoneNumber;
		string passportNumber;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter passenger information" << endl;
		cout << "First Name: ";
		std::getline(std::cin, firstName);
		cout << "Last Name:  ";
		std::getline(std::cin, lastName);
		cout << "Sex/Gender: ";
		std::getline(std::cin, sex);
		cout << "Birthdate:  ";
		std::getline(std::cin, birthday);
		cout << "Address:    ";
		std::getline(std::cin, address);
		cout << "Phone Number: ";
		std::getline(std::cin, phoneNumber);
		cout << "Passport Number: ";
		std::getline(std::cin, passportNumber);
		cout << endl;

		Passenger& ps = pdb.addPassenger(firstName, lastName);
		ps.setFirstName(firstName);
		ps.setLastName(lastName);
		ps.setSex(sex);
		ps.setBirthday(birthday);
		ps.setAddress(address);
		ps.setPhoneNumber(phoneNumber);
		ps.setPassportNumber(passportNumber);
		
		return ps;
	}

	bool InputHelper::inputTicketInfo(string firstName, string lastName, int flightNumber,  
										int passengerNumber, FlightScheduleDB& fsdb, TicketDB& tkdb) {
		
		string mySeatNum;
		int Num_luggage = 0;
		int cnt = 0;

		cout << "Please choose your seat from the following available seats" << endl;
		

		unordered_map<string, SeatInfo>& reservedSeat = fsdb.getFlightSchedule(flightNumber).getReservedSeatAgent();

		for (auto seatNum = reservedSeat.begin(); seatNum != reservedSeat.end(); ++seatNum){
			if (seatNum->second.ticketNumber == 0) { 
				cout << seatNum->first << "  ";
			}
		}

		while (1) {
			if (cnt > 2) {
				cout << "Return to the main menu" << endl;
				return false;
			}
			else {
				cout << endl << "Your seat choice : ";
				cin >> mySeatNum;
				if (reservedSeat.find(mySeatNum) == reservedSeat.end()) {
					cout << "Entered Seat number is not valid. Please try again." << endl;
				}
				else {
					break;
				}
			}
			cnt++;
		}

		cout << endl << "Number of your luggages: ";
		cin >> Num_luggage;

		Ticket& tk = tkdb.addTicket();

		fsdb.getFlightSchedule(flightNumber).ResearvingSeatAgent(mySeatNum, tk.getTicketNumber());
		
		tk.setFirstName(firstName);
		tk.setLastName(lastName);
		tk.setFlightNumber(flightNumber);
		tk.setTicketPrice(fsdb.getFlightSchedule(flightNumber).getReservedSeatAgent()[mySeatNum].price);
		tk.setSeatClass(fsdb.getFlightSchedule(flightNumber).getReservedSeatAgent()[mySeatNum].seatClass);
		tk.setPassengerNumber(passengerNumber);
		tk.setSeatNumber(mySeatNum);
		tk.setNumofLuggage(Num_luggage);

		return true;
	}
}