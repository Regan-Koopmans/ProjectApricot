#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "MyException.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	List<int> myList;
	myList.addToBack(4);
	myList.addToFront(5);
	myList.addToBack(6);
	myList.insertAtIndex(1,19);
	myList.set(1,2);
	myList.set(0,3);
	myList.set(2,10);
	myList.set(3,11);
	cout << myList.get(3) << endl;
	cout << myList;
}
