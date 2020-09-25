 
public class CrystalBallRiddle {
    int breakingPoint = 99;
    int countDrops = 0;
    
     public boolean drop(int floor) {
          countDrops++;
          return floor >= breakingPoint;
  }

     public int findBreakingPoint(int floors) {
          int interval = 14;
          int previousFloor = 0;
          int crystal1 = interval;

          //Drop crystal1 at decreasing intervals
          while (!drop(crystal1) && crystal1 <=floors) {
              interval-=1;
              previousFloor = crystal1;
              crystal1 += interval;
          }

          //Drop crystal2 at 1 unit increments
          int crystal2 = previousFloor + 1;
          while (crystal2 < crystal1 && crystal2 <= floors && !drops(crystal2)) {
              crystal2 +=1;
          }
          //If didn't break, return -1
          return crystal2 > floors ? -1 : crystal2;
      }
      
     public static void main(String[] args) {
          int result = findBreakingPoint(100);
	        System.out.println(result);
    }
}
