#include <iostream>
#include <stdexcept>
#include "FlightScheduleDB.h"

using namespace std;

namespace AirlineReservationSystemApp {

	FlightSchedule& FlightScheduleDB::addFlightSchedule() {
		FlightSchedule theFlightSchedule;
		theFlightSchedule.setFlightNumber(mNextFlightScheduleNumber++);
		mFlightSchedules.push_back(theFlightSchedule);

		return mFlightSchedules[mFlightSchedules.size() - 1];
	}

	FlightSchedule& FlightScheduleDB::getFlightSchedule(int flightNumber) {
		for (auto& flightSchedule : mFlightSchedules) {
			if (flightSchedule.getFlightNumber() == flightNumber) {
				return flightSchedule;
			}
		}
		throw logic_error("No FlightSchedule found");
	}

	bool FlightScheduleDB::isExist(int flightNumber) {

		if (flightNumber < kFirstFlightScheduleNumber ||
			flightNumber >= mNextFlightScheduleNumber) {
			return false;
		}
		
		return true;
	}

	bool FlightScheduleDB::isExist(int flightNumber, vector<int> flightNumbers) {

		for (auto& num : flightNumbers) {
			if (num == flightNumber) {
				return true;
			}
		}

		return false;
	}

	vector<int> FlightScheduleDB::search(const string& departureAirport, const string& arrivalAirport, const string& departureDate) {
		vector<int> selectedFlightNum;

		for (auto& fs : mFlightSchedules) {
			if (fs.getDepartureAirport() == departureAirport &&
				fs.getArrivalAirport() == arrivalAirport &&
				fs.getDepartureDate() == departureDate) {
				selectedFlightNum.push_back(fs.getFlightNumber());
			}
		}
		
		return selectedFlightNum;
	}


	void FlightScheduleDB::displayAll() const {
		for (const auto& flightSchedule : mFlightSchedules) {
			flightSchedule.display();
		}
	}
}