#include <string>
#include <chrono>

#include "CallInfo.hpp"


// Main app namespace
namespace billing {


	// D-tor
	CallInfo::~CallInfo() {

		startTime = endTime = std::chrono::seconds(0);

	}


	// Set call info
	CallInfo::CallInfo(const MobileNumber &_number, const std::chrono::seconds &_startTime, const std::chrono::seconds &_endTime) {

		number		= _number;
		startTime	= _startTime;
		endTime		= _endTime;

	}


	// Set call timing
	void CallInfo::setTiming(const std::chrono::seconds &_startTime, const std::chrono::seconds &_endTime) {

		setTimingStart	(_startTime);
		setTimingEnd	(_endTime);

	}


	// Print number to provided output stream
	std::ostream& CallInfo::print(std::ostream &_os) const {

		unsigned long long timeSec	= std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime).count();
		unsigned long long timeInc	= ((((endTime - startTime).count() % 60L) == 0L) ? 0L : 1L);

		_os	<< "Call to "										\
			<< number										\
			<< " from "										\
			<< startTime.count()									\
			<< " to "										\
			<< endTime.count()									\
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

