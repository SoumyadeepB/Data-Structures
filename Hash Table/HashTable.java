import java.util.*;

class Node{
  
  
  Node next = null;
  int data=0;
  public Node(int d)
  {
     data = d;
	 next = null;
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
  
  boolean search(int x)
  {
     Node n = this;
	 
	 while(n!= null)
	 {
	    if(n.data==x)
		 return true;
	   n=n.next;
	 }
	 return false;
  }
}

/*class SingleLL{

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

}*/

class HashTable
{

public static void main(String args[])
{
System.out.println("Hash Table of 20 columns:  /nHash function used : (data % 23)%20" );
int index=0,x=0;
Node []arr= new Node[20];
while(x<20)
{
  arr[x] = new Node(x+1);
  x++;
 }
System.out.println("Enter data :  [type -1 to quit]");
Scanner sc = new Scanner(System.in);

while(true)
{
 x = sc.nextInt();
 if(x==-1)
  {
  System.out.println("Entry complete! "); 
  break;
 }
 index = (x % 23)%20;
 arr[index].addElement(x);

}

x=0;
while(x<20){
arr[x].display();
System.out.println();
x++;
}
System.out.println("Search for an element [-1 to quit]:");
 while(true)
 {
 x = sc.nextInt();
 if(x==-1)
  break;
 index = (x % 23)%20;
 
 if(arr[index].search(x))
  System.out.println("Data present!");
  else
  System.out.println("Data not present!");
}
}
}