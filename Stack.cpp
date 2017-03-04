//===============================================
//! @file Stack.cpp.
//===============================================

//===============================================
//! @brief Source code stack library.
//===============================================
#include "Stack.h"

//-----------------------------------------------
static const int POISON_INIT    = 100500; //! Initialization const.
static const double POISON_DEST = NAN;    //! Destruct const.
//-----------------------------------------------


Stack::Stack() :
	count_(0), 
	data_()
	{
		std::cout << INFO << "\n\n";
	}

//-----------------------------------------------

/*Stack::Stack(size_t capasity) :
	data_(new value_type[capasity]),
	count_(0),
	size_(size)
	{}
*/	

Stack::~Stack()
	{
	count_ = POISON_DEST;
	for (size_t i = 0; i < capasity_; i++)
		data_[i] = POISON_DEST;
	}

//-----------------------------------------------

bool Stack::push(value_type value)
{
	ASSERT_OK(); //! Entry verification

	if (count_ >= capasity_)
	{
		ASSERT_OK(); //! Exit verification
		return false;
	}
	data_[count_++] = value;

	ASSERT_OK(); //! Exit verification
	return true;
}

//-----------------------------------------------

Stack::value_type Stack::pop()
{
	ASSERT_OK(); //! Entry verification
	if (count_ == 0)
	{
		ASSERT_OK();
		return NAN; // Exit verification 
	}
	value_type result = data_[--count_];

	ASSERT_OK(); //! Exit verification
	return result;
}

//-----------------------------------------------

size_t Stack::capasity() const
{
	ASSERT_OK(); //! Verification
	return capasity_;
}

//-----------------------------------------------

bool Stack::ok() const
{
	return (count_ <= capasity_ || data_ != NULL);
}



void Stack::dump() const

{

	//-----------------------------------------------
	static const bool TRUE = 1;
	static const bool FALSE = 0;

#define DUMPTRUE()															\
	if (data_[i] != data_[i])												\
	{																		\
		data_correct = FALSE;												\
		log << "*[" << i << "] = " << data_[i] << "\t (Correct?)\n";		\
	}													     				\
	else if (data_[i] == POISON_INIT)										\
	{																		\
		poison = FALSE;														\
		log << "*[" << i << "] = " << data_[i] << "\t (Poison?)\n";			\
	}																		\
	else																	\
	log << "*[" << i << "] = " << data_[i] << '\n';

	//-----------------------------------------------

#define DUMPFALSE() 														\
	if (data_[i] != data_[i])												\
		log << " [" << i << "] = " << data_[i] << "\t (Correct?)\n";		\
	else if (data_[i] == POISON_INIT)										\
		log << " [" << i << "] = " << data_[i] << "\t (POISON?)\n";			\
	else																	\
		log << " [" << i << "] = " << data_[i] << '\n';

	//-----------------------------------------------

	bool data_correct = TRUE, poison = TRUE;
	bool count_correct = TRUE;
//	int data_correct = 1, poison = 1;
//	int count_correct = 1;


	std::ofstream log;  //! Write in log.txt
	log.open("log.txt", std::ios_base::app); //! Open file for addition info.
	
	log << "--------------------------------------------------\n\n";
	log	<< "Info about stack." << '\n' << '\n';
	log << "Stack max size = " << capasity_ << '\n';
	log << "Amount of elements in the stack = " << count_ << '\t';
	if	(count_ <= capasity_) 
	{	//! Start first block.
		log << "\n\n";
		for (size_t i = 0; i < count_; i++) // Write data from the stack memory.
		{	// Start first for .
			DUMPTRUE();

		} //! End first for.

		for (size_t i = count_; i < capasity_; i++) // Write data from the memory off the stack.
		{ // Start second for.
			DUMPFALSE();
		} //! End second for.
	} //! End of first block.
	else 
	{   //! Second block.
		count_correct = FALSE;
		log << "Correct???\n\n";
		for (size_t i = 0; i < capasity_; i++) // Write data from the memory off the stack.
		{ // Start for.
			DUMPFALSE();
		} // End for. 
	} // End if.
	if (count_correct == TRUE || data_correct == TRUE || poison == TRUE)
		log << "Stack is OK\n";
	else 
		log << "Stack is NOT OK\n";

	log << "--------------------------------------------------\n\n";

	log.close();

}

//-----------------------------------------------