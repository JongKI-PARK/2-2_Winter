import java.util.Scanner;
import java.util.Stack;

public class Stack_bj10828 {
	static Stack<Integer> stack = new Stack<Integer>();
	
	public static void main(String arg[]) {
		Scanner scan = new Scanner(System.in);
		System.out.println("입력할 명령어 갯수를 입력하시오 :");
		int n=scan.nextInt();
		
		int i=0;
		while(i<n) {
			System.out.println("명령어를 입력하시오");
			String q=scan.next();
			switch(q){
			case("push"):
				int k=scan.nextInt();
				stack.push(k);
				break;
			case("pop"):
				if(stack.size()==0) {
					System.out.println(-1);
				}else{
					System.out.println(stack.pop());
				}
				break;
			case("size"):
				System.out.println(stack.size());
				break;
			case("empty"):
				if(stack.empty()==true) {
					System.out.println(1);
				}else {
					System.out.println(0);
				}
				break;
			case("top"):
				if(stack.size()==0) {
					System.out.println(-1);
				}else {
					System.out.println(stack.get(stack.size()-1));
				}
				break;
			}
			i++;
		}
	}
}
