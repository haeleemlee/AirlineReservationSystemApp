#pragma once

#include <iostream>
#include <vector>
#include "Ticket.h"

using namespace std;

namespace AirlineReservationSystemApp {
	const int kFirstTicketNumber = 100;

	class TicketDB {
	public:
		Ticket& addTicket();
		Ticket& getTicket(int ticketNumber);
		Ticket& getTicket(const string& firstName, const string& lastName);
		bool isExist(int ticketNumber);

		void displayAll(FlightScheduleDB& fsdb);

	private:
		vector<Ticket> mTickets;
		int mNextTicketNumber = kFirstTicketNumber;

	};
}
