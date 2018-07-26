#include "Currency.hpp"


// Main app namespace
namespace billing {


	// D-tor
	Currency::~Currency() {

		cents = 0L;

	}


	// Set currency
	Currency::Currency(const long long _dollars, const unsigned int _cents) {

		// Store currency in cents for safety
		// (floats are not sufficient for currency calculations)
		cents = _dollars * 100L + _cents;

	}


	// Addition operator
	Currency Currency::operator+(const Currency &_cur) {

		return Currency(cents + _cur.cents);

	}

	// Subtraction operator
	Currency Currency::operator-(const Currency &_cur) {

		return Currency(cents - _cur.cents);

	}


	// Self-addition operator
	Currency& Currency::operator+=(const Currency &_cur) {

		cents += _cur.cents;

		return *this;

	}

	// Self-subtraction operator
	Currency& Currency::operator-=(const Currency &_cur) {

		cents += _cur.cents;

		return *this;

	}


	// Unary minus operator
	Currency Currency::operator-() {

		return Currency(-cents);

	}


	// Print number to provided output stream
	std::ostream& Currency::print(std::ostream &_os) const {

		//Whole dollars count
		long long dollars	= cents / 100L;
		// Whole cents count
		long long _cents	= cents % 100L;

		// Formatted currency output
		_os	<< "$"		\
			<< dollars	\
			<< "."		\
			<< _cents;

		return _os;

	}


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const Currency &_currency) {

		return _currency.print(_os);

	}


}	// namespace billing

