#include<stdio.h>
#include<stdlib.h>


struct node 
{
	int data;
	struct node *next;
	
}*head1=NULL,*head2=NULL,*head3=NULL;


void insertinfll(int val)  //insert in first linked list
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head1==NULL)
	{
		head1=newnode;
	}
	else
	{
		struct node *temp=head1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	printf("node inserted\n");
}

void insertinsll(int val)  //insert in second linked list
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head2==NULL)
	{
		head2=newnode;
	}
	else
	{
		struct node *temp=head2;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	printf("node inserted\n");
}
void insert(int val)  //insert in newly formedlinkedlist after intersection
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head3==NULL)
	{
		head3=newnode;
	}
	else
	{
		struct node *temp=head3;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	
}


void intersection()
{
  struct node *temp1=head1;
  struct node *temp2=head2;
  int option=1;
  while(option)
  {
  	
  	if((temp1->data)==(temp2->data))
  	{   if(head3==NULL)
  	{
  		insert(temp1->data);
  		temp1=temp1->next;
  		temp2=temp2->next;
	  }
	  else
	  {
	  
  		struct node *temp3=head3;
  		struct node *a;
  		while(temp3!=NULL)
  		{    a=temp3;
  			temp3=temp3->next;
		}
		
		if(temp1->data != a->data)
		{
		    
		insert(temp1->data);
  		temp1=temp1->next;
  		temp2=temp2->next;
  	}}
	}
	else if((temp1->data)>(temp2->data))
	{
		temp2=temp2->next;
	}
	else 
	{
		temp1=temp1->next;
	}
	if(temp1==NULL || temp2==NULL)
	{
		option=0;
	}
	
	
    
  }

}
	




void display3()
{

if(head3 == NULL)
   {
      printf("\nempty List3\n");
   }
   else
   {
      struct node *temp3 = head3;
      printf("\n\nList3 elements are - \n");
      while(temp3->next != NULL)
      {
	 printf("%d ->",temp3->data);
	 temp3 = temp3->next;
      }
      printf("%d ->NULL",temp3->data);
   }   
}

void display2()
{

if(head2 == NULL)
   {
      printf("\nempty List2\n");
   }
   else
   {
      struct node *temp2 = head2;
      printf("\n\nList2 elements are - \n");
      while(temp2->next != NULL)
      {
	 printf("%d ->",temp2->data);
	 temp2 = temp2->next;
      }
      printf("%d ->NULL",temp2->data);
   }   
}
void display1()
{

if(head1 == NULL)
   {
      printf("\nempty List1\n");
   }
   else
   {
      struct node *temp1 = head1;
      printf("\n\nList1 elements are - \n");
      while(temp1->next != NULL)
      {
	 printf("%d ->",temp1->data);
	 temp1 = temp1->next;
      }
      printf("%d ->NULL",temp1->data);
   }   
}
int main()
{
	int choice,val1,val2;
	int option=1;
	while(option)
	{
		 printf("\n1. Insert in list1\n2. insert in list 2\n3. perform intersection function\n4. display\n5.exit\nEnter your choice: ");
   scanf("%d",&choice);
   if(choice==1)
   {
   	printf("\nvalue to be inserted in list1");
   	scanf("%d",&val1);
   	insertinfll(val1);
   }
   if(choice==2)
   {
   	printf("\nvalue to be inserted in list2");
   	scanf("%d",&val2);
   	insertinsll(val2);
	}
	if(choice==3)
	{
		intersection();
		
		
	}
	if(choice==4)
	{
		display1();
		display2();
		display3();
	}
	if(choice==5)
	{
		option=0;
	}
	
}
return 0;
}
