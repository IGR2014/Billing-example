#include <iostream>
#include <chrono>

#include "AccountInfo.hpp"
#include "CallInfo.hpp"
#include "FeeChain.hpp"


int main (int argc, char* argv[]) {

	billing::AccountInfo	user(billing::Currency(40, 5), std::chrono::system_clock::now());
	billing::CallInfo	call[40];
	billing::FeeChainItem	feeCalculator;
	billing::FeeFixed	fixedFeeCalculator(billing::Currency(0, 33));

	feeCalculator.addFee(&fixedFeeCalculator);

	std::cout << user << std::endl;
	std::cout << std::endl;

	for (auto &i : call) {

		i = billing::CallInfo(billing::MobileNumber(98, 8866378), std::chrono::system_clock::now(), std::chrono::system_clock::now());
		std::cout << i << std::endl;

		feeCalculator.calcFee(&i);

		std::cout << "\tCalculated fee: " << i.getFee() << std::endl;
		std::cout << std::endl;

	}

	return 0;

}

