#include "Currency.hpp"
#include "CallInfo.hpp"
#include "FeeChain.hpp"


namespace billing {


	// D-tor
	FeeChainItem::~FeeChainItem() {

		feeList = nullptr;

	}


	// Add fee calculator
	void FeeChainItem::addFee(FeeChainItem* _newItem) {

		if (feeList) {

			feeList->addFee(_newItem);

		} else {

			feeList = _newItem;

		}

	}


	// Fee calculation method
	void FeeChainItem::calcFee(CallInfo* _info) {

		feeList->calcFee(_info);

	}


// ================================================================


	// D-tor
	FeeFixed::~FeeFixed() {

		fixedFeeValue = Currency(0);

	}


	// Fee calculation method
	void FeeFixed::calcFee(CallInfo* _info) {

		// Add fixed fee
		_info->setFee(_info->getFee() + fixedFeeValue);
		// Move responsibility to next item in chain
		FeeChainItem::calcFee(_info);

	}


// ================================================================


}

