#include<iostream>
using namespace std;
int a[]={30,9,20,1,8,55,3,4};
void insert(int num,int locn)
{
	int pn;
	while(locn>0)
	{
		pn=(locn-1)/2;
		if(num>=a[pn])
		{
			a[locn]=num;
			return;
			
		}
		a[locn]=a[pn];
		locn=pn;
	}
	a[0]=num;
	
}
int main()
{
	
	int b=sizeof(a)/sizeof(a[0]);
	int n=0;
	for(int i=0;i<b;i++)
	{
		insert(a[i],n);
		n++;
	}
		for(int i=0;i<b;i++)
		{
			cout<<a[i]<<endl;
		}
	return 0;
}
