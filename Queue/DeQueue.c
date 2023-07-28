#include<stdio.h>
#include<conio.h>
#define size 10
/*data structure for deque*/
struct queue
{
	int que[size];
	int front,rear;
}Q;
int Qfull()
{
	if(Q.rear==size-1)
	return 1;
	else
	return 0;
}
int Qempty()
{
	if((Q.front>Q.rear)||(Q.front==-1&&Q.rear==-1))
	return 1;
	else
	return 0;
}
int insert_rear(int item)
{
	if(Q.front==-1&&Q.rear==-1)
	Q.front++;
	Q.que[++Q.rear]=item;
	return Q.rear;
}

int delete_front()
{
	int item;
	if(Q.front==-1)
	Q.front++;
	item=Q.que[Q.front];
	Q.que[Q.front]=-1;
	Q.front++;
	return item;
}

int insert_front(int item)
{
	int i,j;
	if(Q.front==-1)
	Q.front++;
	i=Q.front-1;
	while(i>=0)
	{
		Q.que[i+1]=Q.que[i];
		i--;
			}
			j=Q.rear;
			while(j>=Q.front)
			{
				Q.que[j+1]=Q.que[j];
				j--;
			}
			Q.rear++;
			Q.que[Q.front]=item;
			return Q.front;
}

int delete_rear()
{
	int item;
	item=Q.que[Q.rear];
	Q.que[Q.rear]=-1;   /*logical deletion*/
	Q.rear--;
	return item;
}

void display()
{
	int i;
	printf("\nDouble Ended Queue is:");
	for(i=Q.front;i<=Q.rear;i++)
	printf("%d",Q.que[i]);
}

void main()
{
	int choice,i,item;
	char ans;
	ans='y';
	Q.front=-1;
	Q.rear=-1;
	for(i=0;i<size;i++)
	Q.que[i]=-1;
	printf("\n\t\tPerform Operation Like Insert,Delete,Display on Double Ended Queue");
	do
	{ 
		printf("\n1.insert by rear");
		printf("\n2.delete by front");
		printf("\n3.insert by front");
		printf("\n4.delete by rear");
		printf("\n5.display");
		printf("\n0.Exist");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(Qfull())
			printf("\nDouble ended Queue is full");
			else
			{
				printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				Q.rear=insert_rear(item);
			}
			break;
			
			case 2:if(Qempty())
			printf("\nDoubles ended Queue is Empty");
			else
			{
				item=delete_front();
				printf("\nThe item deleted from queue is %d",item);
			}
			break;
			
			case 3:if(Qfull())
			printf("\nDouble ended Queue is full");
			else
			{
				printf("\nEnter The item to be inserted");
				scanf("%d",&item);
				Q.front=insert_front(item);
			}
			break;
			
			case 4:if(Qempty())
			printf("\nDouble ended Queue is Empty");
			else
			{
				item=delete_rear();
				printf("The item deleted from queue is %d",item);
			}
			break;
			
			case 5:display();
			break;
			
			
		}
	
	}
	while(choice!=0);
	return 0;
}
