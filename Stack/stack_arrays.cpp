#include<stdio.h>
int top=-1;
int stack[100];

int  isfull()
{
	if(top==99)
	{return 1;
	}
	else
	{
		return 0;
	}
}
int  isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
void push(int a)
{
	if(isfull())
	{
	    printf("stack is full");
		return;	
	}
	top++;
	stack[top]=a;
}

void pop()
{
	if(isempty())
	{
		printf("stack is empty");
		return;
	}
	top--;
	printf("%d",stack[top+1]);
}
void peek()
{
		if(isempty())
	{
		printf("stack is empty");
		return;
	}
	printf("%d",stack[top]);
}
void display()
{
	for(int i=0;i<=top;i++)
	{
		printf("%d\n",stack[i]);
	}
}


int main()
{  int option=1;
  
 while(option)
{

	printf("\nchoose the number corresponding to function you want to perform on stack\n");
	printf("1-push\n2-pop\n3-peek\n4-isempty\n5-display\n6-exit\n");
	
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		int a;
		printf("enter the number to be added\n");
		scanf("%d",&a);
		push(a);
	 } 
	 if(choice==2)
	 {
	 	pop();
	 }
	 if(choice==3)
	 {
	 	peek();
	 }
	 if(choice==4)
	 {
	 	int c=isempty();
	 	if(c==1)
	 	{printf("yes");
		 }
	 	
	 }
	 if(choice==5)
	 {
	 	display();
	 	
	 }
	 if(choice==6)
	 {
	 	option=0;
	 }

}}

