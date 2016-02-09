public class Queue<T>
{	
	public Queue()
	{
		head = null;
	}

	public Queue(Queue<T> other)
	{
		Node nodePointer = other.head;
		while (nodePointer)
		{
			enqueue(nodePointer.element);
			nodePointer = nodePointer.next;
		}
	}
	
	public void clone(Queue<T> other)
	{
		
	}

	public void enqueue(T el)
	{
		if (head == null)
		{
			head = new Node(el);
			return;
		}
		
		Node nodePointer = head;
		while (nodePointer.next != null)
		{	
			nodePointer = nodePointer.next;
		}
	}

	public T dequeue()
	{
		if (head == null)
				//throw some exception
			
		Node * tempNode = head;
		T temp = tempNode.element;
		
		head = head.next;
		
		return temp;
	}

	bool isEmpty()	{ return (head == null); }

	public T
	void increasePriority(T el)
	{
		if (head == null) return;
		
		if (head.element == el) return;
		
		Node nodePointer = head;
		Node prevPointer = null;

		while (nodePointer.next != null && nodePointer.next.element != el)
		{
			prevPointer = nodePointer;
			nodePointer = nodePointer.next;
		}

		if (nodePointer.next == null) return;
	}

		
	public toString()
	{
		Node nodePointer = head; 
		System.out.print("[");
		while(nodePointer != null)
		{
			
			System.out.print(nodePointer.element);
	
			if (nodePointer.next)
				System.out.print(",");

			nodePointer = nodePoiter.next;

		}
		System.out.print("]");		
	}
	class Node
	{
		public Node(T data, Node n)
		{
			element = data;
			next = n;
		}
		public Node(T data)
		{
			this(data,null);
		}
		T element;
		public Node next;
	}
}
