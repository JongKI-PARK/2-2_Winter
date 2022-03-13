import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Scanner;

public class Statistics_bj2108 {

	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {

	int n=scan.nextInt();
	while(n%2==0) {
		n=scan.nextInt();
	}
	
	int[] nums=new int[n];

	for(int i=0;i<n;i++) {
		nums[i]=scan.nextInt();
		}
	
	System.out.println(mean(nums,n));
	System.out.println(median(nums,n));
	System.out.println(mode(nums,n));
	System.out.println(range(nums,n));
	}
	
	public static double mean(int[] nums,int n) {
		double sum=0;
		for(int i=0;i<nums.length;i++) {
			sum+=nums[i];
		}
		double result=sum/n;
		return Math.round(result);
	}
	
	
	public static int median(int[] nums,int n) {
		Arrays.sort(nums);
		int j=Math.round(n/2);
		return nums[j];
	}
	
	public static int mode(int[] nums,int n) {
		int[] mode_p=new int[10000];
		int[] mode_m=new int[10000];
		
		//�迭�ȿ� ����� ���� ������ ���� �����Ƿ� ���� �󵵼��� ��� �󵵼��� �����ش�
		for(int i=0;i<n;i++) {
			if(nums[i]>=0) {
				mode_p[nums[i]]++;
			}else {
				mode_m[-nums[i]]++;
			}
		}
		
		//���� ������ ��������� �ֺ��� ã�´�
		ArrayList<Integer> list=new ArrayList<Integer>();
		int max_p=0;
		int max_m=0;
		for(int i=0;i<10000;i++) {
			if(max_p<mode_p[i]) {
				max_p=mode_p[i];
			}
		}
		
		for(int i=0;i<10000;i++) {
			if(max_m<mode_m[i]) {
				max_m=mode_m[i];
			}
		}		
		
		if(max_p>max_m) {
			for(int i=0;i<10000;i++) {
				if(mode_p[i]==max_p) {
					for(int j=0;j<10000;j++) {
						if(max_p==mode_p[j]) {
							if(list.contains(j)==true) {
								continue;
							}else
								list.add(j);
						}
					}
				}
			}
		}else if(max_p<max_m){
			for(int i=0;i<10000;i++) {
				if(mode_m[i]==max_m) {
					for(int j=0;j<10000;j++) {
						if(max_m==mode_m[j]) {
							if(list.contains(-j)==true) {
								continue;
							}else
								list.add(-j);
						}
					}
				}
			}
		}else {
			for(int i=0;i<10000;i++) {
				if(mode_m[i]==max_m) {
					for(int j=0;j<10000;j++) {
						if(max_m==mode_m[j]) {
							if(list.contains(-j)==true) {
								continue;
							}else
								list.add(-j);
						}
					}
				}
			}
			for(int i=0;i<10000;i++) {
				if(mode_p[i]==max_p) {
					for(int j=0;j<10000;j++) {
						if(max_p==mode_p[j]) {
							if(list.contains(j)==true) {
								continue;
							}else
								list.add(j);
						}
					}
				}
			}
		}
		
		Collections.sort(list);
		if(list.size()>1) {
			return list.get(1);
		}else
			return list.get(0);
	}

	
	public static int range(int[] nums,int n) {
		Arrays.sort(nums);
		int r=nums[n-1]-nums[0];
		return r;
	}
}
