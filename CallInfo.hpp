#pragma once
#ifndef BILLING_CALL_INFO_HPP
#define BILLING_CALL_INFO_HPP


#include <ostream>
#include <chrono>

#include "MobileNumber.hpp"
#include "Currency.hpp"


// Main app namespace
namespace billing {


	// Not good but helps to reduce boilerplate code with std::chrono
	using namespace std::chrono;


	// Call information storing class
	class CallInfo {

		MobileNumber			number;			// Called mobile number
		system_clock::time_point	startTime;		// Call start time (seconds since epoch)
		system_clock::time_point	endTime;		// Call start time (seconds since epoch)
		Currency			callFee;		// Call fee (will be calculated)


	public:

		// C-tor
		CallInfo() : number(), startTime(system_clock::now()), endTime(system_clock::now()), callFee(0L) {};
		// D-tor
		~CallInfo();

		// Set call info
		CallInfo(const MobileNumber &_number, const system_clock::time_point &_startTime, const system_clock::time_point &_endTime);

		// Set called number
		void setNumber(const MobileNumber &_number);

		// Set call timing
		void setTiming(const system_clock::time_point &_startTime, const system_clock::time_point &_endTime);
		// Set call start time
		inline void setTimingStart(const system_clock::time_point &_startTime) {

			startTime = _startTime;

		}
		// Set call end time
		inline void setTimingEnd(const system_clock::time_point &_endTime) {

			endTime = _endTime;

		}
		// Set call fee
		inline void setFee(const Currency &_callFee) {

			callFee = _callFee;

		}

		// Get called number
		inline MobileNumber getNumber() const {

			return number;

		}

		// Get call start time
		inline system_clock::time_point getTimingStart() const {

			return startTime;

		}
		// Get call end time
		inline system_clock::time_point getTimingEnd() const {

			return endTime;

		}
		// Get call fee
		inline Currency getFee() const {

			return callFee;

		}

		// Print number to provided output stream
		std::ostream& print(std::ostream &_os) const;


	};


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const CallInfo &_callInfo);


}	// namespace billing


#endif	// BILLING_CALL_INFO_HPP

