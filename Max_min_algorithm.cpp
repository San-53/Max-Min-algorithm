//Max-Min algorithm
#include<iostream>
using namespace std;
void Max_Min(int arr[],int low,int high,int &max,int &min)
{
	int mid;
	int max1,min1;
	if(low==high)
	{
		max=arr[low];
		min=arr[low];
		return;
	}
	else if(low==high-1)
	{
		if(arr[low]>arr[high])
		{
			max=arr[low];
			min=arr[high];
		}
		else
		{
			max=arr[high];
			min=arr[low];	
		}
		return;
	}
	else
	{
		//Divide the problem
		
		mid=(low+high)/2;
		Max_Min(arr,low,mid,max,min);
		Max_Min(arr,mid+1,high,max1,min1);
		
		//Combine the solution
		
		if(max<max1)
			max=max1;
		if(min>min1)
			min=min1;
			
		return;
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements of the array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int low=0;
	int high=n-1;
	int max,min;
	Max_Min(arr,low,high,max,min);
	cout<<"Max = "<<max<<endl;
	cout<<"Min = "<<min<<endl;
	return 0;
}
