#include "Passenger.h"

namespace AirlineReservationSystemApp {
	Passenger::Passenger (const string& firstName,
		const string& lastName): mFirstName(firstName), mLastName(lastName) {

	}

	void Passenger::setPassengerNumber(int passengerNumber) {
		mPassengerNumber = passengerNumber;
	}

	int Passenger::getPassengerNumber() const {
		return mPassengerNumber;
	}

	void Passenger::setFirstName(const string& firstName) {
		mFirstName = firstName;
	}

	const string& Passenger::getFirstName() const {
		return mFirstName;
	}

	void Passenger::setLastName(const string& lastName) {
		mLastName = lastName;
	}

	const string& Passenger::getLastName() const {
		return mLastName;
	}

	void Passenger::setSex(const string& sex) {
		mSex = sex;
	}

	const string& Passenger::getSex() const {
		return mSex;
	}

	void Passenger::setBirthday(const string& birthday) {
		mBirthdate = birthday;
	}

	const string& Passenger::getBirthday() const {
		return mBirthdate;
	}

	void Passenger::setAddress(const string& address) {
		mAddress = address;
	}

	const string& Passenger::getAddress() const {
		return mAddress;
	}

	void Passenger::setPhoneNumber(const string& phoneNumber) {
		mPhoneNumber = phoneNumber;
	}

	const string& Passenger::getPhoneNumber() const {
		return mPhoneNumber;
	}

	void Passenger::setPassportNumber(const string& nationality) {
		mPassportNumber = nationality;
	}

	const string& Passenger::getPassportNumber() const {
		return mPassportNumber;
	}

	void Passenger::display() const {

		cout << "Passenger " << endl;
		cout << "---------------------------------" << endl;
		cout << "First Name      : " << getFirstName() << endl;
		cout << "Last Name       : " << getLastName() << endl;
		cout << "Sex/Gender      : " << getSex() << endl;
		cout << "Birthdate       : " << getBirthday() << endl;
		cout << "Address         : " << getAddress() << endl;
		cout << "Phone Number    : " << getPassengerNumber() << endl;
		cout << "Passport Number : " << getPassportNumber() << endl;
	}
}