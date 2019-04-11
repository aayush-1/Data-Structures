//head contains the msb

#include <stdio.h>
#include<stdlib.h>
int l1;
int l2;
struct node
{
	int a;
	struct node *next;
}*head1=NULL,*head2=NULL;
//insertion at end
void insert1(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=val;
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
	
}
void insert2(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=val;
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
	
}



int b=1;
//free up the whole linked list after execution of one line
void free1()
{
  struct node *temp=head1;
  struct node *temp2;
  while(temp!=NULL)
  {
    temp2=temp->next;
    free(temp);
    temp=temp2;
  }
  head1 = NULL;

}
void free2()
{
  struct node *temp=head2;
  struct node *temp2;
  while(temp!=NULL)
  {
    temp2=temp->next;
    free(temp);
    temp=temp2;
  }
  head2 = NULL;
}

//used to sanitize the input
void check1()
{
  l1=0;
struct node *temp1,*temp=head1;
while(temp!=NULL )
{
if(temp->a == 0)

{
  temp1=temp;
  temp=temp->next;
  free(temp1);

}
else
{
  break;
}

}
head1=temp;
if(head1==NULL)
{
  insert1(0);
}
while(temp!=NULL)
{
  l1++;
  temp=temp->next;
}
}
void check2()
{
  l2=0;
struct node *temp1,*temp=head2;
while(temp!=NULL )
{
if(temp->a == 0)

{
  temp1=temp;
  temp=temp->next;
  free(temp1);

}
else
{
  break;
}
}
head2=temp;
if(head2==NULL)
{
  insert2(0);
}
while(temp!=NULL)
{
  l2++;
  temp=temp->next;
}
}
//compare the no.s after sanitisation
void big()
{
  if(l1>l2)
  {
    printf("1\n");
    return;
  }
  if(l2>l1)
  {
    printf("0\n");
    return;
  }
  if(l2==l1)
  {
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL)
    {
    
    if(temp1->a > temp2->a)
    {
      printf("1\n");
      return;
    }
    else if(temp1->a < temp2->a)
    {
      printf("0\n");
      return;
    }
    else{
      temp1=temp1->next;
      temp2=temp2->next;
    }
    }
    printf("1\n");
    
  }
  
}



int main(){
  int digit;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      check1();
      check2();
      big();
      free1();
      free2();

      b=1;
    }
    else if(digit==' '){
      b=2;
    }
    else{
    if(b==1)
     {
       insert1(digit-48);
      
     }
    else
     {
      
        insert2(digit-48);
       
     }
    }
  }
  return(0);
}
