#include <iostream>

#include "MobileNumber.hpp"
#include "Currency.hpp"
#include "CallInfo.hpp"


int main (int argc, char* argv[]) {

	billing::MobileNumber	mobileNumber(50, 841672);

	std::cout << mobileNumber << std::endl;

	billing::Currency	dollar(40, 53);

	std::cout << dollar << std::endl;

	billing::CallInfo	info(mobileNumber, std::chrono::seconds(2400), std::chrono::seconds(8760));

	std::cout << info << std::endl;

	return 0;

}

