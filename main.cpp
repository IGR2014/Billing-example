#include <iostream>
#include <chrono>

#include "MobileNumber.hpp"
#include "Currency.hpp"
#include "CallInfo.hpp"


int main (int argc, char* argv[]) {

	billing::CallInfo	call[40];
	
	for (auto &i : call) {
	
		i = billing::CallInfo(billing::MobileNumber(63, 1234206), std::chrono::system_clock::now(), std::chrono::system_clock::now());
		std::cout << i << std::endl;

	}

	return 0;

}

