public class GenericSort
{  public static void main(String[] args)                  
  { Integer[] intArray={new Integer(2), new Integer(4), 
    		new Integer(3)};
    Double[] doubleArray={new Double(3.4), new Double(1.3), 
    		new Double(-22.1)};
    Character[] charArray = {new Character('a'), new Character('J'), 
    		new Character('r')};
    String[] stringArray = {"Tom", "John", "Fred"};
    sort(intArray);
    sort(doubleArray);
    sort(charArray);
    sort(stringArray);
    System.out.print("Sorted Integer objects: ");
    printList(intArray);
    System.out.print("Sorted Double objects: ");
    printList(doubleArray);
    System.out.print("Sorted Character objects: ");
    printList(charArray);
    System.out.print("Sorted String objects: ");
    printList(stringArray);             
  }
  /** Sort an array of comparable objects */
  //public static void sort(Comparable[] list) {
  public static void sort(Comparable[] list)
  { Comparable currentMin;
    int currentMinIndex;
    for (int i = 0; i < list.length - 1; i++)           {
      // Find the maximum in the list[0..i]
      currentMin = list[i];
      currentMinIndex = i;
      for (int j = i + 1; j < list.length; j++) {
        if ((currentMin).compareTo(list[j]) > 0)  {
          currentMin = list[j];
          currentMinIndex = j;                    }
                                                }
      //Swap list[i] with list[currentMinIndex]if necessary;
      if (currentMinIndex != i) {
        list[currentMinIndex] = list[i];
        list[i] = currentMin;   }
                                                        }
  }
  /** Print an array of objects */
  public static void printList(Comparable[] list) {
    for (int i = 0; i < list.length; i++)
    	 System.out.print(list[i] + " ");
    System.out.println();                         }
}
// you can use also Object types:
//  public static void sort(Object[] list)                   {	  
//    Object currentMin;
//    int currentMinIndex;
//    for (int i = 0; i < list.length - 1; i++)        {
      // Find the maximum in the list[0..i]
//      currentMin = list[i];
//      currentMinIndex = i;
//      for (int j = i + 1; j < list.length; j++) {
//        if (((Comparable)currentMin).compareTo(((Comparable)list[j])) > 0) {
//          currentMin = list[j];
//          currentMinIndex = j;                                             }
//                                                }
      //Swap list[i] with list[currentMinIndex]if necessary;
//      if (currentMinIndex != i) {
//        list[currentMinIndex] = list[i];
//        list[i] = currentMin;   }
//                                                      }
//                                                            }
  /** Print an array of objects */
//  public static void printList(Object[] list) {
//    for (int i = 0; i < list.length; i++)
//      System.out.print(list[i] + " ");
//    System.out.println();                     }
 
