#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "MyException.h"

using namespace std;

template<class T>
class Queue;

template<class T>
ostream& operator<<(ostream&,Queue<T>&);

template<class T>
class Queue
{
	public:
		/*The overloaded stream operator for the Queue class.  If
		a Object object is printed and contains the elements 1,2,3 and 8, where 1 is at the front of the queue and 8 at the back, the output MUST be in the following format:
		[1,2,3,8]
		There are no spaces in the string.  
		
		NOTE: You will have to replace this operator with an appropriate equivalent in your Java code.*/
		friend ostream& operator<< <T>(ostream&,Queue<T>&);
		
		/*The default constructor*/
		Queue();
		
		/*The copy constructor*/
		Queue(const Queue<T>& other);
		
		/*The overloaded assignment operator.  You will have to replace this operator with an appropriate equivalent in your Java code*/
		Queue<T>& operator=(const Queue<T>& other);
		
		/*The destructor*/
		~Queue();
		
		/*This function adds the element passed as a parameter to the back of the queue*/
		void enqueue(const T& el);
		
		/*This function removes the first element from the queue and returns it
		
		The function should throw an object of MyException, initialized with a descriptive reason, if the structure is empty*/
		T dequeue();
		
		/*It is possible in a queue structure to request that the priority of an element in the queue should be increased.  When an element's priority is increased, it is simply swapped with its predecessor in the queue.  This function receives as a parameter the element of which the priority should be increased.  Given the queue [5,6,7,8,9], after a call to the increasePriority, function with the parameter 8, the queue becomes [5,6,8,7,9]
		
		You may assume that any T will have the equals operator "==" overloaded, but you cannot make assumptions about the assignment operator or the copy constructor for T.  If the element passed as a parameter is not in the queue, the queue remains unchanged.
		
		NOTE: For your Java implementation, you cannot make use of the equals operator for T.  You will have to find a suitable replacement to test the equality of two T objects*/
		void increasePriority(const T& el);
		
		/*This function must return true if the queue is empty and false otherwise*/
		bool isEmpty();
	
	private:
		/*The node class.*/
		class Node
		{
			public:
				Node(const T& data, Node* n = 0)
				{
					element = data;
					next = n;
				}
				
				T element;
				Node* next;
		};
		
		/*The head of the queue*/
		Node* head;
	
};

#include "Queue.C"
			 
#endif
