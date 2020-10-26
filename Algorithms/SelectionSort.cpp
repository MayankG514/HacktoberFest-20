#include<iostream>
using namespace std;

//Swap function
void swap(int* a,int* b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

void SelectionSort(int a[],int n)
{
	int i,j;
	int min; //index of smallest element
	
	//finding smallest element and swap with 0th index then find next smallest element in remaining (n-1) elements and swap with 1st index and so on..
	
	for(i=0;i<n-1;++i)
	{
		min=i;
		for(j=i+1;j<n;++j)
		{
			if(a[min]>a[j]) 
					 min=j;
		}
		swap(&a[min],&a[i]);
	}
}


int main()
{
	int a[]={6,44,8,10,51,89,90,7,20,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	SelectionSort(a,n);	
	
	//printing sorted array
	for(int k=0;k<n;++k)
	cout<<a[k]<<" ";
}