public class Tester
{
	public static void main(String [] args)
	{
		List<Integer> myQueue = new List<Integer>();
		myQueue.addToFront(new Integer(5));
		myQueue.addToFront(new Integer(6));
		myQueue.addToFront(new Integer(7));
		myQueue.set(1,2);
		myQueue.addToBack(new Integer(9));
		myQueue.print();
	}	

}