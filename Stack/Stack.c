// WRITE A PROGRAM TO CREATE A STACK AND PERFORM FOLLOWING OPERATION ON STACK.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *stack,*temp,size;
int choice,n,top,x,i,id,new_element;
void push();
void pop();
void peek();
void display();
void change(int id,int new_element);

int main()
{
	
	top = -1;
	printf("Enter the size of the Stack: ");
	scanf("%d",&n);
	stack=(int *)malloc(n*sizeof(int));
	if(stack == NULL)
	{
		printf("Memory not Allocated...\n");
		getch();
		exit(0);
	}
	else
	printf("1.PUSH \n");
	printf("2.POP \n");
	printf("3.DISPLAY \n");
	printf("4.PEEK \n");
	printf("5.CHANGE \n");
	printf("6.EXIT \n");
	do
	{
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: peek();
					break;
			case 5: printf("Enter the Element ID :");
					scanf("%d",&id);
					printf("Enter new Element Value :");
					scanf("%d",&new_element);
					change(id,new_element);
					break;
			case 6: exit(0);
					break;
			default:printf("Invalid choice...");
					break;
		}
	}
	while(choice != 6);
	getch();
}
void push()
{
	if(top >= n-1)
	{
		printf("Stack Overflow...");
	}
	else
	{
		printf("Enter a Value : ");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if(top <= -1)
	{
		printf("Stack Underflow...");
	}
	else
	{
		printf("Popped Element is %d",stack[top]);
		top--;
	}
}
void display()
{
	if(top > 0)
	{
		printf("The Elements are : ");
		for(i=top; i>=0; i--)
		{
			printf("\n%d",stack[i]);
		}
	}
	else
	{
		printf("Stack is Empty...");
	}
}
void peek()
{
	printf("\nTop : %d",top);
	printf("\nValue : %d",stack[top]);
}
void change(int id, int new_element)
{
	int i,j=-1;
	for(i=top; i>id; i--)
	{
		temp[++j]=stack[top--];
	}
	stack[top]=new_element;
	for(i=j;i>-1;i--)
	{
		stack[++top]=temp[j--];
	}
}
