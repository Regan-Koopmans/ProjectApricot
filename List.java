public class List<T extends Comparable<? super T>> 
{
	private Stack<T> stack;

	public void print() { stack.print(); }

	public List()
	{
		stack = new Stack<T>();
	}

	public List(List<T> other)
	{
		stack = other.stack.clone();
	}

	public List<T> clone()
	{
		List<T> temp = new List<T>();
		temp.stack = stack.clone();
		return temp;	
	}

	public void addToFront(T el) { stack.push(el); }

	public void addToBack(T el)
	{
		Stack<T> tempStack = new Stack<T>();
		
		while(!stack.isEmpty())
			tempStack.push(stack.pop());

		tempStack.push(el);

		while (!tempStack.isEmpty())
			stack.push(tempStack.pop());
	}

	public void insertAtIndex(int index, T el)
	{
		if (index == 0)
		{
			stack.push(el);
			return;
		}
		
		Stack<T> tempStack = new Stack<T>();
		int counter = -1;

		while (!stack.isEmpty() && counter != index)
		{
			tempStack.push(stack.pop());
			++counter;
		}
		if (stack.isEmpty() && counter != index)
			throw new NullPointerException();

		tempStack.push(el);
		while ( !tempStack.isEmpty() )
		{
			stack.push(tempStack.pop());
		}
	}

	public T deleteAtIndex(int index)
	{
		if (index == 0)
		{
			return stack.pop();
		}
		Stack<T> tempStack = new Stack<T>();
		T temp;
		int counter = -1;
		while (!stack.isEmpty() && counter != index)
		{
			tempStack.push(stack.pop());
			++counter;
		}
		if (stack.isEmpty() && counter != index)
			throw new NullPointerException();

		temp = tempStack.peek();
		tempStack.pop();
		while ( !tempStack.isEmpty() )
			stack.push(tempStack.pop());
		
		return temp;
	}
	
	public T get(int index)
	{
		if (index == 0)	
		{
			T temp = stack.pop();
			stack.push(temp);
			return temp;
		}

		Stack<T> tempStack = new Stack<T>();
		T temp = null;
		int counter = -1;
		while (!stack.isEmpty() && counter+1 != index)
		{
			tempStack.push(stack.pop());
			++counter;
		}
		temp = stack.pop(); 
		stack.push(temp);
		while (!tempStack.isEmpty())
		{
			stack.push(tempStack.pop());
		}
		return temp;
	}

	public void set(int index, T el)
	{
		if (stack == null) throw new NullPointerException();
		
		if (index == 0)
		{
			stack.pop();
			stack.push(el);
		}

		Stack<T> tempStack = new Stack<T>();
		
		int counter = -1;
		while (!stack.isEmpty() && counter+1 != index)
		{
			tempStack.push(stack.pop());
			++counter;
		}
		if (stack.isEmpty() && counter+1 != index)
			return;
		

		stack.pop();
		
		stack.push(el);
		while ( !tempStack.isEmpty() )
		{
			stack.push(tempStack.pop());
		}
	}
	public boolean isEmpty() { return stack.isEmpty(); } 
}
