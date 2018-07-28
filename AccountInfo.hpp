#pragma once
#ifndef BILLING_ACCOUNT_INFO_HPP
#define BILLING_ACCOUNT_INFO_HPP


#include <ostream>
#include <chrono>

#include "Currency.hpp"


// Main app namespace
namespace billing {


	// Call information storing class
	class AccountInfo {

		Currency		generalAcc;		// General account value
		std::chrono::seconds	lastCreditTime;		// Time when last credit was added


	public:

		// C-tor
		AccountInfo() : generalAcc(), lastCreditTime(0) {};
		// D-tor
		~AccountInfo();

		// Set call info
		AccountInfo(const Currency &_generalAcc, const std::chrono::seconds &_lastCreditTime) : generalAcc(_generalAcc), lastCreditTime(_lastCreditTime) {};

		// Set general account value
		void setGeneralAcc(const Currency &_generalAcc, const std::chrono::seconds &_lastCreditTime);

		// Get called number
		inline Currency getGeneralAcc() const {

			return generalAcc;

		}

		// Get call start time
		inline std::chrono::seconds getLastCreditTime() const {

			return lastCreditTime;

		}

		// Print number to provided output stream
		std::ostream& print(std::ostream &_os) const;


	};


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const AccountInfo &_accountInfo);


}	// namespace billing


#endif	// BILLING_ACCOUNT_INFO_HPP

