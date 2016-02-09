#ifndef STACK_H
#define STACK_H

#include "Queue.h"
#include "MyException.h"

#include <iostream>

using namespace std;

template<class T>
class Stack;

template<class T>
ostream& operator<<(ostream&,Stack<T>&);

template<class T>
class Stack
{
	public:
		/*The overloaded stream operator for the Stack class.  If
		a Stack object is printed and contains the elements 4,7,3 and 1, where 4 is at the top of the stack, the output MUST be in the following format:
		[4,7,3,1]
		
		There are no spaces in the string.  You will have to replace this operator with an appropriate equivalent in your Java code*/
		friend ostream& operator<< <T>(ostream&,Stack<T>&);
		
		/*The constructor for the Stack class*/
		Stack();
		
		/*The copy constructor*/
		Stack(const Stack<T>& other);
		
		/*The overloaded assignment operator.  You will have to replace this operator with an appropriate equivalent in your Java code*/
		Stack<T>& operator=(const Stack<T>& other);
		
		/*The destructor for the stack class*/
		~Stack();
		
		/*This function adds the element passed as a parameter to the top of the stack*/
		void push(const T& el);
		
		/*This function removes the top element from the stack and returns it
		
		This function should throw an object of MyException, initialized with a descriptive reason, if the structure is empty*/
		T pop();
		
		/*This function returns the top element of the stack without removing it.
		
		This function should throw an object of MyException, initialized with a descriptive reason, if the structure is empty*/
		T peek();
		
		/*This function must return true if the stack is empty and false otherwise*/
		bool isEmpty();

	private:
		/*You must store your elements in this Queue*/
		Queue<T>* queue;
	
};

#include "Stack.C"
			 
#endif