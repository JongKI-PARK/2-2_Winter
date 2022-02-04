import java.util.Scanner;

public class CuttingTree {

	public static void main(String[] args) {
		System.out.println("������ �� N�� �ʿ��� ������ ���� M�� �Է��Ͻÿ� :");
		int n=UserInput.getInt();
		int m=UserInput.getInt();
		
		if(n<1 || n>1000000) {
			n=UserInput.getInt();
		}
		if(m<1 || m>2000000000) {
			m=UserInput.getInt();
		}
		
		int[] tree=new int[n];
		
		System.out.println("������ ������ ���̸� �Է��Ͻÿ� : ");
		for(int i=0;i<n;i++) {
			tree[i]=UserInput.getInt();
		}
		
		System.out.println(getH(tree,m));
		
	}
// ----------------------------------------------------
	public static class UserInput{
		static Scanner scan=new Scanner(System.in);
		
		public static int getInt() {
			int value=0;
			value=scan.nextInt();
			return value;
		}
		
	}
	
	public static int getH(int[] tree, int m) {
		int mth=0;
		for(int j=0;j<tree.length;j++) {
			mth=Math.max(mth, tree[j]);
		}
		
		while(mth>0) {
			int h=0;
			for(int i=0;i<tree.length;i++) {
				if(tree[i]-mth<0) {
					continue;
				}
				else {
					h=h+(tree[i]-mth);
				}
			}
			
			if(h==m) {
				break;
			}
			else mth--;
		}
		
		return mth;
	}
}
