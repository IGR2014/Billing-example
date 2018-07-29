#include <iomanip>

#include "AccountInfo.hpp"


namespace billing {


	// D-tor
	AccountInfo::~AccountInfo() {

		lastCreditTime = system_clock::now();

	}


	// Set call info
	void AccountInfo::setGeneralAcc(const Currency &_generalAcc, const system_clock::time_point &_lastCreditTime) {

		generalAcc	= _generalAcc;
		lastCreditTime	= _lastCreditTime;

	}


	// Print number to provided output stream
	std::ostream& AccountInfo::print(std::ostream &_os) const {

		auto creditTime	= system_clock::to_time_t(lastCreditTime);

		_os	<< "General account: "					\
			<< generalAcc						\
			<< " (last credit added "				\
			<< std::put_time(std::localtime(&creditTime), "%c")	\
			<< ")";

		return _os;

	}


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const AccountInfo &_accountInfo) {

		return _accountInfo.print(_os);

	}


}

