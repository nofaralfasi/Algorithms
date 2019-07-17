package stars;

import java.util.Scanner;

import javax.swing.text.AbstractDocument.LeafElement;

public class Stars {

	public static void main(String[] args) {
		int height=0,length=0;
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter height and length of stars cube: ");
		height = s.nextInt();
		length = s.nextInt();
		// i is the current line number
		for(int i =1;i<=height;i++){
			// j is the number of current star
			for(int j=1;j<=length;j++){
				System.out.print("*");
			}
			System.out.println();
		}
		
		// draw triangle of stars
		for(int line=1;line<=height;line++){
			for(int stars = 1; stars<=line;stars++){
				System.out.print("*");
			}
			System.out.println();
		}
	
		// draw triangle of stars 
		for(int line=1;line<=height;line++){
			for(int spaces = 1; spaces<= (height-line);spaces++){
				System.out.print(" ");
			}
			for(int stars = 1; stars<=line;stars++){
				System.out.print("*");
			}
			System.out.println();
		}
		// draw pyramid of stars 
		int total_spaces=height-1, total_stars=1;
		for(int lines = 1;lines<=height;lines++){
			// print spaces
			for(int spaces = 1; spaces<=total_spaces; spaces++){
				System.out.print(" ");
			}
			// print stars
			for(int stars = 1; stars<=total_stars; stars++)
				System.out.print("*");
			// update total_spaces and total_stars
			total_spaces--;
			total_stars+=2;
			
			System.out.println();
		}

		
	}

}
