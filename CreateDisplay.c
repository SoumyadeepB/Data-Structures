#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}nd;
nd *start = NULL;
void create()
{
	char ch;
    nd *ptr;
    ptr=(nd*)malloc(sizeof(nd));
    printf("\n  Enter data: ");
    scanf("%d",&ptr->data);
    
  	if(start==NULL)
  	  start=ptr;
  	  
  	  printf("\n Continue entry?(Y/N) :\t");
  	  ch=getche();
  	  
  	 while(ch=='y' || ch=='Y')
	   {
	   	ptr->link=(nd*)malloc(sizeof(nd));
 		   ptr=ptr->link;
		   printf("\n  Enter data: ");
 		   scanf("%d",&ptr->data);
 		   
 		   printf("\n Continue entry?(Y/N) :\t");
  	  		ch=getche();
	   } 
		ptr->link=NULL;
}

void display()
{
	nd *ptr=start;
	printf("\n Start ->");
	while(ptr)
	{
		printf("%d ->",ptr->data);
		ptr=ptr->link;
	}
	printf("NULL.");
}

void displayRev(nd *ptr)
{

	if(ptr)
	{
		displayRev(ptr->link);
		printf("%d ->",ptr->data);
	}

}

void insAt(int n)		// n : node number
{
	int count=1;
	nd *temp,*ptr,*pre;
	ptr=pre=start;
	
	
	while(count!=n && ptr)
	{
	  pre=ptr;
	  ptr=ptr->link;
	   count++;	
	}
	if(ptr==NULL)
	 {
	  printf("\n Linked list contains less than %d nodes.",n);
	 return; 
	 }
	 
	 temp=(nd*)malloc(sizeof(nd));
   		 printf("\n  Enter data to be inserted: ");
   		 scanf("%d",&temp->data);
   		 temp->link=NULL;
   		 
	if(n!=1)
	{
		    temp->link=ptr;
		    pre->link=temp;	
	}
	else if(n==1)
	{
		temp->link=start;	
		start=temp;
	}
printf("\n Node inserted.\n");
display();	

}
void insBef(int x)
{
	nd *temp,*ptr,*pre;
	ptr=pre=start;
	
	
	while(ptr && ptr->data!=x)
	{
	  pre=ptr;
	  ptr=ptr->link;
	   
	}
	if(ptr==NULL)
	 {
	  printf("\n %d not present.",x);
	 return; 
	 }
	 
	 temp=(nd*)malloc(sizeof(nd));
   		 printf("\n  Enter data to be inserted: ");
   		 scanf("%d",&temp->data);
   		 temp->link=NULL;
   		 
	if(start->data!=x)
	{
		    temp->link=ptr;
		    pre->link=temp;	
	}
	else 
	{
		temp->link=start;	
		start=temp;
	}
printf("\n Node inserted.\n");
display();	
}

void insAft(int x)
{
  	nd *temp,*ptr;
	ptr=start;
	
	
	while(ptr->data!=x && ptr)
	{
	  
	  ptr=ptr->link;
	   
	}
	if(ptr==NULL)
	 {
	  printf("\n %d not present.",x);
	  return; 
	 }
	 
	 temp=(nd*)malloc(sizeof(nd));
   		 printf("\n  Enter data to be inserted: ");
   		 scanf("%d",&temp->data);
   		 temp->link=NULL;
   		 
	temp->link=ptr->link;
	ptr->link=temp;
	
printf("\n Node inserted.\n");
display();	
}

void reverse()
{
	nd *curr,*pre,*next;
	pre=NULL;
	curr=start;
	next=curr->link;
	
	while(curr!=NULL)
	{
		curr->link=pre;
		pre=curr;
		curr=next;
		next=next->link;
	}
	start=pre;
	display();
	
}
void main()
{
	
 char c;
 int ch,pos;
    while(1)
    { 
      
    	printf("\n 1. Create \t\t 2. Display");
	printf("\n 3. Insert At \t\t 4. Insert Before \t\t5. Insert After");
	printf("\n 6. Display Reverse \t\t 7. EXIT");
	printf("\n\tEnter your choice: ");
	scanf("%d",&ch);
    	switch(ch)
    	{
    	   
    	          case 1: create();
    	          break;
    	          case 2: display();
    	          break;
    	          case 3: 
			  printf("\n Enter position to insert at: ");
			  scanf("%d",&pos);
			  insAt(pos);
    	          break;
    	         case 4:printf("\n Enter the element to insert before: ");
			  scanf("%d",&pos); 
			 insBef(pos);
    	         break;
    	          case 5: printf("\n Enter the element to insert after: ");
			  scanf("%d",&pos); 
			 insAft(pos);
    	           break;
    	          case 6: 
    	          
    	                printf("NULL ->");
			     displayRev(start);
			     printf("Start");
    	          break;
    	          case 7: exit(0);
    	          break;
    	          default: printf("\nWrong Choice");
    	}
    	  printf("\n Continue? (Y/N) :");
    	  c=getche();
    	  if(c=='n')
    	    break;
    }	
}
/* void Reverse()
 {
 	nd* pre=NULL,*curr,*nxt; int i=0;
 	curr=start;
 	nxt=curr->link;
 	while(nxt->link!=NULL)
 	  {
 	  	curr->link=pre;
 	  	pre=curr;
 	  	curr=nxt;
 	  	if(nxt->link)
 	  	nxt=nxt->link;
 	  	printf("%d",++i);
 	  }
 	  start=curr;
 	  
 }
void nodeCount()
   {
   		int chk=0;
   	 	ptr=start;
 	 
	 while(ptr)
	 {
	 	chk++;
	 	ptr=ptr->link;
	 	
	 }
	 printf("\n	No. of Nodes = %d",chk );
   }
 void InsertAt(int x)
 {	
 	nd *ptr1;
	 int chk=0;
 	ptr=start;
 	
	 while(1)
	 {
	 	if(chk==(x-2))
	 	  break;
	 	  ptr=ptr->link;
	 	  chk++;
	 }
	 ptr1=(nd*)malloc(sizeof(nd));
	 printf("chk =%d",chk);
	 printf("\nEnter the data : ");
     scanf("%d",&ptr1->data);
	 ptr1->link=ptr->link;
	 ptr->link=ptr1;
	 printf("\n\n\n   The new list is:\n");
	 //return 0;
	 display();
 }
void InsBef(int x)
 {
 	nd *ptr1;
	 int chk=1;
 	ptr=start;
 	
	 while(1)
	 {
	 	if(chk==(x-2))
	 	  break;
	 	  ptr=ptr->link;
	 	  chk++;
	 }
	 ptr1=(nd*)malloc(sizeof(nd));
	 printf("chk =%d",chk);
	 printf("\nEnter the data : ");
     scanf("%d",&ptr1->data);
	 ptr1->link=ptr->link;
	 ptr->link=ptr1;
	 printf("\n\n\n   The new list is:\n");
	 //return 0;
	 display();
 }
nd *search(int x)
{
	ptr=start;
	while(ptr->data!=x)
	{
		ptr=ptr->link;
		if(!ptr)
		 break;
	}
	return ptr;
}
*/
