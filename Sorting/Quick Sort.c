#include<stdio.h>
#include<conio.h>

void quicksort(int a[],int first,int last);

int main()
{
	int i,n;
	int first,last;
	
	printf("\n\t----Quick Sort----");
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	
	int a[n];

	printf("\n Enter the element:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	quicksort(a,0,n-1);
	
	
	printf("\nSorted array:\n");
	
	for(i=0; i<n; i++)
		printf("%d\n",a[i]);
	
	return 0;
}

/* -----------Quick sort --------*/

void quicksort(int a[],int first,int last)
{
	int i,j,temp,pivot=first;
	
	if(first<last)
	{
		//pivot=first;
		i=first;
		j=last;
		
		while(i<j)
		{
			while(a[i]<=a[pivot] && i<last)
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
	
	quicksort(a,first,j-1);
    quicksort(a,j+1,last);

	}
}
