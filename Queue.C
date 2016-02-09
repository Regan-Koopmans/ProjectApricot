template<class T>
Queue<T>::Queue()
{
	head = 0;	
}

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
	Node * nodePointer = other.head;
	while (nodePointer)
	{
	
		enqueue(nodePointer->element);
		nodePointer = nodePointer->next;
	}
		
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	Node * nodePointer = head;
	Node * tempPointer = 0;
	
	while (nodePointer)
	{
		tempPointer = nodePointer;
		nodePointer = nodePointer->next;
		delete tempPointer;
	}
	head = 0;	

	if (!other.head)
	{
		Queue();
		return *this;
	}
	else
	{
		Node * otherPointer = other.head;
		while (otherPointer)
		{
			enqueue(otherPointer->element);
			otherPointer = otherPointer->next;
		}
	}
	
	return *this;
	
}

template<class T>
Queue<T>::~Queue()
{
	Node * nodePointer = head;
	Node * tempPointer = 0;
	while(nodePointer)
	{
		tempPointer = nodePointer;
		nodePointer = nodePointer->next;
		delete tempPointer;
	}
	head = 0;
}

template<class T>
void Queue<T>::enqueue(const T& el)
{
	T term = el;
	if (!head)
	{
		head = new Node(term,0);
		return;	
	}
	
	Node * nodePointer = head;

	while ( nodePointer->next )
	{
		nodePointer = nodePointer->next;
	}
	nodePointer->next = new Node(el,0);
}

template<class T>
T Queue<T>::dequeue()
{	
	if (head == 0)
		throw new MyException("Error: Cannot dequeue on empty structure.");

	Node * tempNode = head;
	T temp = tempNode->element;

	head = head->next;

	delete tempNode;
	return temp;
}

template<class T>
bool Queue<T>::isEmpty()
{
	return (head == 0);		
}

template<class T>
void Queue<T>::increasePriority(const T& el)
{
	if (!head)
		return;
	
	if (head->element == el)
		return;

	Node * nodePointer = head;
	Node * prevPointer = 0;

	while (nodePointer->next != 0 && nodePointer->next->element != el)
	{
		prevPointer = nodePointer;
		nodePointer = nodePointer->next;
	}

	if (nodePointer->next == 0)
		return;

	Node * tempNode = nodePointer->next->next;
	if (prevPointer)
	{
		prevPointer->next = nodePointer->next;
		prevPointer->next->next = nodePointer;
		nodePointer->next = tempNode;
	}
	else
	{
		if (tempNode)
		{
			Node * tempNodeExtra = nodePointer->next;
			tempNodeExtra->next = head;
			head->next = tempNode;
			head = tempNodeExtra;
	
		}
		else
		{
			Node * tempNodeExtra = nodePointer->next;
			tempNodeExtra->next = head;
			head->next = 0;
			head = tempNodeExtra;
		}	
	}
}

template<class T>
ostream& operator<<(ostream& os,Queue<T>& queue)
{
	typename Queue<T>::Node* nodePointer = 0;
	nodePointer = queue.head;
	os << "[";
	while (nodePointer)
	{
		os << nodePointer->element;
		if (nodePointer->next != 0)
			os << ",";

		nodePointer = nodePointer->next;
	}
	os << "]\n";
	return os;
}
