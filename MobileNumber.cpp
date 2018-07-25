#include <iomanip>

#include "MobileNumber.hpp"


// Main app namespace
namespace billing {


	// D-tor
	MobileNumber::~MobileNumber() {

		subsNumber	= 0;
		opCode		= 0;

	}


	// Set mobile number
	MobileNumber::MobileNumber(const unsigned char _opCode, const unsigned int _subsNumber) {

		set	(std::forward<const unsigned char>(_opCode),
			 std::forward<const unsigned int>(_subsNumber));

	}


	// Set operator`s code and subscriber's number
	void MobileNumber::set(const unsigned char _opCode, const unsigned int _subsNumber) {

		setOperator	(std::forward<const unsigned char>(_opCode));
		setSubscriber	(std::forward<const unsigned int>(_subsNumber));

	}


	// Print number to provided output stream
	std::ostream& MobileNumber::print(std::ostream &_os) const {

		unsigned int subsNumber1 = subsNumber / 10000;
		unsigned int subsNumber2 = (subsNumber % 10000) / 100;
		unsigned int subsNumber3 = (subsNumber % 100);

		// Represent number as "+ 38 (0XX) YYY-YY-YY"
		_os	<< "+ 38 ("				\
			<< std::setw(3)				\
			<< std::setfill('0')			\
			<< static_cast<unsigned int>(opCode)	\
			<< ") "					\
			<< std::setw(3)				\
			<< std::setfill('0')			\
			<< subsNumber1				\
			<< "-"					\
			<< std::setw(2)				\
			<< std::setfill('0')			\
			<< subsNumber2				\
			<< "-"					\
			<< std::setw(2)				\
			<< std::setfill('0')			\
			<< subsNumber3;

		return _os;

	}


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, MobileNumber &_mobileNumber) {

		return _mobileNumber.print(_os);

	}


}	// namespace billing

