#include <stdio.h>
#include<conio.h>

int fib(int);

int fib(int n)
{ 
//	if(n==0)
//	{
//		return 0;
//	}
//	else
//	{
//		if(n==1)
//		{
//			return 1;
//		}
    if(n<=1)
    {
       return n;
    }
	else    //if(n>1)
    {
    return fib(n-1) + fib(n-2);
}
}


int main()
{
    int n,i;
    printf("Enter how many term you print:");
    scanf("%d",&n);
    
    printf("Fibonacci series is:");
    
    
    for(i=0;i<n;i++)
    {
    printf("%d ", fib(i));
    }
    getch();
    return 0;
}
