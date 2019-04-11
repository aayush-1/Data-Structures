#include<stdio.h>
struct node
{
	float cgpa;
	node *next;
	
};
node *first,*last,*x;
int main()
{
	int n,i;
	printf("\nenter size of list");
	scanf("%d",&n);
	first=new node;
	printf("\nenter cgpa");
	scanf("%f",&first->cgpa);
	first->next=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
	x=new node;
	printf("\nenter cgpa");
	scanf("%f",&x->cgpa);
	
	x->next=NULL;
	last->next=x;
	last=x;
    }
    
    	printf("\nthe list is");
	last=first;
	int j=0;
	while(last!=NULL)
	{
		printf("\nthe cgpa is %f",last->cgpa);
		printf("\nthe index is %f",j);
		printf("\nthe address is %p",last);
		last=last->next;
		printf("\nthe pointer stored in node %p\n",last);
		j++;
	}
	delete first;
	return 0;
}



