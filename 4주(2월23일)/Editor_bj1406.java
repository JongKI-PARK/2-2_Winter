import java.util.Scanner;

public class Editor_bj1406 {

	static Scanner scan = new Scanner(System.in);
	static int cursor=0;
	
	public static void main(String[] args) {
		
		String word = scan.next();
		cursor=word.length();
		
		int n=scan.nextInt();
		
		int i=0;
		while(i<n) {
			String inst=scan.next();
			switch(inst) {
			case("P"):
				String pw=scan.next();
				String nword = null;
				nword=word.substring(0,cursor)+pw+word.substring(cursor,word.length());
				word=nword;
				cursor+=1;
				break;
			case("L"):
				if(cursor>0) {
					cursor-=1;
				}else
					cursor=0;
				break;
			case("D"):
				if(cursor<word.length()) {
					cursor+=1;
				}else
					cursor=word.length();
				break;
			case("B"):
				if(cursor==0) {
					break;
				}else {
					String nword1=null;
					nword1=word.substring(0,cursor-1)+word.substring(cursor);
					if(cursor>0) {
						cursor-=1;
					}else
						cursor=0;
					word=nword1;
					System.out.println(word);
					break;
				}
			}
			i++;
		}
		System.out.println(word);
	}
	

}
