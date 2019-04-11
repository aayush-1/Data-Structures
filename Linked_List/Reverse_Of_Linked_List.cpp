#include<iostream>
using namespace std;
#include<cstdlib>

struct node 
{
	int data;
	struct node *next;
}*head=NULL;

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

struct node *reverse(struct node *head)
{
	struct node *current,*prev,*next;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}


int main()
{
	 int choice,value;
	  while(1){
   mainMenu: printf("\n 1-insert , 2-reverse,3-display");
   scanf("%d",&choice);
   switch(choice)
   {
      case 1: 	printf("Enter the value to be insert: ");
		scanf("%d",&value);
		insertatend(value);
		break;
	  case 2: head=reverse(head);
	          break;
	  case 3:display();
	         break;
	  case 4: exit(0);	
}
}
}

