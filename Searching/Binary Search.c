#include<stdio.h>
#include<conio.h>

int binarysearch(int a[],int val,int low,int high);

int main() 
{
	int val,i,j,n,flag,low,high,temp;
	printf("----------Binary Search--------");
	printf("\n Enter the size of array:");
	scanf("%d",&n);
	int a[n];
	
	
	printf("\n Enter the element:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	
	// sorting array
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	printf("Sorted array:\n");
	for(i=0; i<n; i++)
	{
	printf("%d\n",a[i]);
    }
    
    printf("\nEnter the element which you want to search:");
    scanf("%d",&val);
    low=0;
    high=n-1;
    flag=binarysearch(a,val,0,n-1);
    
//    if(flag == -1)
//    {
//    	printf("Sorry, Value is not present in array");
//	}
//	else

    printf("\n The element is at a[%d] is location",flag);
//    int mid=(low+high)/2;
//    printf("\nv a[mid]");
    return 0;
}

int binarysearch(int a[],int val,int low,int high)
{
	int mid;
	if(low<=high)
	{
			mid=(low+high)/2;
	}
	
	if(val==a[mid])
	{
		return mid;
	}
	else
	{
		if(val<a[mid])
		{
			binarysearch(a,val,low,mid-1); // search at left side of mid
		}
		else
		{
			binarysearch(a,val,mid+1,high); // search at right side of mid
		}
	}
}
