#pragma once
#ifndef BILLING_MOBILE_NUMBER_HPP
#define BILLING_MOBILE_NUMBER_HPP


#include <ostream>


// Main app namespace
namespace billing {


	// Mobile number representation class
	class MobileNumber {

							// Country code	| Operaror code	| Subscriber number
		unsigned int	subsNumber;		// +38		| (XXX)		| THIS_FIELD
		unsigned char	opCode;			// +38		| (THIS_FIELD)	| XXX-XX-XX


	public:

		// C-tor
		MobileNumber() : subsNumber(0), opCode(0) {};
		// D-tor
		~MobileNumber();

		// Set mobile number
		MobileNumber(const unsigned char _opCode, const unsigned int _subsNumber);

		// Set operator's code
		inline void setOperator(const unsigned char _opCode) {

			opCode = _opCode;

		}

		// Set subscriber`s number
		inline void setSubscriber(const unsigned int _subsNumber) {

			subsNumber = _subsNumber;

		}

		// Set operator`s code and subscriber's number
		void set(const unsigned char _opCode, const unsigned int _subsNumber);

		// Get operator's code
		inline unsigned char getOperator() const  {

			return opCode;

		}

		// Get subscriber`s number
		inline unsigned char getSubscriber() const  {

			return subsNumber;

		}

		// Print number to provided output stream
		std::ostream& print(std::ostream &os) const;


	};


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &os, MobileNumber &mobileNumber);


}	// namespace billing


#endif	// BILLING_MOBILE_NUMBER_HPP

