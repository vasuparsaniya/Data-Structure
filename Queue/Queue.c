#include<stdio.h>
#include<conio.h>
#define size 5
struct queue
{
	int que[size];
	int front,rear;
}Q;
Qfull()
{
	if(Q.rear>=size-1)
	return 1;
	else
	return 0;
}

int insert(int item)
{
	if(Q.front==-1)
	Q.front++;
	Q.que[++Q.rear]=item;
	return Q.rear;
}
int Qempty()
{
	if((Q.front==-1) || (Q.front>Q.rear))     
	return 1;
	else
	return 0;
}
int delet()
{
	int item;
	item=Q.que[Q.front];
	Q.front++;
	printf("\nThe deleted item is %d",item);
	return Q.front;
}

void display()
{
	int i;
	for(i=Q.front;i<=Q.rear;i++)
	printf("%d",Q.que[i]);
}

void main(void)
{
	int ch,item;
	char ans;
	Q.front=-1;
	Q.rear=-1;
	do
	{
	
		printf("\n1.Insert");
		printf("\n2.Delet");
		printf("\n3.DISPLAY");
		printf("\n0.EXIT");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(Qempty())      
			printf("\nEnter The Number to be Inserted:");
			scanf("\n\t%d",&item);
			insert(item);
			
		
		break;
		case 2:if(Qempty())
		printf("\nQueue Underflow!!");
		else
		delet();
		break;
		case 3:if(Qempty())
		printf("\nQueue Is Empty!");
		else
		display();
        break;
default:printf("\nThankYou!");
break;
}

}while(ch!=0);
    return 0;
}




