/*TODO: Provide the implementation for the Stack class in this file*/

template<class T>
Stack<T>::Stack()
{
	queue = new Queue<T>();
}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
	queue = other.queue;
}


template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	queue = other.queue;
}

template<class T>
Stack<T>::~Stack()
{
	delete queue;	
	queue = 0;
}

template<class T>
void Stack<T>::push(const T& el)
{
	queue->enqueue(el);
}

template<class T>
T Stack<T>::pop()
{
	if (queue.isEmpty())
		throw new MyException("Error: Stack is empty.");	
}


template<class T>
bool Stack<T>::isEmpty()
{
	return queue->isEmpty();
}

template<class T>
T Stack<T>::peek()
{
	if (queue.isEmpty())
		throw new MyException("Error: Stack is empty.");
}

template<class T>
ostream& operator<<(ostream& os,Stack<T>& stack)
{
	os << stack.queue;
	return os;	
}



