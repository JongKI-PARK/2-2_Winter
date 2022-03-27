import java.util.Scanner;

public class Sorting {
	
	static Scanner scan=new Scanner(System.in);
	static int[] alist;
	
	public static void main(String[] args) {
		
		int n=scan.nextInt();
		while(n>1000){
			if (n>1000){
				n=scan.nextInt();
			}
		}

		alist=new int[n];
		
		for(int i=0;i<n;i++) {
			alist[i]=scan.nextInt();
		}
		sorting(alist);
		quick_sorting(alist,0,alist.length-1);

	}
	
	public static void sorting(int[] list) {
		
		for(int i=0;i<list.length-1;i++) {
			for(int j=0;j<list.length-1;j++) {
				int temp;
				if(list[j]>list[j+1]) {
					temp=list[j];
					list[j]=list[j+1];
					list[j+1]=temp;
				}
			}
		}
		
		alist=list;
		for(int i=0;i<list.length;i++) {
			System.out.println(list[i]);
		}
	}
	
	public static void quick_sorting(int[] list,int si,int ei) {
		if((ei-si)<=0) {
			alist=list;
			System.out.println("quick sorting");
			for(int i=0;i<list.length;i++) {
				System.out.println(alist[i]);
			}
			return ;
		}
		int point=list[list.length-1];
		int i=si;
		for(int j=si;j<ei;j++) {
			if(list[j]<point) {
				int temp=list[i];
				list[i]=list[j];
				list[j]=temp;
				i++;
			}
		}
		int temp=list[i];
		list[i]=list[ei];
		list[ei]=temp;
		
		quick_sorting(list,si,i-1);
		quick_sorting(list,i+1,ei);
	}
}
