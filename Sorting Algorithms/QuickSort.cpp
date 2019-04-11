#include<iostream>
using namespace std;
void quicksort(int a[],int f,int l)
{
	int i ,j,pivot,temp;
	if(f<l)
	{
		pivot=f;
		i=f;
		j=l;
		
		while(i<j)
		{
			while(a[i]<a[pivot] && i<l)
			{
				i++;
				
			}
			while(a[j]>a[pivot])
			{
				j--;
				
			}
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,f,j-1);
		quicksort(a,j+1,l);
		
	    	
	}
}



int main()
{
	int a[25];
	int b;
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,b-1);
		for(int i=0;i<b;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
