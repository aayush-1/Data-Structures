#include<iostream>
#include<cstdlib>
using namespace std;


//used to store the visited nodes in the djik function

struct visited
{
  int verte;
  int weigh;
  struct visited *next;

}*head=NULL;
//used to store the graph
struct node
{
   int data=0;
   int weight=0;
   struct node *next=NULL;
};
struct node *vertex;


int N;


int ptr=0;
int minhv[100];
int minhw[100];

//insertion in heap

void insert1(int num,int vertex)
{
  int pn;
  int locn=ptr;
  while(locn>0)
  {
    pn=(locn-1)/2;
    if(num>=minhw[pn])
    {
      minhw[locn]=num;
      minhv[locn]=vertex;
      ptr++;
      return;
      
    }
    minhw[locn]=minhw[pn];
    minhv[locn]=minhv[pn];
    locn=pn;
  }
  minhw[0]=num;
  minhv[0]=vertex;
  ptr++;
 
}

//used to delete any desired no. from heap

void deletee(int s)
{
  int temp;
  int p;
  for(int i=0;i<ptr;i++)
  {
    if(minhv[i]==s)
    {
        p=i;                                
    }
  }
  if(s==0)
  {
    p=0;
  }
  minhw[p]=minhw[ptr-1];
  minhv[p]=minhv[ptr-1];
  minhw[ptr-1]=10000;
  ptr--;

  while(minhw[p]>minhw[2*p+1] || minhw[p]>minhw[2*p+2])
  {
  if(minhw[p]>minhw[2*p+1])
  {
    if(minhw[2*p+1]<minhw[2*p+2])
    {
      temp=minhw[2*p+1];
      minhw[2*p+1]=minhw[p];
      minhw[p]=temp;
      temp=minhv[2*p+1];
      minhv[2*p+1]=minhv[p];
      minhv[p]=temp;
      p=2*p+1;
    }
    else
    {
      temp=minhw[2*p+2];
      minhw[2*p+2]=minhw[p];
      minhw[p]=temp;
      temp=minhv[2*p+2];
      minhv[2*p+2]=minhv[p];
      minhv[p]=temp;
      p=2*p+2;
    }
  }
  else if(minhw[p]>minhw[2*p+2])
  {
    temp=minhw[2*p+2];
    minhw[2*p+2]=minhw[p];
    minhw[p]=temp;
    temp=minhv[2*p+2];
    minhv[2*p+2]=minhv[p];
    minhv[p]=temp;
    p=2*p+2;
  }
  }
}

//used to update weight in the graph

void weight(int val,int a)
{
  if(vertex[a].next==NULL)
  {
    vertex[a].next->weight=val;
  }
  else
  {
    struct node *temp=vertex[a].next;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->weight=val;
  }

}



//insertion in graph
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

void insertvisited(int val,int weight)
{
  struct visited *newnode;
  newnode=(struct visited*)malloc(sizeof(struct visited));
  newnode->verte=val;
  newnode->weigh=weight;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
    struct visited *temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newnode;
  }
}
//delete the linked list 
void del()
{
  struct visited *temp=head,*temp1;
  while(temp!=NULL)
  {
    temp1=temp->next;
    free(temp);
    temp=temp1;
  }
  head=NULL;
}


//check whether 2 nodes of a graph are connected or not
int check(int value1,int value2)
{
    if(vertex[value1].data==value2)
    {
        return -1;
    }

  struct node *temp=vertex[value1].next;
    if(vertex[value1].next==NULL)
    {
      return -1;
    }
    while(temp!=NULL)
    {
      if(temp->data==value2)
      {
        return temp->weight;
      }
      temp=temp->next;
    }
    return -1;
}

//compare the visited linked list and the nodes
int comparell(int a)
{
  struct visited *temp1=head;
  while(temp1!=NULL)
  {
    if(temp1->verte==a)
    {
      return 1;
    }
    temp1=temp1->next;
  }
  return 0;

}

//display the output of djik fn stored in the visited linked list

void display()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct visited *temp = head;
      while(temp->next != NULL)
      {
   printf("%d %d\n",temp->verte,temp->weigh);
   temp = temp->next;
      }
      printf("%d %d\n",temp->verte,temp->weigh);
   }
}

int checkminheap(int v)
{
    for(int i=0;i<ptr;i++)
    {
      if(minhv[i]==v)
      {
        return i;
      }
    }
    return -1;
}

//djikstras algo
void djik(int source,int w)
{
  int a,b,i;
  insertvisited(source,w);
  struct node *temp=vertex[source].next;
  while(temp!=NULL)
  {
    a=comparell(temp->data);
    b=checkminheap(temp->data);


    if(a==0)
    {
      if(b==-1)
      {
        insert1(temp->weight+w,temp->data);
      }
      else
      {
        if(temp->weight+w<minhw[b])
        {
          deletee(temp->data);
          insert1(temp->weight+w,temp->data);
        }
      }

    }
    temp=temp->next;
  }
  while(ptr!=0)
  {
    int m=minhv[0];
    int n=minhw[0];
    deletee(0);
    djik(m,n);
  }
}

//used to find shortest path

int parent=-1;
int djik1(int source,int w,int dest)
{
  int a,b,i;
  insertvisited(source,w);

  struct node *temp=vertex[source].next;
  while(temp!=NULL)
  {
    a=comparell(temp->data);
    b=checkminheap(temp->data);


    if(a==0)
    {
      if(b==-1)
      {
        insert1(temp->weight+w,temp->data);
        if(temp->data==dest)
        {
          parent=vertex[source].data;
        }
      }
      else
      {
        if(temp->weight+w<minhw[b])
        {
          deletee(temp->data);
          insert1(temp->weight+w,temp->data);
          if(temp->data==dest)
          {
            parent=vertex[source].data;
          }

        }
      }



    }
    temp=temp->next;
  }
  while(ptr!=0)
  {
    int m=minhv[0];
    if(m==dest)
    {
      return parent;
    }
    int n=minhw[0];
    deletee(0);
    parent=djik1(m,n,dest);
    if(parent!=-1)
    {
      return parent;
    }
  }

}

//shortest path algo
int shortestpath(int source,int destination)
{
  int a=0;
  if(source==destination)
  {
    return 0;
  }
  else
  {
    int b=djik1(source,0,destination);
     del();
    for(int i=0;i<ptr;i++)
    {
      minhw[i]=10000;
    }
    ptr=0;
    parent=-1;

    if(b==a)
    {

      return -1;
    }
    else
    {
      shortestpath(source,b);
      cout<<b<<" ";
      return 0;

    }

  }
 }

//delete the whole graph after one iteration
void delgraph()
{
  for(int i=0;i<N;i++)
  {
    struct node *temp=vertex[i].next;
    struct node *temp1;
    while(temp!=NULL)
    {
      temp1=temp;
      free(temp1->next);
      temp=temp->next;
    }
    }

}



int main()
{
  int digit;
  int value=0;
  int a;
  int c=0;

  for(int i=0;i<100;i++)
  {
    minhw[i]=10000;
  }
 
  while((digit=fgetc(stdin))!=EOF){
  if(digit=='N'){
      //delete old whole linked list
        if(c==0)
        {
            c=1;
        }
        else if(c==1)
        {
            delgraph();
        }

  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      vertex=(struct node*)malloc(sizeof(struct node)*(value+1));
      N=value+1;
      for(int i=0;i<N;i++)
      {
      	vertex[i+1].data=i+1;
      }
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
    int z=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      weight(value,a);
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
        if(z==0)
        {
          x=1;
          z=1;
        }
        else if(z==1)
        {
          x=2;
        }

      }
      else if(x==2)
      {
        x=1;
        weight(value,a);
        value=0;
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
    int x;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      x=check(value1,value2);
      cout<<x<<endl;  
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

  else if(digit=='P')
  {
      int value1=0,value2=0;
      int y=0;
      while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      int b=-1;
      djik(value1,0);
      struct visited *temp=head;
    while(temp!=NULL)
    {
      if(temp->verte==value2)
      {
      b=temp->weigh;
      break;
      }
      temp=temp->next;
    } 
    del();
    for(int i=0;i<ptr;i++)
    {
      minhw[i]=10000;
    }
    ptr=0;
    if(b!=-1)
    {
      cout<<b<<" ";
      shortestpath(value1,value2);
      cout<<value2<<endl;
    }
    else
    {
      cout<<b<<endl;
    }
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

  else if(digit=='D')
  {
    while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      djik(value,0);
      display();
      for(int i=0;i<N-1;i++)
      {
      	int a=0;
      struct visited *t=head;
      while(t!=NULL)
      {
      	if(t->verte==vertex[i+1].data)
      	{
      		a=1;
      	}
      	t=t->next;
      }
      if(a==0)
      {
      	cout<<vertex[i+1].data<<" -1"<<endl;
      }
  	  }
      del();
      for(int i=0;i<ptr;i++)
      {
        minhw[i]=10000;
      }
      ptr=0;
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
      
    

