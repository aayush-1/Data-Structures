#include <stdio.h>
#include<stdlib.h>
int check();
void freee();

int l1;
int l2;

struct BST
{
	struct node *pointer;
	struct BST *left;
	struct BST *right;
	struct BST *parent;

}*root=NULL;



struct node
{
	int a;
  
	struct node *next;
}*head=NULL,*head1=NULL;

//inserting the no. in the linked list
void insertdigit(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=val;
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
  }

//sanitize the input
int check()
{
  
struct node *temp1,*temp=head;
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
head=temp;
if(head==NULL)
{
  struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->a=0;
	newnode->next=NULL;
  head=newnode;
  
}
}

int compare(struct node *A,struct node *B)
{ 
  l1=0;
  struct node *tempa=A;
while(tempa!=NULL)
{
  l1++;
  tempa=tempa->next;
}

l2=0;
struct node *tempb=B;

while(tempb!=NULL)
{
  l2++;
  tempb=tempb->next;
}
  if(l1>l2)
  {
    
    return 1;
  }
  if(l2>l1)
  {
  
    return 0;
  }
  if(l2==l1)
  {
    struct node *temp1=A;
    struct node *temp2=B;
    while(temp1!=NULL)
    {
    
    if(temp1->a > temp2->a)
    {
      return 1;
    }
    else if(temp1->a < temp2->a)
    {
      return 0;
    }
    else{
      temp1=temp1->next;
      temp2=temp2->next;
    }
    }
     return 2;
  }
 

}

//delete the whole bst with numbers stored as linked list in it
void deletebst(struct BST *root)
{
  struct BST *temp=root;
  if(temp!=NULL)
  {
    deletebst(temp->left);
    deletebst(temp->right);
    freee(temp->pointer);
    temp->pointer=NULL;
    
   free(temp);
  }
  root=NULL;
}

//insert the linked list of numbers entered in the binary search tree
void insertbst()
{
	struct BST *newnode;
	newnode=(struct BST*)malloc(sizeof(struct BST));
	newnode->pointer=head;
	int a;
	if(root==NULL)
	{
		root=newnode;
		root->right=NULL;
		root->left=NULL;
		root->parent=NULL;


	}
	else
	{
	    struct BST *par,*temp=root;
	    while(temp!=NULL)
	    {
	    	par=temp;

			if(compare(newnode->pointer,temp->pointer)==0)//newnode->data < temp->data
	    	{
	    		temp=temp->left;
	    		a=1;
			}
			else if(compare(newnode->pointer,temp->pointer)==1)
			{
				temp=temp->right;
				a=2;
			}
      else if(compare(newnode->pointer,temp->pointer)==2)
      {
        return;
      }

	    }
        temp=newnode;
        temp->left=NULL;
        temp->right=NULL;
    if(a==1)
    {
      par->left=temp;
		}
		if(a==2)
		{
			par->right=temp;
		}
		temp->parent=par;

    }
  

}
int z;

//display the binary search tree
void display(struct BST *root)//preorder traversal
{
   if(root != NULL){
     z=0;
     struct node *temp = root->pointer;
     while(temp!=NULL)
     {
   	  printf("%d",temp->a);
       temp=temp->next;
       z=1;
     }
     if(z==1)
     {
       printf(" ");
     }
     display(root->left);
     display(root->right);
   }
}

//delete the number enter while checking the position of that no. in bst
void freee(struct node *A)
{
  struct node *temp=A;
  struct node *temp2;
  while(temp!=NULL)
  {
    temp2=temp->next;
	free(temp);
    temp=temp2;
  }
  A= NULL;

}

//insert the position of the number entered in the bst
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

//displays the position of no. entered in bst
void display1(struct node *A)
{
   if(A == NULL)
   {
      printf("\n");
   }
   else
   {
      struct node *temp = A;
      while(temp->next != NULL)
      {
	 printf("%d",temp->a);
	 temp = temp->next;
      }
      printf("%d\n",temp->a);
   }
}

//free the linked list containing the position of the no. asked to be searched in the linked list
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

//search the no. in the linked list
void search()
{
  struct BST *temp=root;
	    while(temp!=NULL)
	    {
	    	

			if(compare(head,temp->pointer)==0)
	    	{
	    		temp=temp->left;
	    		insert1(0);
			}
			else if(compare(head,temp->pointer)==1)
			{
				temp=temp->right;
				insert1(1);
			}
      else if(compare(head,temp->pointer)==2)
      {
        display1(head1);
        
        return;
      }

}
printf("-1\n");

}



int main(){
  int digit;
  while((digit=fgetc(stdin))!=EOF){
  if(digit=='N'){
    int x=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      //display(root);
      check();
      insertbst();
      head=NULL;
      

      break;

     
    }
    else if(digit==' '){
      if(x==0)
      {
        deletebst(root);
        root=NULL;
        //free all BST
        x=1;
      }
      else if(x==1)
      {
        //compare and insert linked list in BST simultaneously
        check();
        insertbst();
        head=NULL;
        //put head = NULL

      }
      
    }
    else{
      //insert digits in linked list
      insertdigit(digit-48);
      //check too 
    }
    
  }
  }

  else if(digit=='S'){
    int y=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      check();
      search();
      freee(head);
      head=NULL;
      free1();
      //compare with bst and print ans 
      //free linked list of digits
      break;
      

     
    }
    else if(digit==' '){
     y=1;
      
    }
    else{
      //insert digits in linked list 
      insertdigit(digit-48);
      //check too
       
    }
    
  }
  }

  else if(digit=='P'){
  //put a \n in the end in display of bst.
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
    display(root);
    printf("\n");
    break;
  }
  }
  }
 }
    //delete bst again
	deletebst(root);
    root=NULL;
 
  return(0);
}

