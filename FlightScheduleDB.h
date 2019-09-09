#pragma once

#include <iostream>
#include <vector>
#include "FlightSchedule.h"

namespace AirlineReservationSystemApp {
	const int kFirstFlightScheduleNumber = 1000;

	class FlightScheduleDB {
	public:
		FlightSchedule& addFlightSchedule();
		FlightSchedule& getFlightSchedule(int flightNumber);
		bool isExist(int flightNumber);
		static bool isExist(int flightNumber, vector<int> flightNumbers);
		vector<int> search(const string& departureAirport, const string& arrivalAirport, const string& departureDate);

		void displayAll() const;
		
	private:
		vector<FlightSchedule> mFlightSchedules;
		int mNextFlightScheduleNumber = kFirstFlightScheduleNumber;
	};
}
