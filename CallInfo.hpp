#pragma once
#ifndef BILLING_CALL_INFO_HPP
#define BILLING_CALL_INFO_HPP


#include <ostream>
#include <chrono>

#include "MobileNumber.hpp"


// Main app namespace
namespace billing {


	// Call information storing class
	class CallInfo {

		MobileNumber		number;			// Called mobile number
		std::chrono::seconds	startTime;		// Call start time (seconds since epoch)
		std::chrono::seconds	endTime;		// Call start time (seconds since epoch)


	public:

		// C-tor
		CallInfo() : number(), startTime(0), endTime(0) {};
		// D-tor
		~CallInfo();

		// Set call info
		CallInfo(const MobileNumber &_number, const std::chrono::seconds &_startTime, const std::chrono::seconds &_endTime);

		// Set called number
		void setNumber(const MobileNumber &_number);

		// Set call timing
		void setTiming(const std::chrono::seconds &_startTime, const std::chrono::seconds &_endTime);
		// Set call start time
		inline void setTimingStart(const std::chrono::seconds &_startTime) {

			startTime = _startTime;

		}
		// Set call end time
		inline void setTimingEnd(const std::chrono::seconds &_endTime) {

			endTime = _endTime;

		}

		// Get called number
		inline MobileNumber getNumber() const {

			return number;

		}

		// Get call start time
		inline std::chrono::seconds getTimingStart() const {

			return startTime;

		}
		// Get call end time
		inline std::chrono::seconds getTimingEnd() const {

			return endTime;

		}

		// Print number to provided output stream
		std::ostream& print(std::ostream &_os) const;


	};


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const CallInfo &_callInfo);


}	// namespace billing


#endif	// BILLING_CALL_INFO_HPP

