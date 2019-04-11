//taken help from introduction to algorithms(clrs) for delete and deletefix functions

#include <iostream>
#include<cstdlib>
using namespace std;

//RB tree
struct node
{
	int data;
    char colour;
	struct node *left;
	struct node *right;
	struct node *parent;

}*nill,*root=nill;

struct path
{
	int a;
	struct path *next;
};
struct path *head=NULL;

//display the path in search	
void dip()
{
	struct path *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->a;
		temp=temp->next;
	}
}
//delete the path in search

void del()
{
	struct path *temp=head,*temp2;
	while(temp!=NULL)
	{
		temp2=temp->next;
		free(temp);
		temp=temp2;
	}
	head=NULL;

}

//insert in path struct to create the path for search function
void insert1(int value)
{
	struct path *newnode;
	newnode=new struct path;
	newnode->a=value;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct path *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}


//left rotate at node->data=value
void leftrotate(int value)
{  
  struct node *x;
   
        if(root!=nill){
        struct node *temp=root;
        while(temp!=nill)
        {


            if(temp->data==value)
            { 
              x = temp;
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
        if(temp==nill)
        {
            return ;
            
        }
        }


  struct node *y=x->right;
  x->right=y->left;
  if(y->left!=nill)
  {
    y->left->parent=x;
  }
  y->parent=x->parent;
  if(x->parent==NULL)
  {
    root=y;
  }
  else
  {
    if(x==(x->parent)->left)
    {
      x->parent->left=y;
    }
    else
    {
      x->parent->right=y;
    }

  }
 
  y->left=x;
  x->parent=y;
}

//right rotate at node->data=value
void rightrotate(int value)
{  
  struct node *y;
    if(root!=nill)
    {
        
        struct node *temp=root;
        while(temp!=nill)
        {


            if(temp->data==value)
            { 
              y = temp;
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
        if(temp==nill)
        {
            return ;
            
        }
    }

  struct node *x=y->left;
  y->left=x->right;
  if(x->right!=nill)
  {
    x->right->parent=y;
  }
  x->parent=y->parent;
  if(y->parent==NULL)
  {
    root=x;
  }
  else
  {
    if(y==(y->parent)->left)
    {
      y->parent->left=x;
    }
    else
    {
      y->parent->right=x;
    }

  }
 
  x->right=y;
  y->parent=x;
}

//display the RB tree
void display(struct node *p)
{
	if(p!=nill)
	{
	cout<<p->data<<" ";
	display(p->left);
	display(p->right);
  
    }

}

//insert in the tree
void insert(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	int a;
  	newnode->colour='R';
	if(root==nill)
	{
    	struct node *newnode1;
		newnode1=(struct node*)malloc(sizeof(struct node));
    	newnode1->colour='B';
    	nill=newnode1;
		root=newnode;
		root->right=nill;
		root->left=nill;
		root->parent=NULL;


	}
	else
	{
	    struct node *par,*temp=root;
	    while(temp!=nill)
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
        temp->left=nill;
        temp->right=nill;
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

//fix the insert in the rb tree
void fixinsert(struct node *Z)
{
  if(root==Z)
  {
    Z->colour='B';
    return;
  }

  while(Z->parent!=NULL && Z->parent->parent!=NULL && Z->parent->colour=='R')
  {
    struct node *U=Z->parent->parent;
    
    if(U->left==Z->parent)
    {
      if(U->right!=nill)
      {
          Z->parent->colour='B';
          U->right->colour='B';
          U->colour='R';
          Z=U;      
          
        }
        else
        {
          if(Z->parent->right==Z)
          {
            Z=Z->parent;
            leftrotate(Z->data);
          }
          Z->parent->colour='B';
          U->colour='R';
          rightrotate(U->data);
        }
    }
    else if(U->right==Z->parent)
    {

        if(U->left->colour=='R')
        {
          Z->parent->colour='B';
          U->left->colour='B';
          U->colour='R';
          Z=U;
          
        }        
      else
        {
          if(Z->parent->left==Z)
          {
            Z=Z->parent;
            rightrotate(Z->data);
          }
          
          Z->parent->colour='B';
          U->colour='R';
          leftrotate(U->data);

        }
    }
    root->colour='B';
	}
}

//just calls insert and fixinsert functions
void rbinsert(int val)
{
 insert(val);

 if(root!=nill)
    {
        struct node *temp=root;
        while(temp!=nill)
        {


            if(temp->data==val)
            {
                break;
            }
            else if(temp->data>val)
            {

                temp=temp->left;
                
            }
            else
            {
                temp=temp->right;
                
            }
        }
  

  fixinsert(temp);
}
}


//successor of the function
struct node *succ(int value,int x=0)
{
	int a;
	int b=x;
	int c=0;
    if(root!=nill)
    {
        struct node *temp=root,*temp2;
        while(temp!=nill)
        {


            if(temp->data==value)
            {
                break;
            }
            else if(temp->data>value)
            {
            	temp2=temp;
            	a=0;
            	c=1;
                temp=temp->left;
            }
            else
            {
            	temp2=temp;
            	a=1;
                temp=temp->right;
            }
        }
        if(temp!=nill)
        {
	        if(temp->right!=nill)
	        {

	            struct node *y;
	            y=temp->right;
	            while(y->left!=nill)
	            {

	                y=y->left;

	            }
	            if(b==0)
	            	cout<<y->data<<endl;
	            return y;
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
	                	if(b==0)
	                    	cout<<"-1"<<endl;
	                    return NULL;
	                }
	            }
	            if(b==0)	
	            	cout<<y->data<<endl;
	            return y;
	        }
    	}
    	else
    	{
    		if(a==0)
      		{
      			if(b==0)
      				cout<<temp2->data<<endl;
      			return temp2;
      		}
		    else if(a==1)
		    {
		    	if(c==0)
		    	{
		    		cout<<"-1"<<endl;
		    		return NULL;
		    	}

		        return succ(temp2->data,b);
		    }
    	}

    }
    else
    {
    	if(b==0)
        	cout<<"-1"<<endl;
        return NULL;
    }

}

//search a particular value


void search(int val)
{
  struct node *temp=root;
	    while(temp!=nill)
	    {
	    	

			if(val<temp->data)
	    	{
	    		temp=temp->left;
	    		insert1(0);
			}
			else if(val>temp->data)
			{
				temp=temp->right;
				insert1(1);
			}
		    else if(val==temp->data)
		    {
		        dip(); 
		        cout<<" "<<temp->colour<<endl;
		        return;
		    }

		}
printf("-1\n");

}

//delfix after deleting a particular value(taken help from clrs)

void delfix(struct node *x)
{
	struct node *w;
	while(x!=root && x->colour=='B')
	{
		if(x==x->parent->left)
		{
			w=x->parent->right;
			if(w->colour=='R')
			{
				w->colour='B';
				x->parent->colour='R';
				leftrotate(x->parent->data);
				w=x->parent->right;
			}
			if(w->left->colour=='B' && w->right->colour=='B')
			{
				w->colour='R';
				x=x->parent;
			}
			else
			{
				if(w->right->colour=='B')
				{
					w->left->colour='B';
					w->colour='R';
					rightrotate(w->data);
					w=x->parent->right;
				}
				w->colour=x->parent->colour;
				x->parent->colour='B';
				w->right->colour='B';
				leftrotate(x->parent->data);
				x=root;
			}

		}
		else
		{
			w=x->parent->left;
			if(w->colour=='R')
			{
				w->colour='B';
				x->parent->colour='R';
				rightrotate(x->parent->data);
				w=x->parent->left;
			}
			if(w->right->colour=='B' && w->left->colour=='B')
			{
				w->colour='R';
				x=x->parent;
			}
			else
			{
				if(w->left->colour=='B')
				{
					w->right->colour='B';
					w->colour='R';
					leftrotate(w->data);
					w=x->parent->left;
				}
				w->colour=x->parent->colour;
				x->parent->colour='B';
				w->left->colour='B';
				rightrotate(x->parent->data);
				x=root;
			}

		}
	}
	x->colour='B';
}



//to delete a particular no. from the tree(taken help from clrs)
void rbdelete(int val)
{
	struct node *z=root;
        while(z!=nill)
        {


            if(z->data==val)
            {
                break;
            }
            else if(z->data>val)
            {
                z=z->left;
            }
            else
            {
                z=z->right;
            }
        }
        if(z==nill)
        {
        	cout<<"-1"<<endl;
        	return;
        }
    struct node *y=z,*x;
    char yoriginal=y->colour;

    if(z->left==nill)
    {
    	x=z->right;
    	if(z==root)
    		root=z->right;
    	else if(z==z->parent->left)
    		z->parent->left=z->right;   
    	else if(z==z->parent->right)
    		z->parent->right=z->right;
    	z->right->parent=z->parent;
    }

    else if(z->right==nill)
    {
    	x=z->left;
    	if(z==root)
    		root=z->left;
    	else if(z==z->parent->left)
    		z->parent->left=z->left;   
    	else if(z==z->parent->right)
    		z->parent->right=z->left;
    	z->left->parent=z->parent;
    }
    

    else
    {
    	y=succ(z->data,1);
    	yoriginal=y->colour;
    	x=y->right;
    	if(y->parent==z)
    	{
    		x->parent=y;
    	}    	
    	else
    	{
    		if(y==root)
    			root=y->right;
    		else if(y==y->parent->left)
    			y->parent->left=y->right;   
    		else if(y==y->parent->right)
    		{
    			y->parent->right=y->right;	    		
	    	}
	    	y->right->parent=y->parent;
	    	y->right=z->right;
	    	y->right->parent=y;	    	
    	}
    	if(z==root)
    	{
	    	root=y;
    	}
	    else if(z==z->parent->left)
	    	z->parent->left=y;   
	    else if(z==z->parent->right)
	    	z->parent->right=y;
	    y->parent=z->parent;
	    y->left=z->left;
	    y->left->parent=y;
	    y->colour=z->colour;
    }
    if(yoriginal=='B')
	    delfix(x);
	free(z);
}


//delete the whole bst

void deleteall(struct node *A)
{
  struct node *temp=A;
  if(temp!=nill)
  {
    deleteall(temp->left);
    deleteall(temp->right);
    free(temp);
  }
}

//find the child of the given values
void child(int value)
{
	if(root!=nill)
    {
        struct node *temp=root;
        while(temp!=nill)
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
        if(temp==nill)
        {
        	cout<<"-1"<<endl;
        	return;
        }
        if(temp->left!=nill)
        	cout<<temp->left->data<<" "<<temp->left->colour<<" ";
        else
        	cout<<"L B ";
        if(temp->right!=nill)
        	cout<<temp->right->data<<" "<<temp->right->colour<<endl;
        else
        	cout<<"L B"<<endl;
}
}

int main(int argc, char const *argv[])
{
	int digit;
  	int value=0;
  	while((digit=fgetc(stdin))!=EOF){
	  	if(digit=='N'){
	  		deleteall(root);
	  		root=nill;
	  		int a=0;
		  	while((digit=fgetc(stdin))!=EOF){

			    if(digit=='\n'){
			    	rbinsert(value);
			    	value=0;
			        break;     
			    }
			    else if(digit==' '){
			    	if(a==0)
			    	{
			    		a=1;
			    		value=0;
			    	}
			    	else
			    	{
			    		rbinsert(value);
			        	value=0;
			        }      
			    }
			    else{
			      value=value*10+digit-48;    
			    }
		    
		  	}
	    }


  else if(digit=='P'){
  //put a \n in the end in display of bst.
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){

    display(root);
    cout<<endl;
    break;
  }
     else if(digit==' '){
     value=0;      
    }
    else
    {
    	value=value*10+digit-48;    	
    }
    
  }
}
 
 else if(digit=='+'){
    int y=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
    	rbinsert(value);
      break;    
    }
    else if(digit==' '){
     value=0;      
    }
    else
    {
    	value=value*10+digit-48;    	
    }
    
  }
  }

   else if(digit=='>'){
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      succ(value);	
      break;     
    }
    else if(digit==' '){
    	value=0;
      
    }
    else{
      value=value*10+digit-48;
       
    }
    
  }
  }

    else if(digit=='C'){
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      child(value);
      break;       
    }
    else if(digit==' '){
    	value=0;
      
    }
    else{
    	value=value*10+digit-48;
       
    }
    
  }
  }

      else if(digit=='S'){
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      search(value);
      del();
      break;       
    }
    else if(digit==' '){
    	value=0;
      
    }
    else{
    	value=value*10+digit-48;
       
    }
    
  }
  }


     else if(digit=='-'){
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      rbdelete(value);
      break;       
    }
    else if(digit==' '){
    	value=0;
      
    }
    else{
    	value=value*10+digit-48;
       
    }
    
  }
  }

}
return 0;
}