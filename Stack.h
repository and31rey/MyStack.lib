//===============================================
//! @file Stack.h
//===============================================

//===============================================
//! @brief Stack library
//===============================================

#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <assert.h>
#include <fstream>
#include "ServiceLib.h"


class Stack 
{
	public:
	typedef double value_type;  //! Elements type

	//===========================================
	//! @brief Standart constructor for static stack
	//===========================================

	Stack();

	//===========================================
	//! @brief Standart constructor for dynamic stack
	//===========================================

//	Stack(size_t capasity);

//  Stack(size_t capasity);

	~Stack();

	//===========================================
	//! @brief Pushes a value to the stack
	//! @param value is an element to be pushed
	//! @return succes of operation
	//===========================================

	bool push(value_type value);

	//===========================================
	//! @brief Take the last element from the stack 
	//! @return last element in the stack
	//===========================================

	value_type pop();

	//===========================================
	//! @brief Maximum number of elements to be pushed 
	//! @return stack capasity
	//===========================================

	size_t capasity() const;

	//===========================================
	//! Show the last element of the stac
	//! @return last element of stack
	//===========================================

//	value_type peek(); //TODO

	//===========================================
	//! @brief Information about stack
	//! @detailed Send all info about stack in logfile.	
	//===========================================

	void dump() const;


	private:
	
	//===========================================
	//! Silent validation
	//! @return success to validation
	//===========================================

	bool ok() const;

	//===========================================
	//! @brief Information about stack
	//! @detailed Send all info about stack in logfile.
	//===========================================

//	void dump() const;

	//===========================================
    //! variables
	//===========================================

	static const size_t capasity_ = 6; //! maximum number of elements to be pushed 

//	Static stack
	value_type data_[capasity_]; //! data storage
	size_t count_; //! counter


/* Dynamic Stack
	value_type data_; //! Data pointer
	size_t count_;    //! Counter
	size_t size_;     //! Stack capasity
*/

}; //! End of class stack

#endif