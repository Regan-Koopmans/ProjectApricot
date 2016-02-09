

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
	
}

template<class T>
void List<T>::addToBack(const T& el)
{
	
}

template<class T>
void List<T>::insertAtIndex(const int& index, const T& el)
{
	
}

template<class T>
T List<T>::deleteAtIndex(const int& index)
{
	
}


template<class T>
T List<T>::get(const int& index)
{
	
}

template<class T>
void List<T>::set(const int& index, const T& el)
{
	
}

template<class T>
bool List<T>::isEmpty()
{
	return stack->isEmpty();
}

template<class T>
ostream& operator<<(ostream& os,List<T>& list)
{
	os << *list.stack;
	return os;	
}

