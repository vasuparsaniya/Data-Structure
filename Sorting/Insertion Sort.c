#include<stdio.h>
#include<conio.h>

int n,m;

void main()
{
	int i,A[m];
	void insertion(int A[m]);    // size of list is m
	
	printf("\n\t\t Insertion Sort\n");
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
		insertion(A); //call the bubble function
		getch();
	}
}

void insertion(int A[m])
{
	int i,j,x;
	
	for(i=2;i<=n;i++)
	{
		x=A[i];
		j=i-1;
		
		while(x<A[j] && j>0)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;	
	}

	
	printf("\n The sorted List is:\n");
	for(i=1;i<=n;i++)
	printf("%d\n",A[i]);
}
