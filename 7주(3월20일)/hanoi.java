import java.util.Scanner;

public class hanoi {
    static int count=0;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		
		int i= sc.nextInt();
		
		System.out.println(Math.pow(2, i)-1);
		hahanoi(i,1,2,3);
		
		
		
	}
	public static void hahanoi(int num, int from, int by, int to) {
		
		
		if(num==1) {
			System.out.println(from+" "+ to+ "");
		}
		else {
			
			hahanoi(num-1,from,to,by);
			
			System.out.println(from+" "+ to+ "");
			
			hahanoi(num-1,by,from,to);
		}
		
	}
}
