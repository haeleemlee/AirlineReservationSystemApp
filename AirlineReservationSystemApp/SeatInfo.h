#pragma once
#include <iostream>
#include <vector>
#include <string>
#//include "Passenger.h"
//#include "Ticket.h"
//#include "FlightSchedule.h"
//#include "PassengerDB.h"
//#include "TicketDB.h"
//#include "FlightScheduleDB.h"

using namespace std;

namespace AirlineReservationSystemApp {
	class SeatInfo {
	public:
		int ticketNumber;
		string seatClass;
		int price;
	};
}