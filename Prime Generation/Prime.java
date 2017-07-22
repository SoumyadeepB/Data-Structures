import java.util.*;
class Prime{

public static void main(String args[])
{
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter the limit for generating primes :");
  int n = sc.nextInt();
  int i=0,j=0,k=0;
  boolean a[] = new boolean[n+1];
  
  for( i=2;i<=n;i++)
  {
     while(i<=n && a[i])
	  i++;
	  
    k=2;
    while(k*i<=n)
	{
	  a[k*i]=true;
	  k++;
	}
    
  }
  System.out.println("Prime no.s <= "+n);
  System.out.println("2");
  for(i=3;i<=n;i=i+2)
    if(!a[i])
	 System.out.println(i);
  

}

}