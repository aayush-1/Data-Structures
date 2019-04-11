#include <iostream>
using namespace std;
void bubblesort(int a[],int n)
{
  for(int k=1;k<=n-1;k++)
{
 for(int i=0;i<n-2;i++)
 {
   
 

 
  
    if(a[i]<a[i+1])
    {
      int temp=a[i+1];
      a[i+1]=a[i];
      a[i]=temp;
    }
  
  
  
 } 
}
}



int main()
{
 int a[]={3,5,8,6,9,4};
  bubblesort(a,6);
  for(int i=0;i<6;i++)
  {
    cout<<a[i];
  }
  return 0;
}
