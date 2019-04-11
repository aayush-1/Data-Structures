#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
   int data=0;
   struct node *next=NULL;
};

struct node *head1=NULL,*head2=NULL;
struct node *vertex;

int queue[100];
int f=0;
int r=-1;
int N;
int checkit=0;
//inserting in queue
void enqueue(int a)
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
//deletion from queue
int dequeue()
{
  int c;
  if(f>r)
  {
    f=0;
    r=-1; 
    return 0; 
  }
  else if(f==r)
  {
    c=queue[f];
    r=r-1;
    return c;
  }
  else
  {
    c=queue[f];
    f++;
    return c;
  }
}

//used in breadth first search

void insertvisited(int val)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=val;
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



//inserion in graph
void insert(int val,int a)
{

  if(vertex[a].data==0)
  {
    vertex[a].data=val;
    vertex[a].next=NULL;
    
  }
  else
  {  
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    
    if(vertex[a].next==NULL)
    {
      vertex[a].next=newnode;
    }
    else
    {
    	struct node *temp=vertex[a].next;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=newnode;
    }

  }
}


//check whether 2 nodes of a graph are connected or not
void check(int value1,int value2)
{
	if(vertex[value1].data==value2)
	{
		cout<<"1\n";
		return;
	}

  struct node *temp=vertex[value1].next;
    if(vertex[value1].next==NULL)
    {
      return;
    }
    while(temp!=NULL)
    {
      if(temp->data==value2)
      {
        cout<<"1\n";
        return;
      }
      temp=temp->next;
    }
    cout<<"0\n";
}

//used in bfs function to compare digit and insertvisited linked list
int comparell(int a)
{
  struct node *temp1=head1;
  while(temp1!=NULL)
  {
    if(temp1->data==a)
    {
      return 1;
    }
    temp1=temp1->next;
  }
  return 0;

}
//used in bfs to search for a no. in queue
int comparequeue(int a)
{
  for(int i=f;i<=r;i++)
  {
    if(queue[i]==a)
    {
      return 1;
    }
  
  }
  return 0;
}
 

 //breadth first search
void BFS(int val)
{   
  int a,b;
  insertvisited(val);
  struct node *temp=vertex[val].next;
  while(temp!=NULL)
  {
    a=comparell(temp->data);
    b=comparequeue(temp->data);
    if(a==0 && b==0)
    { 
      cout<<temp->data<<" ";
      enqueue(temp->data);
      
    }
    temp=temp->next;
  }

  int num=dequeue();
  while(num!=0)
  {
    BFS(num);
    num=dequeue();
  }
}

//used to find shortest path

int BFS1(int val,int pathval)
{  
  int retval;
  int a,b;
  insertvisited(val);
  struct node *temp=vertex[val].next;
  int parent=vertex[val].data;
  while(temp!=NULL)
  {
    a=comparell(temp->data);
    b=comparequeue(temp->data);

    if(a==0 && b==0)
    { 
      enqueue(temp->data);
    }

    if(temp->data==pathval)
      {
      	return parent;
      }
      temp=temp->next;
    }
     
  int num=dequeue();
  while(num!=0)
  {

   retval=BFS1(num,pathval);
  if(retval!=-1)
  {
  	return retval;
  }
    num=dequeue();
  }
 return -1;
 
}


//delete the linked list
void del()
{
  struct node *temp=head1,*temp1;
  while(temp!=NULL)
  {
    temp1=temp->next;
    free(temp);
    temp=temp1;
  }
  head1=NULL;
}


//delete the whole graph after one iteration
void delgraph(struct node *arr)
{
  for(int i=1;i<=N;i++)
  {
    struct node *temp=arr[i].next;
    struct node *temp1;
    while(temp->next!=NULL)
    {
      temp1=temp;
      free(temp1->next);
      temp=temp->next;
    }
	}

}

//computes the shortest path

int shortestpath(int source,int dest)
{
	int a;
	if(source==dest)
	{
		return 0;
	}
	else
	{
	   a=BFS1(source,dest);
	   del();
	   f=0;r=-1;
	   if(a==-1)
	   {
	   	cout<<"-1";
	   	return -1;
	   }

	   shortestpath(source,a);
	   cout<<a<<" ";
	   return 0;


	}

}

int main()
{
  int digit;
  int value=0;
  int a;
  int c=0;
  
  while((digit=fgetc(stdin))!=EOF){
  if(digit=='N'){
  	//delete old whole linked list
    	if(c==0)
    	{
    		c=0;
    	}
    	else if(c==1)
    	{
    		delgraph(vertex);
    	}

  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      vertex=(struct node*)malloc(sizeof(struct node)*(value+1));
      N=value+1;
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

  

  else if(digit=='E'){
    int x=0;
    int y=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      insert(value,a);
      value=0;
      break;     
    }
    else if(digit==' '){
      if(x==0)
      {

        value=0;
        x=1;
      }
      else if(x==1)
      {
        insert(value,a);
        value=0;
        y=1;

      }
      
    }
    else{
      if(y==0)
      {
        value=value*10+digit-48;
        a=value;
        
        }
        else if(y==1)
        {
          value=value*10+digit-48;

        }
    }
    
  }
  }

  else if(digit=='?'){
    int value1=0;
    int value2=0;
    int y=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      check(value1,value2);
        break;     
    }
    else if(digit==' '){
      if(y==0)
      {
        y=1;
      }
      else if(y==1)
      {
        y=2;
      }
          
    }
    else{
      if(y==1)
          value1=value1*10+digit-48;
        else if(y==2)
          value2=value2*10+digit-48;   
    }
    
  }
  }

  else if(digit=='B')
  { 
    while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      cout<<value<<" ";
      BFS(value);
      value=0;
      cout<<"\n";
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

  else if(digit=='P')
  {
  	int value1=0,value2=0;
  	int y=0;
  	while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
    	int p=shortestpath(value1,value2);
    	if(p==0)
    	{
    		cout<<value2;
    	}
    	cout<<"\n";
    	del();
        break;     
    }
    else if(digit==' '){
      if(y==0)
      {
        y=1;
      }
      else if(y==1)
      {
        y=2;
      }
          
    }
    else{
      if(y==1)
          value1=value1*10+digit-48;
       else if(y==2)
          value2=value2*10+digit-48;   
    }
    
  }

  }




  }
  return 0;
      
    
}
