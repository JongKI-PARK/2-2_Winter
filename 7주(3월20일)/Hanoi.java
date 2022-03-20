import java.util.Scanner;
import java.util.Stack;

public class Hanoi {
	
	static Scanner scan=new Scanner(System.in);
	static int count=0;
	static Stack<Integer> st1=new Stack<Integer>();
	static Stack<Integer> st2=new Stack<Integer>();
	static Stack<Integer> st3=new Stack<Integer>();
	
	public static void main(String[] args) {
		
		int n=scan.nextInt();
		for(int i=n;i>0;i--) {
			st1.push(i);
		}
		
		count=(int) (Math.pow(2, n)-1);
		
		System.out.println(count);
		
		Hanoi(1,2,3,n);
	}
	
	public static void Hanoi(int first,int second, int third,int n) {
		if(n==1) {
			System.out.println(first+"\t"+third);
			Hanoi_Calculate(first,second,third);
//			
			System.out.println(st1);
			System.out.println(st2);
			System.out.println(st3);
			return;
		}
		//최종적으로 1번에서 3번으로 옮기기
		
		// 1번에서 2번으로 옮길 때
		Hanoi(first, third, second,n-1);

		//step2. 1번에서 3번으로 옮길 때
		System.out.println(first+"\t"+third);
		Hanoi_Calculate(first,second,third);

		System.out.println(st1);
		System.out.println(st2);
		System.out.println(st3);
		
		//step3. 2번에서 3번으로 옮길 때
		Hanoi(second,first, third,n-1);
		
	}	
	
	public static void Hanoi_Calculate(int first,int second, int third) {
		
		if(first==1 && third==2) {
			if(st1.size()!=0) {
				st2.push(st1.get(st1.size()-1));
				st1.pop();
			}
		}else if(first==1 && third==3) {
			if(st1.size()!=0) {
				st3.push(st1.get(st1.size()-1));
				st1.pop();
			}
		}else if(first==2 && third==1) {
			if(st2.size()!=0) {
				st1.push(st2.get(st2.size()-1));
				st2.pop();
			}
		}else if(first==2 && third==3) {
			if(st2.size()!=0) {
				st3.push(st2.get(st2.size()-1));
				st2.pop();
			}
		}else if(first==3 && third==1) {
			if(st3.size()!=0) {
				st1.push(st3.get(st3.size()-1));
				st3.pop();
			}
		}else if(first==3 && third==2) {
			if(st3.size()!=0) {
				st2.push(st3.get(st3.size()-1));
				st3.pop();
			}
		}
	}

}
/*
 입력 : 3
 출력 :
 7
1	3
[3, 2]
[]
[1]
1	2
[3]
[2]
[1]
3	2
[3]
[2, 1]
[]
1	3
[]
[2, 1]
[3]
2	1
[1]
[2]
[3]
2	3
[1]
[]
[3, 2]
1	3
[]
[]
[3, 2, 1]

 */
