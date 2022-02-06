import java.util.*;

public class Tree {
	static ArrayList<Character> preorder;//����
	static ArrayList<Character> inorder;//����
	static ArrayList<Character> postorder;//����
	
	public static void main(String[] arg) {
		ArrayList<Node> nodes=new ArrayList();
		//��ȸ ����Ʈ ����
		preorder =new ArrayList();
		inorder =new ArrayList();
		postorder =new ArrayList();
		
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		
		//�ƽ�Ű �ڵ� Ȱ�� 65���� �빮�� A
		for(int i=0;i<n;i++) {
			Node node = new Node();
			node.value=(char)(i+65);//�ƽ�Ű �ڵ带 Ȱ���ؼ� 65�� ���Ͽ� ���ĺ����� ��ȯ
			nodes.add(node);
		}
		
		//String.charAt(i) > String Ÿ�� ������ �Է� �޾Ƽ� i��° ���ڿ� �޾ƿ���
		//���� int������ ��ȯ�ϰ� ���� �� charAt(i)-0
		for(int i=0;i<n;i++) {
			char value=(scan.next()).charAt(0);
			char left=(scan.next()).charAt(0);
			char right=(scan.next()).charAt(0);
			Node thisnode=nodes.get(value-65);//�ƽ�Ű�ڵ� 0~31�� . , �� ���� �����
			
			if(left != '.') {
				Node leftnode=nodes.get(left-65);
				thisnode.leftChild=leftnode;
			}
			if(right !='.') {
				Node rightnode=nodes.get(right-65);
				thisnode.rightChild=rightnode;
			}
		}
		//nodes�� ����� 0��° �ε������� ����
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
	//��ȸ ����(��� �Լ� Ȱ��), *study ù�� �ߴ� dfs�� ����� ����
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
