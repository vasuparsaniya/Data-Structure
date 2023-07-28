#include<stdio.h>
#include<conio.h>

int n,m;

void main()
{
	int i,A[m];
	void bubble(int A[m]);    // size of list is m
	
	printf("\n\t\t Bubble Sort\n");
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
	
		scanf("%d",&A[i]);
		bubble(A); //call the bubble function
		getch();
	}
}

void bubble(int A[m])
{
	int i,j,temp;
	
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	
	printf("\n The sorted List is:\n");
	for(i=1;i<=n;i++)
	printf("%d\n",A[i]);
}



 
