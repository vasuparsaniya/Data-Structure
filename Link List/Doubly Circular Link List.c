#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>     
void create();
void display();
void insert_front();
void insert_end();
void insert_after();
void insert_before();
void delete_front();
void delete_end();
void delete_after(); 
void delete_before();
void delete_ParticularNode();
void delete_List();
 
 
struct node
{
        int data;
        struct node *next; 
        struct node *prev;
};
struct node *head;

int main()     
{
        int choice,item;
        while(1){
               
       	printf("Perform Various Operation on doubly circular Link List");
		printf("\n1.Create list");
		printf("\n2.Diplay list");
		printf("\n3.insert at front");
		printf("\n4.insert at end");
		printf("\n5.insert at after");
		printf("\n6.insert at before");
		printf("\n7.delet at front");
		printf("\n8.delet at end");
		printf("\n9.delet at after");
		printf("\n10.delet at before");
		printf("\n11.delet Particularnode");
		printf("\n12.delet link List");
		printf("\n13.Exit");
		printf("\nEnter Your Choice (1-13):");
		scanf("%d",&choice);
                switch(choice)
                {
           	case 1:create();
			       break;
		   	case 2:display();
			       break;
		   	case 3:insert_front();
			       break;
		   	case 4:insert_end();
			       break;
		   	case 5:insert_after();
		   	        break;
		   	case 6:insert_before();
			       break;
		   	case 7:delete_front();
			       break;
		   	case 8:delete_end();
			       break;
		   	case 9:delete_after();
			       break;
		   	case 10:delete_before();
			       break;
		   	case 11:delete_ParticularNode();
			       break;
		   	case 12:delete_List();
			       break;
		    case 13:exit(0);
			       break;
		     default:
				printf("Invalid Choice\n");
				break;
                }
        }
        return 0;
}

/***********************************************create**************/
void create()
{
	int choice=1;
	 struct node *temp,*new,*prev,*ptr;           /*ptr point to lat node*/
	 while(choice)
	 {
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
                printf("\nList is Overflow:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&new->data);
        new->next=NULL;
        new->prev=NULL;

        if(head==NULL)
        {
                head=ptr=new;
                head->next=head;
                head->prev=head;
        }
        else
        {
                
                //temp=head;
                /*while(temp->next!=head)
                {
                        temp=temp->next;
                }*/
                ptr->next=new;
                new->prev=ptr;
                new->next=head;
                head->prev=new;
                ptr=new;
            }
                printf("1 for continue and 0 for exit:");
                scanf("%d",&choice);
            }

}

/**************display*******************/
void display()
{
	
	printf( " THE HEAD IS %d" , head->data);
	printf( " THE HEAD NEXT PREV IS %d" , head->next->prev->data);
	
   struct node *temp;        /*ptr point to last node*/
    temp=head;                   /* temp point to firt node*/
        if(head==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        else
        { 
                //temp=head;
                printf("\nThe List elements are:\n");
                while(temp->next!=head)
                {
                	printf(" %d\n", temp->data );
                    temp=temp->next ;
                }
                 printf(" %d\n", temp->data );
}
}

/*******************insert at front*******************/
void insert_front()
{
	struct node *ptr,*temp;    /*temp point to last node mean tail*/
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter the value which you want to insert at front:");  
    scanf("%d",&item);  
    ptr->data=item;  
   if(head==NULL)  
   {  
      head = ptr;  
      ptr -> next = head;   
      ptr -> prev = head;   
   }  
   else   
   {  
       temp = head;   
    while(temp -> next != head)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  
    ptr -> prev = temp;  
    head -> prev = ptr;  
    ptr -> next = head;  
    head = ptr;  
   }  
   printf("\nNode inserted\n");  
}  
}

/*******************insert at end***************/
void insert_end()
{
	struct node *ptr,*temp;         /*temp point to lat node mean tail*/
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter the value which you want to insert at end:");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  
       {  
          temp = head;  
          while(temp->next !=head)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          head -> prev = ptr;  
          ptr -> next = head;  
        }  
   }  
     printf("\nnode inserted\n");  
}

/**************************insert at after*********************/
void insert_after()
{
	
	
	int item;
	struct node *ptr,*head2,*prev;    
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("\nEnter the element which you want to insert after:");    /*je element enter karvo te*/
    scanf("%d",&ptr->data);

    if(head==NULL)
    {
    head = ptr ;
	}
	else
	
	{
		printf("\nEnter the element after which you want to insert the node:"); /*list mathi element*/
		scanf("%d",&item);
		/*temp=head;*/
	// head=new;
	head2 = head;	
	
    while(head2->data != item)
    {
     	head2=head2->next;
	}
	
	ptr->next=head2->next;
	ptr->prev=head2;
	head2->next=ptr;
	head2->next->prev=ptr;
	
    }
}

/*************************insert at before***********************/
void insert_before()
{
	int item;
	struct node *ptr,*head2,*prev;    
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("\nEnter the element which you want to insert before:");    /*je element enter karvo te*/
    scanf("%d",&ptr->data);

    if(head==NULL)
    {
    head = ptr ;
	}
	else
	
	{
		printf("\nEnter the element before which you want to insert the node:"); /*list mathi element*/
		scanf("%d",&item);
		/*temp=head;*/
	// head=new;
	head2 = head;	
	
    while(head2->next->data != item)
    {
     	head2=head2->next;
	}
	ptr->next=head2->next;
	ptr->prev=head2;
	head2->next=ptr;
	head2->next->prev=ptr;
    }
}

/*******************delete at front************************/
void delete_front()
{
	struct node *temp;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else 
	if(head->next == head)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        temp = head;   
        while(temp -> next != head)     /*temp point to last node*/
        {  
            temp = temp -> next;  
        }  
        temp -> next = head -> next;  
        head -> next -> prev = temp;  
        free(head);  
        head = temp -> next;  
    }  
  
}

/***********************delete at end************************/
void delete_end()
{
	struct node *ptr,*temp,*prev;  
	
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else 
	if(head->next == head)     /*only one node*/
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != head)  
        {       
		    temp=ptr;   
            ptr = ptr -> next;   
        }  
        temp->next=head;
        head->prev=temp;
        free(ptr);
        printf("\nnode deleted\n");
    }  
}

/*********************delete at after**********************/
void delete_after()
{
	int item;
	struct node *temp,*head2;    
   // temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the element which you want to delete after:");    /*je element enter karvo te*/
    //scanf("%d",&temp->data);
    scanf("%d",&item);
    if(head==NULL)
    {
     head->data-item;
    //	head=head2;that i wrong
    //head = temp ;
	}
	else
	{              
	head2 = head;	     
    while(head2->data !=item)
    {
     	head2=head2->next;
	}
	
	temp=head2->next;
	head2->next=temp->next;
	temp->next->prev=head2;
	free(temp);
}
}

/**********************delete at before******************/
void delete_before()
{
	int item;
	struct node *temp,*head2,*ptr,*sh;       /*sh means store head*/
   

    printf("\nEnter the element which you want to delete before:");    /*je element enter karvo te*/
    //scanf("%d",&temp->data);
    scanf("%d",&item);
    if(head==NULL)
    {
    //	head=head2;that i wrong
    //head = temp ;
    head->data=item;
	}

	else
	{ 
	head2 = head;	     
    while(head2->next->data !=item)
    {
     	head2=head2->next;
	}
	if(temp==NULL)
	{
		sh = head ;
		ptr=head;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		head =head->next;
	//	head->prev->next=NULL;
		//sh->prev=NULL;
		ptr->next=head;
        head->prev=ptr;
        sh->next=NULL;
        sh->prev=NULL;
		free(sh);
	}
	else
	{
    temp=head2->prev;
	temp->next=head2->next;
	head2->next->prev=temp;
	free(head2);
}
}
}

/******************delete at particularnode******************/   
void delete_ParticularNode()
{
	struct node *temp,*prev,*ptr;     
	int pos,i=1,l;
	temp=head;
	printf("Enter Position of node which you want to delete:");
	scanf("%d",&pos);
	//l=getlength();
	
	if(pos<1 || pos>l)
	{
		printf("\nInvalid choice\n");
	}
	else
	if(pos==1)
	{
		delete_front();
	}
	else
	{
		while(i<pos)
		{
			while(i<pos)
			{
				temp=temp->next;
				i++;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
		if(temp->next==head)
		{ 
			ptr=temp->prev;     /* ptr point to last node*/
			free(temp);
		}
		else
		{
			free(temp);
		}
	}
}
	
	
	
/********************************************************	
        int i,pos;        /*ParticularNode means pos
        struct node *temp,*new;
        if(head==NULL)
        {
                printf("\nThe List is Empty\n");
                
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t\n");
                scanf("%d",&pos);
                if(pos==0)
                {
                        new=head;
                        head=head->next ;
                        printf("\nThe deleted element is:%d\t",new->data  );
                        free(new);
                }
                else
                {
                        new=head;
                        for(i=1;i<pos;i++) 
						{ 
						temp=new; 
						new=new->next ;
                                if(new==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                               }
                        }
                        temp->next =new->next ;
                        printf("\nThe deleted element is:%d\n",new->data );
                        free(new);
                }
        }
		}*/

/**********************delete list*******************/
void delete_List()
{
		head = NULL;
		printf("List is Deleted\n");
}
