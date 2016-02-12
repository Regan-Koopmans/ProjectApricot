public class Tester
{
	public static void main(String [] args)
	{
		List<Integer> myQueue = new List<Integer>();
		myQueue.insertAtIndex(0,new Integer(5));
		myQueue.insertAtIndex(1, new Integer(6));
		myQueue.addToFront(new Integer(6));
		myQueue.addToFront(new Integer(7));
		myQueue.addToBack(new Integer(9));
		List<Integer> myQueue2 = new List<Integer>(myQueue);
		myQueue.set(3,2);
		myQueue.print();
	}	

}
