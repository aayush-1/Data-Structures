#include <iostream>

#include<cstdlib>
using namespace std;


struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;

}*root=NULL;

void insert(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
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
	    struct node *par,*temp=root;
	    while(temp!=NULL)
	    {
	    	par=temp;

			if(newnode->data < temp->data)
	    	{
	    		temp=temp->left;
	    		a=1;
			}
			else
			{
				temp=temp->right;
				a=2;
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

int succ(int value)
{
    if(root!=NULL)
    {
        struct node *temp=root;
        while(temp!=NULL)
        {


            if(temp->data==value)
            {
                break;
            }
            else if(temp->data>value)
            {

                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(temp==NULL)
        {
            cout<<"no such no.";
            return -1;

        }

        if(temp->right!=NULL)
        {

            struct node *y;
            y=temp->right;
            while(y->left!=NULL)
            {

                y=y->left;

            }
            return y->data;
        }
        else
        {

            struct node *y;
            y=temp->parent;
            while(y->data<temp->data)
            {

                if(y->parent!=NULL)
                {

                    y=y->parent;
                }
                else{
                    cout<<"no succ";
                    return 0;
                }
            }
            return y->data;
        }




    }
    else{
        cout<<"no element present";
    }

}

void display(struct node *p)
{
	if(p!=NULL)
	{

	display(p->left);
	cout<<p->data<<endl;
	display(p->right);
    }

}

void delete1(int value)
{int a;
  int succesor;
  if(root!=NULL)
    {
        struct node *temp=root;
        while(temp!=NULL)
        {


            if(temp->data==value)
            {
                break;
            }
            else if(temp->data>value)
            {

                temp=temp->left;
                a=0;
            }
            else
            {
                temp=temp->right;
                a=1;
            }
        }
        if(temp==NULL)
        {
            cout<<"no such no.";
            return ;

        }
        if(temp->left==NULL && temp->right==NULL)
        {
          struct node *par;
          par=temp->parent;
          if(a==0)
          {
            par->left=NULL;
          }
          else{
            par->right=NULL;
          }
        }
        else if(temp->left!=NULL && temp->right!=NULL)
        {
          succesor=succ(value);
          delete1(succesor);
          temp->data=succesor;




        }
        else
        {

          struct node *par=temp->parent;
          if(temp->left!=NULL)
          {
          if(a==0)
          {
            par->left=temp->left;
          }
          else{
            par->right=temp->left;
          }
        }
        if(temp->right!=NULL)
          {
          if(a==0)
          {
            par->left=temp->right;
          }
          else{
            par->right=temp->right;
          }
        }
        }

    }
    else{
        cout<<"no element present";
    }







}



int main()
{
	int choice,value,p=1,a;
	while(p)
	{
     printf("\n\n********* MENU ************\n1. Insert\n2. Display\n3.-succesor\n4-delete\n5-exit\nEnter your choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
      case 1: 	printf("Enter the value to be insert: ");
		scanf("%d",&value);
		insert(value);
		break;
	  case 2: display(root);
	  break;
	  case 3: cout<<"enter the no.\n";
                cin>>a;
               value=succ(a);
               cout<<value<<endl;
               break;
    case 4: cout<<"enter the no.\n";
                cin>>a;
                delete1(a);
                break;

	  case 5: p=0;


	}
	}
	return 0;
}



