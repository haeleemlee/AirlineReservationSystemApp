using namespace std;

#include "FlightSchedule.h"

namespace AirlineReservationSystemApp {

	FlightSchedule::FlightSchedule(int flightNumber) : mFlightNumber(flightNumber) {

	}

	void FlightSchedule::setFlightNumber(int flightNumber) {
		mFlightNumber = flightNumber;
	}

	int FlightSchedule::getFlightNumber() const {
		return mFlightNumber;
	}

	void FlightSchedule::setDepartureDate(string departureDate) {
		mDepartureDate = departureDate;
	}

	const string& FlightSchedule::getDepartureDate() const {
		return mDepartureDate;
	}

	void FlightSchedule::setDepartureTime(string departureTime) {
		mDepartureTime = departureTime;
	}

	const string& FlightSchedule::getDepartureTime() const {
		return mDepartureTime;
	}

	void FlightSchedule::setDepartureAirport(string departureAirport) {
		mDepartureAirport = departureAirport;
	}

	const string& FlightSchedule::getDepartureAirport() const {
		return mDepartureAirport;
	}

	void FlightSchedule::setArrivalDate(string arrivalDate) {
		mArrivalDate = arrivalDate;
	}
	const string& FlightSchedule::getArrivalDate() const {
		return mArrivalDate;
	}

	void FlightSchedule::setArrivalTime(string arrivalTime) {
		mArrivalTime = arrivalTime;
	}

	const string& FlightSchedule::getArrivalTime() const {
		return mArrivalTime;
	}

	void FlightSchedule::setArrivalAirport(string arrivalAirport) {
		mArrivalAirport = arrivalAirport;
	}

	const string& FlightSchedule::getArrivalAirport() const {
		return mArrivalAirport;
	}

	void FlightSchedule::setTicketPrice(int ticketPrice) {
		mTicketPrice = ticketPrice;
	}
	const int FlightSchedule::getTicketPrice() const {
		return mTicketPrice;
	}

	void FlightSchedule::setTicketRefundable(bool ticketRefundable) {
		mTicketRefundable = ticketRefundable;
	}
	const bool FlightSchedule::getTicketRefundable() const {
		return mTicketRefundable;
	}	

	void FlightSchedule::setReservedSeatAgent(vector<string> seats, vector<SeatInfo> seatInfo) {
		for (int i = 0; i < seats.size(); i++) {
			mSeatMap[seats[i]] = seatInfo[i];
		}
	}

	void FlightSchedule::ResearvingSeatAgent(string seatNumber, int ticketNumber) {
		mSeatMap[seatNumber].ticketNumber = ticketNumber;
	}

	unordered_map<string, SeatInfo>& FlightSchedule::getReservedSeatAgent() {
		return mSeatMap;
	}

	void FlightSchedule::display() const {

		cout << "Flight Schedule " << endl;
		cout << "---------------------------------" << endl;
		cout << "Flight Number     : " << getFlightNumber() << endl;
		cout << "Departure Date    : " << getDepartureDate() << endl;
		cout << "Departure Time    : " << getDepartureTime() << endl;
		cout << "Departure Airport : " << getDepartureAirport() << endl;
		cout << "Arrival Date      : " << getArrivalDate() << endl;
		cout << "Arrival Time      : " << getArrivalTime() << endl;
		cout << "Arrival Airport   : " << getArrivalAirport() << endl << endl;
	}
}