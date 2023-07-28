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
               
       	printf("Perform Various Operation on Link List");
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
	 struct node *temp,*new,*prev;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nList is Overflow:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                
                new=head;
                while(new->next!=NULL)
                {
                        new=new->next;
                }
                new->next=temp;
                temp->prev=new;
                
                
		}
}

/**************display*******************/
void display()
{
	  	/* printf( " THE HEAD IS %d" , head->data);
	  	  printf( " THE HEAD NEXT IS %d" , head->next->data); 
			printf( " THE HEAD NEXT PREV %d" , head->next->next->prev->data);*/
	struct node *temp;
        if(head==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        else
        {
                temp=head;
                printf("\nThe List elements are:\n");
                while(temp!=NULL)
                {
                        printf(" %d\n", temp->data );
                        temp=temp->next ;
                }
}
}

/*******************insert at front*******************/
void insert_front()
{
	struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   
    printf("\nEnter the value which you want to insert at front:");  
    scanf("%d",&item);  
    ptr->data=item;
    ptr->next = NULL;  
    ptr->prev=NULL;  
   if(head==NULL)  
   {    
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}

/*******************insert at end***************/
void insert_end()
{
	struct node *ptr,*head2;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   
       printf("\nEnter the value which you want to insert at end:");  
       scanf("%d",&item);  
        ptr->data=item;  
        ptr->next = NULL;  
        ptr->prev = NULL; 
       if(head == NULL)  
       {  
        head = ptr;  
       }  
       else  
       {  
          head2 = head;  
          while(head2->next!=NULL)  /*travel head2*/
          {  
              head2 = head2->next;  
          }  
          head2->next = ptr;  
          ptr ->prev=head2;  
          ptr->next = NULL;  
          }  
    printf("\nnode inserted\n"); 
}

/**************************insert at after*********************/
void insert_after()
{
	int item;
	struct node *ptr,*head2,*prev;    /*new==head2*/
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("\nEnter the element which you want to insert after:");    /*je element enter karvo te*/
//    scanf("%d",&new->data);
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
	struct node *ptr,*head2,*prev;    /*new==head2*/
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("\nEnter the element which you want to insert before:");    /*je element enter karvo te*/
//    scanf("%d",&new->data);
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
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW\n");  
    }  
    else 
	if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}

/***********************delete at end************************/
void delete_end()
{
	 struct node *head2;      
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW\n");  
    }  
    else 
	if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        head2= head;   
        if(head2->next != NULL)  
        {  
            head2= head2 -> next;   
        }  
        head2->prev->next=NULL;
        //temp=head2->prev;     /*temp become lat node after head2 free*/
        //temp->next=NULL;
        //temp->next->prev=NULL;
        free(head2);  
        printf("\nnode deleted\n");  
    }  

/*
    struct node *head2,*temp;      
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW\n");  
    }  
    else 
	if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        head2= head;   
        if(head2->next != NULL)  
        {  
            head2= head2 -> next;   
        }  
        temp=head2->prev;     /*temp become lat node after head2 free
        head2->prev=NULL;
        free(head2);  
        printf("\nnode deleted\n");  
    }  */
/*	struct node *temp,*tail;
	if(tail=NULL)
	{
		 printf("\n UNDERFLOW");
	}
	else
	{
		temp=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
		free(temp);
		
	}*/
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
    //	head=head2;that i wrong
    //head = temp ;
    head->data=item;
	}
	else
	{
		/*temp=head;*/          
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
	struct node *temp,*head2,*prev;    
    temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the element which you want to delete before:");    /*je element delete karvo te*/
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
		//printf("\nEnter the element before which you want to delete the node:"); /*list mathi element*/
		//scanf("%d",&item);
		/*temp=head;*/
	// head=head2;                
	                    
	head2 = head;
	while(head2->next->data !=item)
	{
		
     	head2=head2->next;
	}
	temp=head2->prev;
	temp->next=head2->next;
	head2->next->prev=temp;
	free(head2);
}
}
	     
/******************delete at particularnode******************/   
void delete_ParticularNode()
{
	 int i,pos;        /*ParticularNode means pos*/
        struct node *temp,*head2;
        if(head==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t\n");
                scanf("%d",&pos);
                if(pos==0)
                {
                        head2=head;
                        head=head->next ;
                        printf("\nThe deleted element is:%d\t",head2->data  );
                        free(head2);
                }
                else
                {
                        head2=head;
                        for(i=1;i<pos;i++) 
						{ 
						temp=head2; 
						head2=head2->next ;
                                if(head2==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =head2->next ;
                        printf("\nThe deleted element is:%d\n",head2->data );
                        free(head2);
                }
        }
}
 
/**********************delete list*******************/
void delete_List()
{
	head = NULL;
	printf("List is delete\n");
	//	struct node *prev,*new;
//            new=head;
//            while(new->next!=NULL)
//            {
//            	prev=new;
//            	new=new->next;
//            	free(prev);
//			}
}
 
