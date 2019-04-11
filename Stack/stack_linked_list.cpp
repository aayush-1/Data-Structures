#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
	
}*top=NULL;


void push(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(top==NULL)
	{
		newnode->next=NULL;
	}
	else
	{
		newnode->next=top;
		
	}
	top=newnode;
	
}


void pop()
{
    if(top==NULL)
	{
		cout<<"empty"<<endl;
    }
    else
    {
    	struct node *temp=top;
    	cout<<temp->data<<endl;
    	top=temp->next;
    	free(temp);
	}
	
}


void display()
{
	if(top==NULL)
	{
		cout<<"empty"<<endl;
		
	}
	else
	{
		struct node *temp=top;
		while(temp->next!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
			
		}
		cout<<temp->data;
	}
}





int main()
{  int option=1;
 while(option)
{

	cout<<"\nchoose the number corresponding to function you want to perform on stack\n";
	cout<<"1-push\n2-pop\n3-display\n";
	
	int choice;
	cin>>choice;
	if(choice==1)
	{
		int a;
		printf("enter the number to be added\n");
		cin>>a;
		push(a);
	 } 
	 if(choice==2)
	 {
	 	pop();
	 }
	 if(choice==3)
	 {
	 	display();
	 }
	 	
	 
	 
	 if(choice==4)
	 {
	 	option=0;
	 }

}}

