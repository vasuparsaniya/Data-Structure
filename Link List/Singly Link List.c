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
};
struct node *head=NULL;

int main()     
{
        int choice,val;
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
        struct node *temp,*new;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nList is Overflow:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->data);
        temp->next=NULL;
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
        }
}

/**************display*******************/
void display()
{
	 printf( " THE HEAD IS %d" , head->data);    
        struct node *new;
        if(head==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        else
        {
                new=head;
                printf("\nThe List elements are:\n");
                while(new!=NULL)
                {
                        printf(" %d\n", new->data );
                        new=new->next ;
                }
        }
}

/*******************insert at front*******************/
void insert_front()
{
	
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}

/*******************insert at end***************/
void insert_end()
{
        struct node *temp,*new;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                new=head;          /*new is head2*/
                while(new->next!=NULL)
                {
                        new=new->next ;
                }
                new->next =temp;
        }
}


/**************************insert at after*********************/
void insert_after()
{
	
	
	int val;
	struct node *temp,*new;    /*new==head2*/
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    printf("\nEnter the element which you want to insert after:");    /*je element enter karvo te*/
//    scanf("%d",&new->data);
    scanf("%d",&temp->data);

    if(head==NULL)
    {
    head = temp ;
	}
	else
	{
		printf("\nEnter the element after which you want to insert the node:"); /*list mathi element*/
		scanf("%d",&val);
		/*temp=head;*/
	
	new = head;	
    while(new->data != val)
    {
     	new=new->next;
	}
	temp->next=new->next;
	new->next=temp;
    }
}

/*************************insert at before***********************/
void insert_before()
{
	int val;
	struct node *temp,*new;    /*new==head2*/
    temp=(struct node *)malloc(sizeof(struct node));
//    temp->next=NULL;
    printf("\nEnter the element which you want to insert before:");    /*je element enter karvo te*/
scanf("%d",&temp->data);

    if(head==NULL)
    {
    //	head=new;
    head = temp ;
	}
	else
	{
		printf("\nEnter the element before which you want to insert the node:"); /*list mathi element*/
		scanf("%d",&val);
		/*temp=head;*/
	new = head;	
    while(new->next->data != val)
    {
     	new=new->next;
	}
	temp->next=new->next;
	new->next=temp;
}
}
	
/*******************delete at front************************/
void delete_front()
{
        struct node *new;
        if(new==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                new=head;
                head=head->next ;
                printf("\nThe deleted element is :%d\t\n",new->data);
                free(new);
        }
}

/***********************delete at end************************/
void delete_end()
{
        struct node *prev,*new;           /*new==head2*/
        if(head==NULL)              /*0 node */
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(head->next ==NULL)   /*1 node*/
        {
                new=head;
                head=NULL;
                printf("\nThe deleted element is:%d\t\n",new->data);
                free(new);
        }
        else
        {                        /*more than one node*/
                new=head;
                while(new->next!=NULL)
                {
                        prev=new;     /*prev i point before node ptr pointer */
                        new=new->next;
                }
                prev->next=NULL;
                printf("\nThe deleted element is:%d\t",new->data);
                free(new);
        }
}

/*********************delete at after**********************/
void delete_after()
{
		int val;
	struct node *temp,*new;    /*new==head2*/
    temp=(struct node *)malloc(sizeof(struct node));
//    temp->next=NULL;
    printf("\nEnter the element which you want to delete after:");    /*je element enter karvo te*/
//    scanf("%d",&new->data);
    //scanf("%d",&temp->data);
    scanf("%d",&val);
    if(head==NULL)
    {
    //	head=new;that i wrong
    head->data=val;
    //head = temp ;
	}
	else
	{
		/*temp=head;*/                
	new = head;	     
    while(new->data != val)
    {
     	new=new->next;
	}
	temp=new->next;
	new->next=temp->next;
	free(temp);
}
}

/**********************delete at before******************/
void delete_before()
{
		int val;
	struct node *temp,*new;    /*new==head2*/
    
    printf("\nEnter the element before which you want to delete :");    /*je element delete karvo te*/
//    scanf("%d",&new->data);
//    scanf("%d",&temp->data);
		scanf("%d",&val);       
    //val = temp->data;
	 
    if(head==NULL)
    {
    	printf( " EMPTY LIST ");
  //  head = temp ;
	}
	else
	
	{     
	   // val = temp->data;             
	new = head;	     
    while(new->next->data != val)
    {
    	temp=new;
     
	 
	 	new=new->next; 
	}
	if(temp=NULL)
	{
		 
		new=head;     
		head=head->next;
		new->next = NULL ;
		
		free(new);
	}
	else
	{
	// temp=head;    
    temp->next = new->next;
    new->next=NULL;
    free(new);
   
}
}
}

/******************delete at particularnode******************/
void delete_ParticularNode()
{
        int i,pos;        /*ParticularNode means pos*/
        struct node *temp,*new;
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
