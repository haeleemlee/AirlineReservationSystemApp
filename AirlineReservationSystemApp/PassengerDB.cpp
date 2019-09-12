#include <iostream>
#include <stdexcept>
#include "PassengerDB.h"

using namespace std;

namespace AirlineReservationSystemApp {
	Passenger& PassengerDB::addPassenger(const string& firstName, const string& lastName) {
		Passenger thePassenger(firstName, lastName);
		thePassenger.setPassengerNumber(mNextPassengerNumber++);
		mPassengers.push_back(thePassenger);
		                               
		return mPassengers[mPassengers.size() - 1];
	}

	Passenger& PassengerDB::getPassenger(int passengerNumber) {
		for (auto& passenger : mPassengers) {
			if (passenger.getPassengerNumber() == passengerNumber) {
				return passenger;
			}
		}
		throw logic_error("No passenger found");
	}

	Passenger& PassengerDB::getPassenger(const string& firstName, const string& lastName) {
		for (auto& passenger : mPassengers) {
			if (passenger.getFirstName() == firstName && passenger.getLastName() == lastName) {
				return passenger;
			}
		}
		throw logic_error("NO passenger found");
	}

	void PassengerDB::displayAll() const {
		for (const auto& passenger : mPassengers) {
			passenger.display();
		}
	}
}