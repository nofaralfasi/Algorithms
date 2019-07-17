package average;

import java.util.Scanner;

public class Average {

	public static void main(String[] args) {
		int grade = 0;
		int sum = 0;
		int num_grades = 0;
		int i=0; // is a current grade
		float average=0;
		Scanner s = new Scanner(System.in);
		
		System.out.println("How many grades are there?");
		num_grades = s.nextInt();
		for(i=1,sum =0;i<=num_grades;i++){
			do{
			System.out.println("Enter a grade in range 0..100: ");
			grade = s.nextInt();
			// check if the grade is in range
			}while(grade<0 || grade >100);
			sum+=grade;
		}
		// compute average
		average = (float)sum/num_grades;
		System.out.printf("The average grade is %3.2f\n",average); // place for 3 digits before
		// point and 2 digits after point
	}
}
