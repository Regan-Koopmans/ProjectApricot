#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "MyException.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Queue<double> myQueue = Queue<double>();
	Queue<double> testQueue;
	myQueue.enqueue(5);
	myQueue.enqueue(6);
	testQueue = myQueue;
	myQueue.enqueue(7);
	cout << testQueue;
	cout << myQueue.dequeue() << endl;
	myQueue.isEmpty();
	
}
