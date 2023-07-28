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
               
       	printf("Perform Various Operation on singly circular Link List");
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
		   	/*case 3:printf("Enter the Element you want to search:");
		   	       scanf("%d",&val);
		   	        int val;
                    int found=0;
	                struct node *temp;
		   	        temp=head;
		   	        while((temp!=NULL)&&(found==0))
		   	        found=search(val);
		   	        if(found)
		   	        printf("\nThe number is Present in the list");
		   	        else
		   	        printf("\nThe number is not Present in the list");
			        break;*/
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

void create()
{
	int choice=1;
	 struct node *temp,*new;
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

        if(head==NULL)
        {
                head=temp=new;
        }
        else
        {
                
                //temp=head;
                /*while(temp->next!=head)
                {
                        temp=temp->next;
                }*/
                temp->next=new;
                temp=new;
            }
                temp->next=head;
                printf("1 for continue and 0 for exit:");
                scanf("%d",&choice);
            }

}
void display()
{
	printf( " THE HEAD IS %d" , head->data);
	printf( " THE HEAD NEXT IS %d" , head->next->next->next->next->next->next->next->next->next->next->data);
	
   struct node *temp;
    temp=head;
        if(head==NULL)
        {
                printf("\nList is empty\n");
                
        }
        else
        {
               // temp=head;
                printf("\nThe List elements are:\n");
                while(temp->next!=head)
                {
                       printf(" %d\n", temp->data );
                        temp=temp->next ;
                }
                printf(" %d\n", temp->data );
}
}
void insert_front()
{
	struct node *ptr,*temp;   
    int item;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else   
    {  
        printf("\nEnter the node data:");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        printf("\nnode inserted\n");  
    }  
}
void insert_end()
{
	 struct node *ptr,*temp;   
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter Data?");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        printf("\nnode inserted\n");  
    }  
}
void insert_after()
{
	int item;
	struct node *ptr,*head2;    
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    
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
		
	head2 = head;	
    while(head2->data != item)
    {
     	head2=head2->next;
	}
	
	ptr->next=head2->next;
	head2->next=ptr;
	 }
}
void insert_before()
{
	int item;
	struct node *ptr,*head2;    
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    
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
		
	head2 = head;	
    while(head2->next->data != item)
    {
     	head2=head2->next;
	}
	
	ptr->next=head2->next;
	head2->next=ptr;
	 }
}
void delete_front()
{
	struct node *ptr;   
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW\n");    
    }  
    else 
	if(head->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
    }  
      
    else  
    {   ptr = head;   
        while(ptr -> next != head)  
        ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        printf("\nnode deleted\n");  
  
    }  
}
void delete_end()
{
	struct node *ptr, *temp;  
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW\n");  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            temp=ptr;         /*temp is point before node ptr pointer */
            ptr = ptr->next;  
        }  
        temp->next = ptr -> next;  
        free(ptr);  
        printf("\nnode deleted\n");  
  
    }  
}
void delete_after()
{
	int item;
	struct node *temp,*head2;    
    //temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the element which you want to delete after:");    /*je element enter karvo te*/
    scanf("%d",&temp->data);

    if(head==NULL)
    {
    //	head=head2;that i wrong
    head =temp;
	}
	else
	{
		printf("\nEnter the element after which you want to delete the node:"); /*list mathi element*/
		scanf("%d",&item);
		/*temp=head;*/
	// head=head2;                
	                    
	head2 = head;	     
    while(head2->data !=item)
    {
     	head2=head2->next;
	}
	temp=head2->next;
	head2->next=temp->next;
	free(temp);
}
}

void delete_before()
{
		int item;
	struct node *temp,*head2;    
    //temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the element which you want to delete before:");    /*je element enter karvo te*/
//    scanf("%d",&temp->data);      vasu 
	scanf("%d",&item);         // deco
    if(head==NULL)
    {
    //	head=head2;that i wrong
//    head =temp;   vasu
head->data = item ;
	}
	else
	{
//		printf("\nEnter the element before which you want to delete the node:"); /*list mathi element*/
//		scanf("%d",&item);                                                    vasu 
		/*temp=head;*/
	// head=head2;                
	                    
	head2 = head;	     
    while(head2->next->data !=item)
    {
    	temp=head2;
     	head2=head2->next;
	}
	temp->next =head2->next;
    head2->next = NULL ;	
//	temp=head2->next;
//	head2->next=temp->next;
	free(head2);
}
}
void delete_ParticularNode()
{
	
        int i,pos;        /*ParticularNode means pos*/
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
                        // while condition 
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
void delete_List()
{
		head = NULL;
		printf("List is Deleted\n");
}
