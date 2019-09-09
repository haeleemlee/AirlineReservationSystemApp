#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace AirlineReservationSystemApp {
	class Passenger {
	public:
		Passenger() = default;
		Passenger(const string& firstName,
			const string& lastName);

		void setPassengerNumber(int passengerNumber);
		int getPassengerNumber() const;

		void setFirstName(const string& firstName);
		const string& getFirstName() const;

		void setLastName(const string& lastName);
		const string& getLastName() const;

		void setSex(const string& mSex);
		const string& getSex() const;

		void setBirthday(const string& birthday);
		const string& getBirthday() const;

		void setAddress(const string& address);
		const string& getAddress() const;

		void setPhoneNumber(const string& phoneNumber);
		const string& getPhoneNumber() const;

		void setPassportNumber(const string& passportNumber);
		const string& getPassportNumber() const;

		void display() const;
			   		 
	private:
		int mPassengerNumber;
		string mFirstName;
		string mLastName;
		string mSex;
		string mBirthdate;
		string mAddress;
		string mPhoneNumber;
		string mPassportNumber;
	};
}