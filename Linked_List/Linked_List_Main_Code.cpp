#include<iostream>
#include<cstdlib>
using namespace std;


struct node
{
	int data;
	struct node *next;
}*head=NULL;

void insertatbegining(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
    if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
		
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	cout<<"node inserted"<<endl;
	
}




void insertatend(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	cout<<"node inserted"<<endl;
}



void insertbetween(int val,int loc1,int loc2)
{
	struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	
	if(head==NULL)
	{
	   newnode->next=NULL;
	   head=newnode;
    }
    else
    {
    	struct node *temp=head;
    	while(temp->data!=loc1 && temp->data!=loc2)
    	{
    		temp=temp->next;
    		
		}
		newnode->next=temp->next;
		temp->next=newnode;
		
	}
	cout<<"node inserted"<<endl;
}

void removebegining()
{
	if(head==NULL)
	{
		cout<<"list empty"<<endl;
		
	}
	else
	{
		struct node *temp=head;
		if(head->next==NULL)
		{
			head=NULL;
			free(temp);
		}
		else
	{
		head=temp->next;
		free(temp);
		cout<<"one node deleted"<<endl;
		
	}
		
	}
}

void removeend()
{
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
		
	}
	else
	{
		struct node *temp1=head,*temp2;
		if(head->next==NULL)
		{
			head=NULL;
			
		}
		else
		{
			while(temp1->next!=NULL)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			temp2->next=NULL;
		}
		free(temp1);
		cout<<"node deleted"<<endl;
		
	}
}



void removespecific(int val)
{
	struct node *temp1=head,*temp2;
	while(temp1->data!=val)
	{
		if(temp1->next==NULL)
		{
			cout<<"not found"<<endl;
			return;
		}
		temp2=temp1;
		temp1=temp1->next;
		
	}
	temp2->next=temp1->next;
	free(temp1);
	cout<<"node deleted"<<endl;
}

void display()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp->next != NULL)
      {
	 printf("%d --->",temp->data);
	 temp = temp->next;
      }
      printf("%d --->NULL",temp->data);
   }
}

void printusingrecursion(struct node *p)
{
	if(p==NULL)
	{
		return;
	}
	cout<<p->data;
	printusingrecursion(p->next);
}

void reverseprintusingrecursion(struct node *p)
{
	if(p==NULL)
	{
		return;
	}
	reverseprintusingrecursion(p->next);
    cout<<p->data;
}


void reverse(struct node *p)
{
	if(p->next==NULL)
	{
		head=p;
		return;
	}
	reverse(p->next);
	struct node *q=p->next;
	q->next=p;
	p->next=NULL;
	
}




int main()
{
   int choice,value,choice1,loc1,loc2;

   while(1){
   mainMenu: printf("\n\n********* MENU ************\n1. Insert\n2. Display\n3. Delete\n4. printusingrecursion  \n5-reverse print using recursion\n6-reverse\n7-ext\nEnter your choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
      case 1: 	printf("Enter the value to be insert: ");
		scanf("%d",&value);
		while(1){
		printf("Where you want to insert: \n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
		scanf("%d",&choice1);
		switch(choice1)
		{
		   case 1: 	insertatbegining(value);
				break;
		   case 2: 	insertatend(value);
				break;
		   case 3:      printf("Enter the two values where you wanto insert: ");
				scanf("%d%d",&loc1,&loc2);
				insertbetween(value,loc1,loc2);
				break;
		   default: 	printf("\nWrong Input!! Try again!!!\n\n");
				goto mainMenu;
		}
		goto subMenuEnd;
		}
		subMenuEnd:
		break;
      case 2: 	display();
		break;
      case 3: 	printf("How do you want to Delete: \n1. From Beginning\n2. From End\n3. Spesific\nEnter your choice: ");
		scanf("%d",&choice1);
		switch(choice1)
		{
		   case 1: 	removebegining();
				break;
		   case 2: 	removeend();
				break;
		   case 3:      printf("Enter the value which you wanto delete: ");
				scanf("%d",&loc2);
				removespecific(loc2);
				break;
		   default: 	printf("\nWrong Input!! Try again!!!\n\n");
				goto mainMenu;
		}
		break;
		
	  case 4:  printusingrecursion(head);
	  break;
	  case 5: reverseprintusingrecursion(head);
	  break;
	  case 6: reverse(head);	
	  break;
      case 7: 	exit(0);
      default: printf("\nWrong input!!! Try again!!\n\n");
   }
   }
return 0;
}


