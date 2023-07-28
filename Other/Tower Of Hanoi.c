#include<stdio.h>
#include<conio.h>

void toh(int,char,char,char);

int main()
{
	int m;
	printf("Enter the number of disk:");
	scanf("%d",&m);
	printf("\n");
	
	toh(m,'A','B','C');
	getch();
	return 0;
}

void toh(int n,char beg,char aux,char end)
{                               // beg-> begining peg  aux-> auxilary peg  end-> last peg
	if(n>0)
	{
		toh(n-1,beg,end,aux);
		printf("%d Disk move %c to %c\n",n,beg,end);
		toh(n-1,aux,beg,end);
	}
}
