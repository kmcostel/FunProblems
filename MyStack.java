/*
 * Author: Kevin Costello
 * Date: 9/24/2016
 */


public class MyStack<E> {
	// Initial size of the stack
	private static final int INIT_SIZE = 50;
	// Underlying data structure
	private E[] myArray;
	// Current size of the stack
	private int currSize;
	private Integer[] myInts;

	public MyStack<E>() {
		currSize = 0;
		myArray = E[INIT_SIZE];
	}

	public E pop(E element) {
		if (currSize == 0) {
			throw new NoSuchElementException();
		}
		return false;
	}
	public E push(E element) {
		return null;
	}
	public E peek() {
		if (currSize == 0) {
			// Nothing on stack
			return null;
		}
		else {
			return myArray[currSize - 1];
		}
	}
}
