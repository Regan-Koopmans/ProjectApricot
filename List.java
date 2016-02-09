public class List
{
	public void print()
	{
		stack.print();
	}

	public List()
	{
		
	}

	public List(List<T> other)
	{
		
	}

	public List<T> clone()
	{
		
	}

	public void addToFront(T el)
	{
		stack.push(el);
	}

	public void addToBack(T el)
	{
		Stack<T> tempStack = new Stack<T>();
		while(!stack.isEmpty())
			tempStack.push(stack.pop());

		tempStack.push(el);
		while (!stack.isEmpty())
			stack.push(tempStack.pop());
	}

	public void insertAtIndex(int index, T el)
	{
		
	}

	public T deleteAtIndex(int index)
	{
		
	}
	
	public T get(int index)
	{
		Stack<T> tempStack = new Stack<T>();
		T temp = null;
		int counter = -1;
		while (!stack.isEmpty() && counter != index)
		{
			tempStack.push(stack.pop());
			++counter;
		}
	}

	public T set(int index, T el)
	{
		
	}

	public bool isEmpty() { return stack.isEmpty(); } 

	private Stack<T> stack;
}
