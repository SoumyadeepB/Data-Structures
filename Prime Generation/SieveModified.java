import java.util.*;
class SieveModified{

public static void main(String args[])
{
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter the limit for generating primes :");
  int n = sc.nextInt();
  int i=0,j=0,k=0,x=0;
  boolean a[] = new boolean[n/2+2];
  
  for( i=1; i<=n/2 ; i++)
  { 
    
     while(a[i])
	  i++;
	  
    k=2;
	x = i*2 +1;
    while(k * x <= n)
	{
	  if( ((k*x) % 2) !=0)
	   a[(k*x-1)/2]=true;
	  k++;
	}
    
  }
  System.out.println("Prime no.s <= "+n);
  System.out.println("2");
  x=1;
  for(i=1; i*2+1<=n ; i++)
    if(!a[i])
	 {System.out.println((i*2)+1);
       x++;
	  }
  System.out.println("Total primes : "+x);

}

}