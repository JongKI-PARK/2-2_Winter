import java.util.Arrays;
import java.util.Scanner;

public class homunculus {
	
	static int[] answer=new int[7];
	static int n1;
	static int n2;
	
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		
		int[] hm=new int[9];
		System.out.println("난쟁이의 키를 입력하시오 : ");
		for(int i=0;i<9;i++) {
			hm[i]=scan.nextInt();
		}
		
		int sum=0;
		for(int i=0;i<9;i++)
		{
			sum=sum+hm[i];
		}
		int oversum=sum-100;
		
		for(int i=0;i<9;i++) {
			for(int j=i+1;j<9;j++) {
				if(hm[i]+hm[j]==oversum) {
					n1=hm[i];
					n2=hm[j];
					break;
				}
			}
		}
		int j=0;
		for(int i=0;i<9;i++) {
			if(hm[i]==n1 || hm[i]==n2) {
				continue;
			}else{
				answer[j]=hm[i];
				j++;
			}
		}
		
		Arrays.sort(answer);
		for(int i=0;i<7;i++) {
			System.out.println(answer[i]);
		}
	}
	
	
}
