//head stores the lsb as i am inserting every input in the starting of the linked list and denoting it as head.

#include <stdio.h>
#include<stdlib.h>
struct node
{
  int a;
  struct node *next;
  

}*head1=NULL,*head2=NULL,*head3=NULL;
//saving lsb first
void insertinbegining1(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=val;
    if(head1==NULL)
	{
		newnode->next=NULL;
		head1=newnode;
		
	}
	else
	{
		newnode->next=head1;
		head1=newnode;
	}
}

void insertinbegining2(int val)
{

	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=val;
    if(head2==NULL)
	{
		newnode->next=NULL;
		head2=newnode;
		
	}
	else
	{
		newnode->next=head2;
		head2=newnode;
	}
}
  void insertinbegining3(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=val;
    if(head3==NULL)
	{
		newnode->next=NULL;
		head3=newnode;
		
	}
	else
	{
		newnode->next=head3;
		head3=newnode;
	}
	
	
}

void display3()
{
  int z=1;
   if(head3 == NULL || head2==NULL || head1==NULL)
   {
      printf("\nanswer not defined\n");
   }
   else
   {
      struct node *temp = head3;
      printf("\n");
      while(temp->next != NULL)
      {
        if(temp->a == 0)
        {
          if(z==0)
          {
            printf("%d",temp->a);
	          temp = temp->next;
          }
          else{
            
            temp=temp->next;

          }
        }
        else{
	      printf("%d",temp->a);
	      temp = temp->next;
        z=0;
      }
      }
      printf("%d\n",temp->a);
   }
}



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
void free3()
{
  struct node *temp=head3;
  struct node *temp3;
  while(temp!=NULL)
  {
    temp3=temp->next;
    free(temp);
    temp=temp3;
  }
  head3 = NULL;
}

void sum()
{
struct node *temp1=head1;
struct node *temp2=head2;
int s,i,c=0;
while(temp1!=NULL && temp2!=NULL)
{

  i=(temp1->a) + (temp2->a) + c;
  if(i>=10)
  {
  s=i%10;
  c=i/10;
  }
  else if(i<10)
  {
    s=i;
    c=0;

  }
  insertinbegining3(s);
  temp1=temp1->next;
  temp2=temp2->next;

}
while(temp1!=NULL)
{
i=temp1->a + c;
  if(i>=10)
  {
  s=i%10;
  c=i/10;
  }
  else if(i<10)
  {
    s=i;
    c=0;
  }
  insertinbegining3(s);
  temp1=temp1->next;
}
while(temp2!=NULL)
{
i=temp2->a + c;
  if(i>=10)
  {
  s=i%10;
  c=i/10;
  }
  else if(i<10)
  {
    s=i;
    c=0;
  }
  insertinbegining3(s);
  temp2=temp2->next;
}
if(c!=0)
insertinbegining3(c);

}


int b=1;



int main()
{
  
  int digit;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
     sum();
     display3();
     free1();
     free2();
     free3();
     
     b=1;
     //free the two linked lists 
     
    }
    else if(digit==' '){
      b=2;
    }
    else{
     if(b==1)
     {
       insertinbegining1(digit-48);
      
     }
     else
     {
      
        insertinbegining2(digit-48);
       
     }
    }
  }
  return(0);
}
