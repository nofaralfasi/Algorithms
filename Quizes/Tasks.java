package fun;

import java.util.Scanner;

public class Tasks {

	public static void main(String[] args) {
		int choice;
		final int STARS = 1;
		final int POWER = 2;
		final int FACTORIAL = 3;
		final int FIB = 4;
		final int SIN = 5;
		final int EXIT = 0;
	
		choice = menu();
		while(choice!=EXIT){
			switch(choice){
			case STARS:
				System.out.println("not ready yet");
//				printStars();
				break;
			case POWER:
				computePower();
				break;
			case FACTORIAL:
			computeFactorial();
				break;
			case FIB:
			computeFib();
				break;
			case SIN:
				computeApproximation();
				break;
				default:
					System.out.println("Wrong choice");
			} // switch
			
			choice = menu();
		}// while
	}// main
	
	public static int menu(){
		int choice;
		Scanner s = new Scanner(System.in);
		
		System.out.println("To run stars enter 1");
		System.out.println("To run power enter 2");
		System.out.println("To run factorial enter 3");
		System.out.println("To run Fibbonazzi enter 4");
		System.out.println("To run sin approximation enter 5");
		System.out.println("To exit enter 0");
		System.out.print("What is your choice: ");
	
		choice = s.nextInt();		
		
		return choice;
	}
	
	public static void computePower() {
		Scanner s = new Scanner(System.in);
		int exp;
		float base;
		float result;
		
		System.out.print("Enter base and exponent: ");
		base = s.nextFloat();
		exp = s.nextInt();
		
		result = power(base,exp);
		System.out.printf("%.2f ^ %d = %.2f\n",base,exp,result);
	}
	
	public static float power(float base, int exp) {
		int count;
		float result;
		
		for(count = 1,result=1;count<=exp;count++)
			result*=base;
		
		return result;
	}
	
	public static void computeFactorial() {
		Scanner s = new Scanner(System.in);
		int n;
		System.out.print("Enter n: ");
		n=s.nextInt();
		System.out.printf("%d! = %d\n",n,factorial(n)); 
	}
	public static int factorial(int n) {
		int count,result;
		
		for(count=1,result=1;count<=n;count++)
			result*=count;
		
		return result;		
	}
	public static void computeApproximation() {
		Scanner s = new Scanner(System.in);
		double x;
		
		System.out.print("Enter x (in degrees): ");
		x = s.nextDouble();
		System.out.printf("approximated sin(%.2f) = %f\n",x,(double)sinApprox(x*Math.PI/180.0));
		System.out.println("The standard sin is: "+Math.sin(x*Math.PI/180.0));
	
	}
	
	public static double sinApprox(double x) {
		double result = 0,next_element = x;
		final double delta = 0.0001;
		int counter = 1;
		
		while(next_element>delta){
			if(counter%2==1) result+=next_element;
			else 	result -= next_element;
			
			counter++;
			next_element = power((float)x,counter*2-1)/factorial(counter*2-1);
		}
					
	//	result = x-power((float)x,3)/factorial(3)+power((float)x,5)/factorial(5)-
	//			power((float)x,7)/factorial(7)+power((float)x,9)/factorial(9);
		
		return result;
	}
	public static void computeFib() {
		Scanner s = new Scanner(System.in);
		int n;
		System.out.print("Enter n: ");
		n = s.nextInt();
		
		System.out.printf("The %d-th Fibonazzi is %d\n",n,fib(n));		
	}
	public static int fib(int n) {
		int curr, prev, next,counter;
		
		for(prev = 1,curr=1,counter=3;counter<=n;counter++){
			next = prev+curr;
			prev = curr;
			curr = next;
		}
		
		return curr;
	}

}
