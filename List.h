#ifndef LIST_H
#define LIST_H

#include "Stack.h"
#include "MyException.h"

template<class T>
class List;

template<class T>
ostream& operator<<(ostream&,List<T>&);

template<class T>
class List
{
	public:
		/*The overloaded stream operator for the List class.  If
		a List object is printed and contains the elements a,c,b and m, with element 'a' at index 0 and element 'm' at index 3 (first to last), the output MUST be in the following format:
		[a,c,b,m]
		
		There are no spaces in the string.  You will have to replace this operator with an appropriate equivalent in your Java code*/
		friend ostream& operator<< <T>(ostream&,List<T>&);
		
		/*The constructor*/
		List();
		
		/*The copy constructor*/
		List(const List<T>& other);
		
		/*The overloaded assignment operator.  You will have to replace this operator with an appropriate equivalent in your Java code*/
		List<T>& operator=(const List<T>& other);
		
		/*The destructor.*/
		~List();
		
		/*This function adds the element passed as a parameter to the front of the list.  The parameter will become the first element in the list at index 0.*/
		void addToFront(const T& el);
		
		/*This function adds the element passed as a parameter to the back of the list.  The parameter will become the last element in the list.*/
		void addToBack(const T& el);
		
		
		
		/*This function accepts a numerical index and places the element passed as a parameter at this index in the list.  You must check the validity of the index.  If the index is valid, place the parameter element at that index and the the element originally at this index (and all elements following it) shift up by one position to the right.
		
		It is always allowed to insert at index 0, even if the structure is empty.  However, all other invalid indices should cause an instance of MyException to be thrown, initialized with a descriptive message.
		*/
		void insertAtIndex(const int& index, const T& el);
		
		/*This function accepts an index from which an element is to be deleted and subsequently returned.  All elements following the deleted element shift one index to the left to close the hole left by the deleted element in the list
		
		Invalid indices should cause an instance of MyException to be thrown, initialized with a descriptive message.*/
		T deleteAtIndex(const int& index);
		
		
		/*Returns the element at the index specified be the recieved parameter without removing the element from the list
		
		Invalid indices should cause an instance of MyException to be thrown, initialized with a descriptive message.*/
		T get(const int& index);
		
		/*Replaces the element at the index specified be the recieved parameter with the second parameter
		
		Invalid indices should cause an instance of MyException to be thrown, initialized with a descriptive message.*/
		void set(const int& index, const T& el);
		
		/*This function must return true if the list is empty and false otherwise*/
		bool isEmpty();
	
	private:
		/*You must store your elements in this Stack*/
		Stack<T>* stack;
};

#include "List.C"

#endif
