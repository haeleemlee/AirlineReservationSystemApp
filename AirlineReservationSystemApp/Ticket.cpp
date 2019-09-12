#include "FlightScheduleDB.h"
#include "Ticket.h"
#include <iostream>

using namespace std;

namespace AirlineReservationSystemApp {

	Ticket::Ticket(const string& firstName,	const string& lastName)
		: mFirstName(firstName), mLastName(lastName) {
	}

	void Ticket::setTicketNumber(int ticketNumber) {
		mTicketNumber = ticketNumber;
	}

	int Ticket::getTicketNumber() const {
		return mTicketNumber;
	}

	void Ticket::setTicketPrice(int ticketPrice) {
		mTicketPrice = ticketPrice;
	}

	int Ticket::getTicketPrice() const {
		return mTicketPrice;
	}

	void Ticket::setTicketRefundable(bool ticketRefundable) {
		mTicketRefundable = ticketRefundable;
	}

	const bool Ticket::getTicketRefundable() const {
		return mTicketRefundable;
	}

	void Ticket::setFirstName(const string& firstName) {
		mFirstName = firstName;
	}

	const string& Ticket::getFirstName() const {
		return mFirstName;
	}

	void Ticket::setLastName(const string& lastName) {
		mLastName = lastName;
	}
	const string& Ticket::getLastName() const {
		return mLastName;
	}

	void Ticket::setFlightNumber(const int flightNumber) {
		mFlightNumber = flightNumber;
	}

	const int Ticket::getFlightNumber() const {
		return mFlightNumber;
	}

	void Ticket::setPassengerNumber(const int passengerNumber) {
		mPassengerNumber = passengerNumber;
	}
		
	const int Ticket::getPassengerNumber() const {
		return mPassengerNumber;
	}

	void Ticket::setSeatNumber(const string& seatNumber) {
		mSeatNumber = seatNumber;
	}

	const string& Ticket::getSeatNumber() const {
		return mSeatNumber;
	}

	void Ticket::setSeatClass(const string& seatClass) {
		mSeatClass = seatClass;
	}

	const string& Ticket::getSeatClass() const {
		return mSeatClass;
	}

	void Ticket::setNumofLuggage(const int numofLuggage) {
		mNumofLuggage = numofLuggage;
	}

	const int Ticket::getNumofLuggage() const {
		return mNumofLuggage;
	}

	void Ticket::display(const FlightSchedule& fs) const {
		
		cout << "Ticket Information " << endl;
		cout << "---------------------------------" << endl;
		cout << "Ticket Number      : " << getTicketNumber() << endl;
		cout << "First Name         : " << getFirstName() << endl;
		cout << "Last Name          : " << getLastName() << endl;
		cout << "Flight Number      : " << getFlightNumber() << endl;
		cout << "Departure Airport  : " << fs.getDepartureAirport() << endl;
		cout << "Departure Date     : " << fs.getDepartureDate() << endl;
		cout << "Departure Time     : " << fs.getDepartureTime() << endl;
		cout << "Arrival Airport    : " << fs.getDepartureAirport() << endl;
		cout << "Arrival Date       : " << fs.getDepartureDate() << endl;
		cout << "Arrival Time       : " << fs.getDepartureTime() << endl;
		cout << "Seat Number        : " << getSeatNumber() << endl;
		cout << "Seat Class         : " << getSeatClass() << endl;
		cout << "Num of Luggages    : " << getNumofLuggage() << endl;
		cout << "Ticket Price       : $" << getTicketPrice() << endl;
	}
}