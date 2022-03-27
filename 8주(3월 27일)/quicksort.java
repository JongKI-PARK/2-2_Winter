package baekjun2108;

import java.util.Arrays;
import java.util.Scanner;

public class quicksort {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("요솟 수 :");
		int n = sc.nextInt();
		int[] arr = new int[n];

		for (int i = 0; i < arr.length; i++) {
			
			arr[i] = sc.nextInt();
		}

		qs(arr,0,arr.length-1);

		
		for (int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]);
		}
		
		
	}
	public static void qs(int [] arr, int start, int end) {
		int pivot= start;
		int left= start+1;
		int right=end;
		int temp;
		
		while(left<=right) {
			while(left<=end&&arr[left]<=arr[pivot]) {
				left++; //피벗보다 큰 데이터를 찾을 때까지 반복
			}
			while(right>start&&arr[right]>=arr[pivot]) {
				right--; //피벗보다 작은 데이터를 찾을 때 까지 반복
			}
			
			if(left>right) {//데이터가 엇갈린다면
				temp = arr[pivot];
				arr[pivot] = arr[right];
				arr[right] = temp;
			}else {
				temp = arr[left];
				arr[left]= arr[right];
				arr[right]=temp;
			}
			qs(arr, start, right-1); //분할이후 왼쪽에서 정렬수행
			qs(arr, right+1,end);
				
			}
			
			
		}
		
		
	}
	
	

