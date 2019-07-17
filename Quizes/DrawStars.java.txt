import java.util.Scanner;

public class DrawStars {

	public static void main(String[] args) {
		Scanner s  = new Scanner(System.in);
		int n,k,l;
		
		System.out.println("Enter odd height, horizontal and vertical repeat number: ");
		n= s.nextInt();
		k=s.nextInt();
		l=s.nextInt();
		
		for(int q=1;q<=l;q++){
			drawX(n,k);
	}
	}
	
	public static void drawX(int n, int k) {
		int spaces1 = 0;
		int spaces2 = n-2 ;
		int spaces3 = 0;
		
			
		// top part
		for(int i=1;i<=n/2;i++){
		for(int p=1;p<=k;p++){
			for(int j=1;j<=spaces1;j++)
				System.out.print(" ");
			System.out.print("*");
			for(int j=1;j<=spaces2;j++)
				System.out.print(" ");
			System.out.print("*");
			for(int j=1;j<=spaces3;j++)
				System.out.print(" ");
			
		}
			System.out.println();
			spaces1++;
			spaces2-=2;
			spaces3++;
		}
		// center star
		for(int p=1;p<=k;p++){
		for(int j=1;j<=spaces1;j++)
			System.out.print(" ");
		System.out.print("*");
		for(int j=1;j<=spaces3;j++)
			System.out.print(" ");
		}
		System.out.println();
		spaces1--;
		spaces2+=2;
		spaces3--;

			
		// bottom part
		for(int i=1;i<=n/2;i++){
			for(int p=1;p<=k;p++){
			for(int j=1;j<=spaces1;j++)
				System.out.print(" ");
			System.out.print("*");
			for(int j=1;j<=spaces2;j++)
				System.out.print(" ");
			System.out.print("*");
			for(int j=1;j<=spaces3;j++)
				System.out.print(" ");
			}
			System.out.println();
			spaces1--;
			spaces2+=2;
			spaces3--;
		} // for i

	}

}
