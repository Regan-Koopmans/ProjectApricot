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
	cout << myList;
}
