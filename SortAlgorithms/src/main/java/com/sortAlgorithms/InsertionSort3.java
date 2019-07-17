
public class InsertionSort {

	public static void main(String[] args) {
		final int SIZE = 40;
		int [] a = new int [SIZE];
		
		readRndArray(a);
		
		System.out.println("Original Array:");
		printArray(a);
		
		insertionSort(a);
		
		System.out.println("Sorted Array:");
		printArray(a);
	}
	
	// sets random array
	public static void readRndArray(int [] a) {
		
		for(int i = 0; i<a.length;i++)
			a[i] = (int)( Math.random()*101); // random values from 0 to 100
	}
	
	public static void printArray(int [] a) {
		for(int i = 0;i<a.length;i++)
			System.out.print(" "+a[i]);
		System.out.println("");
	}// printArray
	
	public static void insertionSort(int [] a)	{
		int iteration,place;
		
		for(iteration=1;iteration<a.length;iteration++){ // counts iterations
			place = findPlace(a,iteration);
			if(place!=iteration)// if the element a[iteration] is not maximum in a[0]..a[iteration]
				insert(a,place,iteration);
		}
	}
	
	// all the elements from a[0] to a[index] (maybe except a[index]) are sorted
	// findPlace finds the right place for a[index] so that  all the elements from a[0] to a[index]
	// will be sorted
	public static int findPlace(int [] a, int index) {
		boolean found = false;
		int place = index;// in case that a[index] is maximum between a[0] ... a[index]
		
		for(int i=0;i<index && !found;i++)
			if(a[i]>a[index]){
				found = true;
				place = i;
			}
		
		return place;
	}
	
	public static void insert(int []a, int right_place, int from_place ) {
		int tmp,i;
		
		tmp = a[from_place];
		for(i=from_place;i>right_place;i--)
			a[i] = a[i-1];
		
		a[right_place] = tmp;
	}


}
