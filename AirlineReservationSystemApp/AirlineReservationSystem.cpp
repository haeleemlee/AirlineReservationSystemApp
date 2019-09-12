// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "PassengerDB.h"
#include "Passenger.h"
#include "FlightScheduleDB.h"
#include "TicketDB.h"
#include "FlightSchedule.h"
#include "Ticket.h"
#include "InputHelper.h"

using namespace std;
using namespace AirlineReservationSystemApp;

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Airline Reservation System" << endl;
	cout << "-----------------" << endl;
	cout << "1) Find your flight schedule" << endl;
	cout << "2) Reserve a seat" << endl;
	cout << "3) Display passenger Information" << endl;
	cout << "4) Flight Details" << endl;
	cout << "5) User ticket information" << endl;
	cout << "6) Exit" << endl;
	cout << endl;
	cout << "---> ";

	cin >> selection;

	return selection;
}

void prepareFlightSchedule(FlightScheduleDB& fsdb, TicketDB& tdb) {
	const int numData = 5;

	string departureAirportList[numData] = { "LAX", "SEA", "LAX", "SEA", "LAX"};
	string arrivalAirportList[numData] = { "SEA", "LAX", "SEA", "LAX", "SEA" };
	string departureDateList[numData] = { "01/02/2020", "01/02/2020", "01/02/2020", "01/03/2020", "01/03/2020" };
	string arrivalDateList[numData] = { "01/02/2020", "01/02/2020", "01/02/2020", "01/03/2020", "01/03/2020" };
	string departureTimeList[numData] = { "09:05", "11:30", "17:55", "09:05", "11:33" };
	string arrivalTimeList[numData] = { "11:30", "13:55", "20:05", "11:40", "13:45" };

	vector<string> availSeats = { "1A", "1B", "2A", "2B", "3A", "3C" };
	vector<SeatInfo> seatInformation = { {0, "Business", 470},{0, "Economy", 240},{0, "Economy", 240},{0, "Business", 470},{0, "Economy", 240},{0, "Economy", 240} };

	for (int i = 0; i < numData; i++) {
		FlightSchedule& fs = fsdb.addFlightSchedule();
		fs.setDepartureAirport(departureAirportList[i]);
		fs.setArrivalAirport(arrivalAirportList[i]);
		fs.setDepartureDate(departureDateList[i]);
		fs.setDepartureTime(departureTimeList[i]);
		fs.setArrivalDate(arrivalDateList[i]);
		fs.setArrivalTime(arrivalTimeList[i]);
		fs.setReservedSeatAgent(availSeats, seatInformation);
	}
}

void findFlightSchedule(FlightScheduleDB& fsdb) {

	string departureAirport;
	string departureDate;
	string departureTime;
	string arrivalAirport;
	int numfs = 0;
	int selFlightNum;
	int subMenuSel;

	cout << "Select One of the following Options" << endl;
	cout << "1. Search your flight schedule by {Departure Airport / Arrival Airport / Departure Date} " << endl;
	cout << "2. Display all Flight Schedule information" << endl;
	cin >> subMenuSel;

	if (subMenuSel == 1) {

		cout << "Please enter the departing airport" << endl;
		cout << "---> ";
		cin >> departureAirport;
		cout << "Please enter the arrival airport" << endl;
		cout << "---> ";
		cin >> arrivalAirport;
		cout << "Please enter the departing date" << endl;
		cout << "---> ";
		cin >> departureDate;

		cout << endl << "Flight(s) from " << departureAirport << " to " << arrivalAirport << " on " << departureDate << endl << endl;

		vector<int> selectedFN = fsdb.search(departureAirport, arrivalAirport, departureDate);

		for (auto& num : selectedFN) {
			const FlightSchedule& fs = fsdb.getFlightSchedule(num);
			cout << "Flight Number | Departure Time--Arrival Time " << endl;
			cout << "      " << fs.getFlightNumber() << "              " << fs.getDepartureTime() << " -- " << fs.getArrivalTime() << endl;
		}
	}
	else if (subMenuSel == 2) {
		fsdb.displayAll();
	}

	else {
		cout << "Invalid input: Return to the main menu" << endl;
	}

#if 0
	while (1) {
		cout << "Please select one Flight Number from the list above OR type 0 for cancel" << endl;
		cout << "---> ";
		cin >> selFlightNum;
		
		if (selFlightNum == 0) {
			return;
		}

		if (!fsdb.isExist(selFlightNum, selectedFN)) {
			cout << "wrong selection" << endl;
			cout << "please select one Flight Number from the list above OR type 0 for cancel" << endl;
		}
		else {
			break;
		}
	}
#endif
}

void doReserveSeat(FlightScheduleDB & fsdb, PassengerDB & pdb, TicketDB & tdb){
	
	int flightNumber;

	cout << "Please enter Flight Number" << endl;
	cin >> flightNumber;
	FlightSchedule& fs = fsdb.getFlightSchedule(flightNumber);

	cout << "Flight Number  Departure---Arrival   Departure Date      Dep.Time---Arr.Time" << endl;
	cout << "     " << flightNumber << "         " << fs.getDepartureAirport() << "---" << fs.getArrivalAirport() << "             "
		<< fs.getDepartureDate() << "           " << fs.getDepartureTime() << "---" << fs.getArrivalTime() << endl;

	while (1) {
		char ans;
		int numPassenger = 0;

		Passenger ps = InputHelper::inputPassengerInfo(pdb);
		bool ret = InputHelper::inputTicketInfo(ps.getFirstName(), ps.getLastName(), flightNumber, ps.getPassengerNumber(), fsdb, tdb);

		if (ret == false) {
			return;
		}

		numPassenger++;

		cout << "More passenger? (Y/N): ";
		cin >> ans;

		if (ans == 'N' || ans == 'n') {
			break;
		}
		else if (ans == 'Y' || ans == 'y') {
			continue;
		}
		else {
			cout << "Please type Y or N." << endl;
		}
	}
}

void doDisplayPassengerInfo(PassengerDB& pdb, TicketDB& tdb) {

	int subMenuSel;
	int ticketNumber;
	
	cout << "Select One of the following Options" << endl;
	cout << "1. Display the passenger information of the ticket number provided" << endl;
	cout << "2. Display all passengers information" << endl;
	cin >> subMenuSel;

	if (subMenuSel == 1) {

		cout << "Please enter a ticket number (100 ~ ): ";
		cin >> ticketNumber;
				 
		if (tdb.isExist(ticketNumber)) {
			Passenger& p = pdb.getPassenger(tdb.getTicket(ticketNumber).getPassengerNumber());
			p.display();
		}
		else {
			cout << "Invalid Ticket Number " << endl;
			return;
		}
	}
	else if (subMenuSel == 2) {

		pdb.displayAll();
	}
	else {
		cout << "Invalid input: Return to the main menu" << endl;
	}

	return; 
}

void doDisplayFlightDetail(FlightScheduleDB& fsdb) {
	int flightNumber;

	cout << "Please enter Flight Number : ";
	cin >> flightNumber;
	FlightSchedule& fs = fsdb.getFlightSchedule(flightNumber);
	fs.display();
}

void doDisplayUserTicketInfo(FlightScheduleDB& fsdb, TicketDB& tdb) {

	int subMenuSel;
	int ticketNumber;

	cout << "Select One of the following Options" << endl;
	cout << "1. Display the Ticket information of the ticket number provided" << endl;
	cout << "2. Display all Tickets information" << endl;
	cin >> subMenuSel;

	if (subMenuSel == 1) {

		cout << "Please enter a ticket number (100 ~ ): ";
		cin >> ticketNumber;

		if (tdb.isExist(ticketNumber)){
			Ticket& t = tdb.getTicket(ticketNumber);
			FlightSchedule& fs = fsdb.getFlightSchedule(t.getFlightNumber());

			t.display(fs);
		}
		else {
			cout << "Invalid Ticket Number " << endl;
			return;
		}
	}
	else if (subMenuSel == 2) {

		tdb.displayAll(fsdb);
	}
	else {
		cout << "Invalid input: Return to the main menu" << endl;
	}

	return;
}


int main()
{
	PassengerDB passengerDB;
	TicketDB ticketDB;
	FlightScheduleDB flightScheduleDB;
	InputHelper inputHelper;

	prepareFlightSchedule(flightScheduleDB, ticketDB);

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			findFlightSchedule(flightScheduleDB);
			break;
		case 2:
			doReserveSeat(flightScheduleDB, passengerDB, ticketDB);
			break;
		case 3:
			doDisplayPassengerInfo(passengerDB, ticketDB);
			break;
		case 4:
			doDisplayFlightDetail(flightScheduleDB);
			break;
		case 5:
			doDisplayUserTicketInfo(flightScheduleDB, ticketDB);
			break;
		case 6:
			return 0;

		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}
}
