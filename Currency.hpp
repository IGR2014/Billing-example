#pragma once
#ifndef BILLING_CURRENCY_HPP
#define BILLING_CURRENCY_HPP


#include <ostream>


// Main app namespace
namespace billing {


	// Currency representation class
	class Currency {

		unsigned int	wholePart;		// Whole dollars count
		unsigned char	fractionPart;		// Fraction dollars count (cents)


	public:

		// C-tor
		Currency() : wholePart(0), fractionPart(0) {};
		// D-tor
		~Currency();

		// Addition operator
		inline Currency operator+(const Currency &_cur);
		// Subtraction operator
		inline Currency operator-(const Currency &_cur);

		// Self-addition operator
		Currency& operator+=(const Currency &_cur);
		// Self-subtraction operator
		Currency& operator-=(const Currency &_cur);

		// Unary minus operator
		Currency operator-();

		// Print number to provided output stream
		std::ostream& print(std::ostream &os) const;


	};


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, Currency &_currency);


}	// namespace billing


#endif	// BILLING_CURRENCY_HPP

