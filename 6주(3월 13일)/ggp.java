import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class ggp {
	public static void main(String[] args) {
	  Scanner sc= new Scanner(System.in);
	
	  int N= sc.nextInt();
    
	
	  int [] arr= new int[N];
	
	  for(int i=0;i<arr.length;i++) {
		arr[i]= sc.nextInt();
	  }
	    double sum=0;
	
	
		for(int i=0;i<arr.length;i++) {
			sum+=arr[i];
			
		}
		
		 
		 
		  System.out.println(Math.round((sum/N)));
		  

		Arrays.sort(arr);
		
	    System.out.println(arr[Math.round(N/2)]);
	    
	   ArrayList<Integer> list= new ArrayList<Integer>();
	   int max=0;
	   int index[]= new int[8001];
	   
	   for(int i=0;i<N;i++) {
		   index[arr[i]+ 4000]++;
	   }
	   
	   for(int i=0;i<8001;i++) {
		   max=Math.max(max,index[i]);
		  
	   }
	   for(int i=0;i<8001;i++) {
		  if(index[i]==max) {
			  list.add(i-4000);
		  }
		  
	   }
	   if(list.size()>1) {
		   System.out.println(list.get(1));
	   }
	   else {
		   System.out.println(list.get(0));
	   }
	   
	   
	   
	   
	    System.out.println(arr[N-1]-arr[0]);
	}
	
}
