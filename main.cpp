#include <iostream>

#include "MobileNumber.hpp"
#include "Currency.hpp"
#include "CallInfo.hpp"


int main (int argc, char* argv[]) {

	billing::CallInfo	call0(billing::MobileNumber(63, 1234206), std::chrono::seconds(0), std::chrono::seconds(3601));

	std::cout << call0 << std::endl;

	return 0;

}

