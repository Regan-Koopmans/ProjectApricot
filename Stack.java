public class Stack<T extends Comparable<? super T>>
{
	public void print()
	{
		queue.print();
	}
	
	public Stack()
	{
		queue = new Queue<T>();
	}

	public Stack(Stack<T> other)
	{
		queue = other.queue.clone();
	}
	
	public void push(T el)
	{

		Queue<T> tempQueue = new Queue<T>();
		
		tempQueue.enqueue(el);

		while(!queue.isEmpty())
			tempQueue.enqueue(queue.dequeue());

		while (!tempQueue.isEmpty())
			queue.enqueue(tempQueue.dequeue());
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

	public Stack<T> clone()
	{
		Stack<T> cloneStack = new Stack<T>();
		cloneStack.queue = queue.clone();
		return cloneStack;
	}

	public boolean isEmpty()
	{ 
		if (queue == null)
			return true;
		else
			return queue.isEmpty(); 
	}
	
	private Queue<T> queue;
}
