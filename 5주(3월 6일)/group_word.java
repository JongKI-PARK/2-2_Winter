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
		
		for(int i=0;i<str.length()-1;i++){//�ε����� Ȱ���Ѵ�		
			//�� ���� ���ڸ� ���� �� �ε����� Ȱ���Ѵ�
			//���� �ѹ� ���Դ� ������ ��� �ε����� �տ� ���Դ� �ε����� �����鼭 �̹� �ѹ� ���Դٴ� ������ �׷�ܾ �� �� ����.
			if(str.indexOf(str.charAt(i)) > str.indexOf(str.charAt(i+1))) {
				answer--;
				break;
			}
		}	
	}
}
