#include <string>
#include <chrono>
#include <iomanip>

#include "CallInfo.hpp"


// Main app namespace
namespace billing {


	// D-tor
	CallInfo::~CallInfo() {

		startTime = endTime = system_clock::now();

	}


	// Set call info
	CallInfo::CallInfo(const MobileNumber &_number, const system_clock::time_point &_startTime, const system_clock::time_point &_endTime) {

		number		= _number;
		startTime	= _startTime;
		endTime		= _endTime;

	}


	// Set call timing
	void CallInfo::setTiming(const system_clock::time_point &_startTime, const system_clock::time_point &_endTime) {

		setTimingStart	(_startTime);
		setTimingEnd	(_endTime);

	}


	// Print number to provided output stream
	std::ostream& CallInfo::print(std::ostream &_os) const {

		auto timeSec		= duration_cast<minutes>(endTime - startTime).count();
		auto timeInc		= ((((endTime - startTime).count() % 60L) == 0L) ? 0L : 1L);

		auto callStartTime	= system_clock::to_time_t(startTime);
		auto callEndTime	= system_clock::to_time_t(endTime);

		_os	<< "Call to "										\
			<< number										\
			<< " from "										\
			<< std::put_time(std::localtime(&callStartTime), "%c")					\
			<< " to "										\
			<< std::put_time(std::localtime(&callEndTime), "%c")					\
			<< " lasts "										\
			<< timeSec + timeInc									\
			<< " minutes";

		return _os;

	}


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const CallInfo &_callInfo) {

		return _callInfo.print(_os);

	}


}	// namespace billing

