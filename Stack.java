public class Stack<T>
{
	public void print()
	{
		queue.print();
	}
	
	public Stack()
	{
		queue = null;
	}

	public Stack(Stack<T> other)
	{
		//queue = other.copy();
	}
	
	public void push(T el)
	{
		Queue<T> tempQueue = new Queue<T>();
		tempQueue.enqueue(el);
		while(!queue.isEmpty())
			tempQueue.enqueue(queue.dequeue());
	}
	
	public T pop()
	{
		if (queue.isEmpty())
			throw new NullPointerException();
	 
		return queue.dequeue();	
	}

	public T peek() 
	{
		if (queue.isEmpty())
			throw new NullPointerException();

		T temp = pop();
		push(temp);	
		return temp;
	}

	public Stack clone()
	{
	}

	public boolean isEmpty(){ return queue.isEmpty(); }
	
	private Queue<T> queue;
}
