

template<class T>
List<T>::List()
{
	stack = new Stack<T>();
}

template<class T>
List<T>::List(const List<T>& other)
{
	stack->operator=(other);
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other)
{
	stack->operator=(other.stack);
	return *this;
}

template<class T>
List<T>::~List()
{
	delete stack;
	stack = 0;
}

template<class T>
void List<T>::addToFront(const T& el)
{
	stack->push(el);	
}

template<class T>
void List<T>::addToBack(const T& el)
{
	Stack<T> tempStack;
	while (!stack->isEmpty())
		tempStack.push(stack->pop());

	tempStack.push(el);
	while (!tempStack.isEmpty())
		stack->push(tempStack.pop());

}

template<class T>
void List<T>::insertAtIndex(const int& index, const T& el)
{
	if (index == 0)
	{
		stack->push(el);
		return;
	}
	
	Stack<T> tempStack;
	int counter = 0;

	while (!stack->isEmpty() && counter != index)
	{
		tempStack.push(stack->pop());	
		++counter;
	}
	if (stack->isEmpty() && counter != index)
	{	
		delete stack;
		throw new MyException("Error: Insert index out of bounds.");
	}
	tempStack.push(el);
	while ( !tempStack.isEmpty() )
	{
		stack->push(tempStack.pop());
	}
}

template<class T>
T List<T>::deleteAtIndex(const int& index)
{
	if (index == 0)
	{
		return stack->pop();
	}

	Stack<T> tempStack;
	T temp;	
	int counter = -1;
	while (!stack->isEmpty() && counter != index)
	{
		tempStack.push(stack->pop());	
		++counter;			
	}
	if (stack->isEmpty() && counter != index)
	{	
		delete stack;
		throw new MyException("Error: Delete index out of bounds.");
	}
	temp = tempStack.peek();
	tempStack.pop();
	while ( !tempStack.isEmpty() )
	{
		stack->push(tempStack.pop());
	}
	return temp;
}


template<class T>
T List<T>::get(const int& index)
{
	Stack<T> tempStack;
	T temp;	
	int counter = -1;
	while (!stack->isEmpty() && counter != index)
	{
		tempStack.push(stack->pop());	
		++counter;			
	}
	if (stack->isEmpty() && counter != index)
	{	
		delete stack;
		throw new MyException("Error: Index out of bounds.");
	}
	temp = tempStack.peek();
	while ( !tempStack.isEmpty() )
	{
		stack->push(tempStack.pop());
	}
	return temp;
}

template<class T>
void List<T>::set(const int& index, const T& el)
{
	if (!stack || stack->isEmpty()) throw new MyException("Error: Set index out of bounds.");

	if (index == 0)
	{
	 	stack->pop();
		stack->push(el);
	}

	Stack<T> tempStack;

	int counter = -1;
	while (!stack->isEmpty() && counter+1 != index)
	{
		tempStack.push(stack->pop());	
		++counter;			
	}
	if (stack->isEmpty() && counter+1 != index)
	{	
		delete stack;
		throw new MyException("Error: Set index out of bounds.");
	}
	stack->pop();
	stack->push(el);
	while ( !tempStack.isEmpty() )
	{
		stack->push(tempStack.pop());
	}

}

template<class T>
bool List<T>::isEmpty()
{
	return stack->isEmpty();
}

template<class T>
ostream& operator<<(ostream& os,List<T>& list)
{
	os << *(list.stack);
	return os;	
}

