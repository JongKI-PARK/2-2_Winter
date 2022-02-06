import java.util.*;

public class Tree {
	static ArrayList<Character> preorder;//전위
	static ArrayList<Character> inorder;//중위
	static ArrayList<Character> postorder;//후위
	
	public static void main(String[] arg) {
		ArrayList<Node> nodes=new ArrayList();
		//순회 리스트 생성
		preorder =new ArrayList();
		inorder =new ArrayList();
		postorder =new ArrayList();
		
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		
		//아스키 코드 활용 65부터 대문자 A
		for(int i=0;i<n;i++) {
			Node node = new Node();
			node.value=(char)(i+65);//아스키 코드를 활용해서 65를 더하여 알파벳으로 변환
			nodes.add(node);
		}
		
		//String.charAt(i) > String 타입 변수로 입력 받아서 i번째 문자열 받아오기
		//만약 int형으로 변환하고 싶을 시 charAt(i)-0
		for(int i=0;i<n;i++) {
			char value=(scan.next()).charAt(0);
			char left=(scan.next()).charAt(0);
			char right=(scan.next()).charAt(0);
			Node thisnode=nodes.get(value-65);//아스키코드 0~31은 . , 과 같은 제어문자
			
			if(left != '.') {
				Node leftnode=nodes.get(left-65);
				thisnode.leftChild=leftnode;
			}
			if(right !='.') {
				Node rightnode=nodes.get(right-65);
				thisnode.rightChild=rightnode;
			}
		}
		//nodes에 저장된 0번째 인덱스부터 시작
		preorder(nodes.get(0));
		inorder(nodes.get(0));
		postorder(nodes.get(0));
		for(char c : preorder) {
			System.out.print(c);
		}
		System.out.println();
		for(char c : inorder) {
			System.out.print(c);
		}
		System.out.println();
		for(char c : postorder) {
			System.out.print(c);
		}
		System.out.println();
	}
	//순회 공식(재귀 함수 활용), *study 첫날 했던 dfs와 비슷한 구문
	static void preorder(Node node) {
		preorder.add(node.value);
		if(node.leftChild != null) {
			preorder(node.leftChild);
		}
		if(node.rightChild!= null) {
			preorder(node.rightChild);
		}
	}
	
	static void inorder(Node node) {
		if(node.leftChild != null) {
			inorder(node.leftChild);
		}
		inorder.add(node.value);
		if(node.rightChild!= null) {
			inorder(node.rightChild);
		}
	}
	
	static void postorder(Node node) {
		if(node.leftChild != null) {
			postorder(node.leftChild);
		}
		if(node.rightChild!= null) {
			postorder(node.rightChild);
		}
		postorder.add(node.value);
	}
}
	


class Node{
	char value;
	Node leftChild;
	Node rightChild;
	
	void setLeft(Node left) {
		this.leftChild=left;
	}
	
	void setRight(Node right) {
		this.rightChild=right;
	}

	@Override
	public String toString() {
		return "Node [value=" + value + ", leftChild=" + leftChild + ", rightChild=" + rightChild + "]";
	}
}
