#pragma once
#include <string>

using namespace std;

namespace AirlineReservationSystemApp {
	class Ticket {
	public:
		Ticket() = default;
		Ticket(const string& firstName,
			const string& lastName);
		
		void setTicketNumber(int ticketNumber);
		int getTicketNumber() const;
	
		void setTicketPrice(int ticketPrice);
		int getTicketPrice() const;
	
		void setTicketRefundable(bool ticketRefundable);
		const bool getTicketRefundable() const;
	
		void setFirstName(const string& firstName);
		const string& getFirstName() const;

		void setLastName(const string& lastName);
		const string& getLastName() const;

		void setFlightNumber(const int flightNumber);
		const int getFlightNumber() const;

		void setPassengerNumber(const int passengerNumber);
		const int getPassengerNumber() const;

		void setSeatNumber(const string& seatNumber);
		const string& getSeatNumber() const;

		void setSeatClass(const string& seatClass);
		const string& getSeatClass() const;

		void setNumofLuggage(const int numofLuggage);
		const int getNumofLuggage() const;

		void display(const FlightSchedule& fs) const;

	private:
		int mTicketNumber;
		int  mTicketPrice;
		bool mTicketRefundable;
		string mFirstName;
		string mLastName;
		int mFlightNumber;
		int mPassengerNumber;
		string mSeatNumber;
		string mSeatClass;
		int mNumofLuggage;
	};
}