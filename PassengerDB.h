#pragma once

#include <iostream>
#include <vector>
#include "Passenger.h"
using namespace std;
namespace AirlineReservationSystemApp {
	const int kFirstPassengerNumber = 10;

	class PassengerDB {
	public:
		Passenger& addPassenger(const string& firstName, const string& lastName);
		Passenger& getPassenger(int passengerNumber);
		Passenger& getPassenger(const string& firstName, const string& lastName);

		void displayAll() const;
		
	private:
		vector<Passenger> mPassengers;
		int mNextPassengerNumber = kFirstPassengerNumber;
	};
}
