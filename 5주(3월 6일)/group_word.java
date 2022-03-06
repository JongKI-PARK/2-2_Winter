package group_word_bj1316;
import java.util.Scanner;

public class group_word {

	static Scanner scan = new Scanner(System.in);
	static int answer;
	
	public static void main(String[] args) {
		
		int n=scan.nextInt();
		answer=n;
		
		for(int i=0;i<n;i++) {
			String str=scan.next();
			getGroupN(str);
		}
		System.out.println(answer);
	}
	
	public static void getGroupN(String str) {
		
		for(int i=0;i<str.length()-1;i++){//인덱스를 활용한다		
			//앞 뒤의 문자를 비교할 때 인덱스를 활용한다
			//만약 한번 나왔던 문자일 경우 인덱스가 앞에 나왔던 인덱스로 나오면서 이미 한번 나왔다는 뜻으로 그룹단어가 될 수 없다.
			if(str.indexOf(str.charAt(i)) > str.indexOf(str.charAt(i+1))) {
				answer--;
				break;
			}
		}	
	}
}
