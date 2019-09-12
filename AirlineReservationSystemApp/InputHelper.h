#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace AirlineReservationSystemApp {
	class InputHelper {
	public:
		static Passenger inputPassengerInfo(PassengerDB& pdb);
		static bool inputTicketInfo(string firstName, string lastName, int flightNumber,
									int passengerNumber, FlightScheduleDB& fsdb, TicketDB& tkdb);
	private:
	};
}