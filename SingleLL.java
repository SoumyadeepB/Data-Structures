import java.util.*;

class Node{
  
  
  Node next = null;
  int data=0;
  public Node(int d)
  {
     data = d;
	
  }
  
  void addElement(int d)
  {
     Node end = new Node(d);
	 
	 Node n =this;
	
	 while(n.next != null)
	 {
	   n = n.next;
	 }
	 n.next=end;
  }
  
  void display()
  {
     Node n = this;
	 
	 while(n!= null)
	 {
	   System.out.print(n.data+" --> ");
	   n=n.next;
	 }
  }  
}

class SingleLL{

public static void main(String args[]){


Scanner sc = new Scanner(System.in);
System.out.println("Enter the elements [-1 to exit] : ");


int i=0,d=0;


d = sc.nextInt();
Node head = new Node(d);
//System.out.println(head.data); 

do{

  d=sc.nextInt();
  if(d!=-1)
  {  
    head.addElement(d);
  }
}while(d!=-1);

  head.display();
}

}
