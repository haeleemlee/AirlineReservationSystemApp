#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "SeatInfo.h"

using namespace std;

namespace AirlineReservationSystemApp {
	class FlightSchedule {
	public:
		FlightSchedule() = default;
		FlightSchedule(int flightNumber);

		void setFlightNumber(int flightNumber);
		int getFlightNumber() const;

		void setDepartureDate(string departureDate);
		const string& getDepartureDate() const;

		void setDepartureTime(string departureTime);
		const string& getDepartureTime() const;

		void setDepartureAirport(string departureAirport);
		const string& getDepartureAirport() const;

		void setArrivalDate(string ArrivalDate);
		const string& getArrivalDate() const;

		void setArrivalTime(string ArrivalTime);
		const string& getArrivalTime() const;

		void setArrivalAirport(string ArrivalAirport);
		const string& getArrivalAirport() const;

		void setTicketPrice(int ticketPrice);
		const int getTicketPrice() const;

		void setTicketRefundable(bool ticketRefundable);
		const bool getTicketRefundable() const;

		void setReservedSeatAgent(vector<string> seats, vector<SeatInfo> seatInfo);
		void ResearvingSeatAgent(string seatNumber, int ticketNumber);
		unordered_map<string, SeatInfo>& getReservedSeatAgent();
		
		void display() const;

	private:
		int mFlightNumber;
		string mDepartureDate;
		string mDepartureTime;
		string mDepartureAirport;
		string mArrivalDate;
		string mArrivalTime;
		string mArrivalAirport;
		int mTicketPrice;
		bool mTicketRefundable;
		unordered_map<string, SeatInfo> mSeatMap;

	};
}
