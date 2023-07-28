#include<stdio.h>
#include<conio.h>
#define size 5
int que[size];
int front=-1; /* queue initialization by front=-1 and rear=0 */
int rear=0;
int qFull()
{
	if(front==(rear+1)%size)
	return 1;
	else
	return 0;
}

int qEmpty()
{
	if(front==-1)
	return 1;
	else
	return 0;
}

void insert(int item)
{
	if(qFull()) /*qFull() returns true value */
	printf("\nThe circular Queue is full!");
	else
	{
		if(front==-1)   /*only one element in the queue*/
		front=rear=0;
		else
		rear=(rear+1)%size;
		que[rear]=item;
	}
	}
	
	void delet()
	{
		int item;
		if(qEmpty())
		printf("\nQueue Is Empty!");
		else
		{
			item=que[front];
			if(front==rear)
			{
				front=rear=-1;
			}
			else
			front=(front+1)%size;
			printf("\nThe deleted item is %d",item);
		}
	}
	
	void display()
	{
		int i;
		if(qEmpty())
		{
			printf("\nThe Queue is empty");
			return;
		}
		i=front;
		while(i!=rear)
		{
			printf("%d",que[i]);
			i=(i+1)%size;
		}
		printf("%d",que[i]);
		}
		
		void main()
		{
			int ch,item;
			char ans;
			
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
			case 1:      
			printf("\nEnter The Element:");
			scanf("%d",&item);
			insert(item);
			break;
		case 2:
		delet();
		break;
		case 3:
		display();
        break;
        
        default:printf("\nThankYou!");
        break; 
			}
			
			
		}while(ch!=0);
    return 0;
			}
