#pragma	once
#ifndef	BILLING_FEE_CHAIN_HPP
#define	BILLING_FEE_CHAIN_HPP


// Main app namespace
namespace billing {


	// Forward declaration
	class CallInfo;


	// Fee chain of responsibility pattern item
	class FeeChainItem {

		FeeChainItem*	feeList;


	public:

		// C-tor
		FeeChainItem() : feeList(nullptr) {};
		// D-tor
		virtual ~FeeChainItem();

		// Add fee calculator
		void addFee(FeeChainItem* _newItem);

		// Fee calculation method
		virtual void calcFee(CallInfo* _info);


	};


// ================================================================


	// Fixed fee
	class FeeFixed : public FeeChainItem {

		Currency	fixedFeeValue;		// Value for fixed fee calculation


	public:

		// C-tor
		FeeFixed() : fixedFeeValue(0) {};
		// D-tor
		~FeeFixed();

		// Set fee
		explicit FeeFixed(const Currency &_newFixedFee) : fixedFeeValue(_newFixedFee) {};

		// Set value of fixed fee
		inline void setFee(const Currency &_fixedFeeValue) {

			fixedFeeValue = _fixedFeeValue;

		}

		// Get value of fixed fee
		inline Currency getFee() const {

			return fixedFeeValue;

		}

		// Fee calculation method
		void calcFee(CallInfo* info);


	};


// ================================================================


	// Home network fee
	class FeeHomeNetwork : public FeeChainItem {

	public:

		// Fee calculation method
		void calcFee(CallInfo* info);


	};


// ================================================================


	// Non-home network fee
	class FeeNonHomeNetwork : public FeeChainItem {

	public:

		// Fee calculation method
		void calcFee(CallInfo* info);


	};


}	// namespace billing


#endif	// BILLING_FEE_CHAIN_HPP

