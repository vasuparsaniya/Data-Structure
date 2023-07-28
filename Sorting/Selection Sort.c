#include<stdio.h>
#include<conio.h>

int n,m;

void main()
{
	int i,A[m];
	void selection(int A[m]);    // size of list is m
	
	printf("\n\t\t Selection Sort\n");
	printf("\n Enter the size of list:");
	scanf("%d",&m);
	printf("\n How many elements are there?");
	scanf("%d",&n);
	if(m<n)
	{
		printf("List size is less than number of element you want to enter");
	}
	else
	{
	printf("\n Enter the elements\n");
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
	}
		selection(A); //call the selection function
		getch();
	}
}

void selection(int A[m])
{
	int i,j,temp;
	
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(A[i]>A[j])
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
	
	printf("\n The sorted List is:\n");
	for(i=1;i<=n;i++)
	printf("%d\n",A[i]);
}



 

