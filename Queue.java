public class Queue<T>
{	
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
		public T element;
		public Node next;
	}
	public Node head;

	public Queue()
	{
		head = null;
	}

	public Queue(Queue<T> other)
	{
		if (other.head == null)
			head = null;

		Node nodePointer = other.head;
		while (nodePointer != null)
		{
			enqueue(nodePointer.element);
			nodePointer = nodePointer.next;
		}
	}
	
	public Queue<T> Queue(Queue<T> other)
	{
		if (other.head == null) return new Queue<T>();

		Node nodePointer = other.head;	

		return this;
	}

	public Queue<T> clone()
	{
		Queue<T> cloneQueue = new Queue<T>();
		if (head == null) return cloneQueue;

		Node nodePointer = head;	

		while (nodePointer != null)
		{
			cloneQueue.enqueue(nodePointer.element);
			nodePointer = nodePointer.next;
		}
		return cloneQueue;
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
		nodePointer.next = new Node(el);
	}

	public T dequeue()
	{
		if (head == null)
			throw new NullPointerException();
			
		Node tempNode = head;
		T temp = tempNode.element;
		
		head = head.next;
		
		return temp;
	}

	public boolean isEmpty()	{ return (head == null); }

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

	public void print()
	{
		Node nodePointer = head; 
		System.out.print("[");
		while(nodePointer != null)
		{
			
			System.out.print(nodePointer.element);
	
			if (nodePointer.next != null)
				System.out.print(",");

			nodePointer = nodePointer.next;

		}
		System.out.print("]\n");		
	}
	
}
