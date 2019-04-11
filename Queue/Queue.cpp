#include<stdio.h>
int queue[100];
int f=0;
int r=-1;
void insert(int a)
{

 if(r==99)
	{
		printf("\nqueue is full\n");
	}
	else
	{
	
	    r++;
	    queue[r]=a;
    }
}
void remove()
{
	if(r==-1)
	{
		printf("\nqueue is empty\n");
		
	}
	else if(f==r)
	{
		int c=queue[f];
		r=r-1;
		printf("%d\n",c);
	}
	else
	{
		int c=queue[f];
		f++;
		printf("%d\n",c);
	}
}
void display()
{
	if(r==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	for(int i=f;i<=r;i++)
	{
		printf("%d\n",queue[i]);
	}
}



int main()
{
    int d,choice;
    int option=1;
while(option)
{
    
    printf("\nQUEUE Elements are :");
    display();
    printf("\n\nEnter choice (1:Insert,2:Display,3:Remove,0:Exit):");
    scanf("%d",&choice);
    switch(choice)
    {
        case 0:
            option=0;
            break;
        case 1:
            printf("Enter an element to insert:");
            scanf("%d",&d);
            insert(d);
            break;
        case 2:
            display();
            break;
        case 3:
            remove();
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }
 
} 
return 0;
}

