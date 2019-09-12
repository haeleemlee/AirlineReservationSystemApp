#include <iostream>
#include <stdexcept>
#include "FlightScheduleDB.h"
#include "TicketDB.h"

using namespace std;

namespace AirlineReservationSystemApp {
	Ticket& TicketDB::addTicket() {
		Ticket theTicket;
		theTicket.setTicketNumber(mNextTicketNumber++);
		mTickets.push_back(theTicket);

		return mTickets[mTickets.size() - 1];
	}
	Ticket& TicketDB::getTicket(int ticketNumber) {
		for (auto& ticket : mTickets) {
			if (ticket.getTicketNumber() == ticketNumber) {
				return ticket;
			}
		}
		throw logic_error("No Ticket found");
	}
	Ticket& TicketDB::getTicket(const string& firstName, const string& lastName) {
		for (auto& ticket : mTickets) {
			if (ticket.getFirstName() == firstName && ticket.getLastName() == lastName) {
				return ticket;
			}
		}
		throw logic_error("NO Ticket found");
	}

	bool TicketDB::isExist(int ticketNumber) {

		if (ticketNumber < kFirstTicketNumber ||
			ticketNumber >= mNextTicketNumber) {
			return false;
		}

		return true;
	}

	void TicketDB::displayAll(FlightScheduleDB& fsdb) {
		for (const auto& ticket : mTickets) {
			FlightSchedule& fs = fsdb.getFlightSchedule(ticket.getFlightNumber());
			ticket.display(fs);
		}
	}
}