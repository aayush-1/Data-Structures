#include <iostream>
using namespace std;
void insertionsort(int a[],int n)
{
 
 for(int i=0;i<n;i++)
 {
   int value=a[i];
   int hole =i;
   
 
while(hole>0 && a[hole-1]>value)
{
  a[hole]=a[hole-1];
  hole=hole-1;
  
}
 
  a[hole]=value;
  
}
}



int main()
{
 int a[]={3,5,8,6,9,1};
  insertionsort(a,6);
  for(int i=0;i<6;i++)
  {
    cout<<a[i];
  }
  return 0;
}
