#include "AccountInfo.hpp"


namespace billing {


	// D-tor
	AccountInfo::~AccountInfo() {

		lastCreditTime = std::chrono::seconds(0);

	}


	// Set call info
	void AccountInfo::setGeneralAcc(const Currency &_generalAcc, const std::chrono::seconds &_lastCreditTime) {

		generalAcc	= _generalAcc;
		lastCreditTime	= _lastCreditTime;

	}


	// Print number to provided output stream
	std::ostream& AccountInfo::print(std::ostream &_os) const {

		_os	<< "General account: "		\
			<< generalAcc			\
			<< " (last credit added "	\
			<< lastCreditTime.count()	\
			<< ")";

		return _os;

	}


	// Non-member non-friend ostream operator
	std::ostream& operator<<(std::ostream &_os, const AccountInfo &_accountInfo) {

		return _accountInfo.print(_os);

	}


}

