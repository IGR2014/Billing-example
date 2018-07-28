#pragma once
#ifndef BILLING_CURRENCY_HPP
#define BILLING_CURRENCY_HPP


#include <ostream>


// Main app namespace
namespace billing {


	// Currency representation class
	class Currency {

		long long	cents;		// Cents count


	public:

		// C-tor
		Currency() : cents(0L) {};
		// D-tor
		~Currency();

		// Set currency
		explicit Currency(long long _cents) : cents(_cents) {};
		// Set currency #2
		Currency(const long long _dollars, const unsigned int _cents);

		// Addition operator
		Currency operator+(const Currency &_cur);
		// Subtraction operator
		Currency operator-(const Currency &_cur);

		// Self-addition operator
		Currency& operator+=(const Currency &_cur);
		// Self-subtraction operator
		Currency& operator-=(const Currency &_cur);

		// Unary minus operator
		Currency operator-();

		// Print number to provided output stream
		std::ostream& print(std::ostream &_os) const;


	};


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const Currency &_currency);


}	// namespace billing


#endif	// BILLING_CURRENCY_HPP

