#include <iostream>
using namespace std;
void sort(int a[],int n)
{
 for(int i=0;i<n-1;i++)
 {
   
 
  int imin=i;
  for(int j=i;j<n;j++)
  {
    if(a[j]<a[imin])
    {
      imin=j;
    }
  int temp=a[i];
  a[i]=a[imin];
  a[imin]=temp;
  }
  
  
 } 
}



int main()
{
 int a[]={3,5,8,6,9,4};
  sort(a,6);
  for(int i=0;i<6;i++)
  {
    cout<<a[i];
  }
  return 0;
}
