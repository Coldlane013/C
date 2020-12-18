#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;						//Initializing head as Null pointer NO MEMORY ALLOCATED YET 

struct node								//Initializing container and pointer NO MEMORY ALLOCATED AS WELL
{
	int data;                        				// how many bytes will be allocated here is dependent to data types
	struct node *next;

};
void append()								// Adding data while also creating node(container) for it.
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node)); 		// Allocating memory for node
	printf("Enter data:");
	scanf("%d",&temp->data);
	temp->next= NULL;   
	if(head == NULL)
	{
		head=temp;         
	}
	else
	{
		struct node *p=head;
		while(p->next!=NULL)
		{
			p=p->next; 				// pointer changing address value until found 0
		}
		p->next=temp; 					// data will connect to that node 
	}
	printf("Data successfully added.PRESS a number again to continue...\n");
}

void addtohead()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node)); //new node to be added
	printf("Enter data:");							
	scanf("%d",&temp->data);				
	temp->next=NULL; 				// intialize address to be null para makabitan
	temp->next=head;				//kukunin yung address ni root
	head=temp;						// root will get acess to the new node
	printf("Data successfully added.PRESS a number again to continue...\n");
}

void middle(int loc)
{
	int ctr,jump=1;
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter a data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	ctr= loc-1;
	p=head; // gets head address so that it can move within linked list
	while(jump < ctr )
	{
		p=p->next;
		jump++;
	}
	temp->next = p->next;	
	p->next = temp;	
	printf("Data successfully added.PRESS a number again to continue...\n");
}

void connector(int loc)
{
	int len=0;
	len = length(); //checks length of list
	if(loc > len)   
	{
		printf(" invalid location\n list only contain %d nodes",len);
	}
	else
	{
		if(loc!=1)
		{
			middle(loc); // adds node based on the inputed location
		}		
		else
			addtohead();			
	}		
}
int length() // list tiga count
{
	struct node *temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void display()
{
		struct node *p = head;
	if (p != NULL)
	{	
		while(p != NULL)
		{
			printf("%d->",p->data); // while finder or p , address is != NULL continue to print data
			p=p->next;
		}
		printf("PRESS a number again to continue...\n");	
	}
	
	else
	{
		printf("PRESS a number again to continue...\n");
		printf(" ITS EMPTY!");
	}
}

int find(int value)
{
	
	struct node *p=head;
	while(p != NULL && p->data != value)
        p = p->next;
    return p;

}

void deletenode(int loc)
{
	struct node *p = head,*temp;
	int ctr,jump = 1;
	ctr= loc-1; // loc - 1 because computer start counting in 0
	if(loc!=1)
	{
		while(jump < ctr )  // if node location is in middle or end ex: is 2<1 if yes proceed to temp getting the address of node
		{					// if no continue jump from one node to next
			p=p->next;
			jump++;
		}
		temp = p->next;         // temp linking to the address of node that is to be deleted 
		p->next = temp->next; // 
		
		temp->next = NULL; // link to tobedeleted node address will be NULL
		free(temp); // delete node
	}
	else // if node location == 1
	{
		head = p->next; // root will kabit to node address of the katabi na hindi idedelete
		p->next = NULL; // address value of first node
		free(p); // delete node
	}
	printf("Node sucessfully deleted.PRESS a number again to continue...\n");
}
void sort()
{
	struct node *p = head,*cpt;
	int temp;
	while(p->next != NULL)
	{
		cpt = p->next;
		while(cpt != NULL)
		{
			if(p->data > cpt->data)  //swaping values
			{
				temp = p->data;
				p->data = cpt->data; 
				cpt->data = temp;
			}
			cpt = cpt->next;
		}	
		p = p->next;
	}
	printf("\nDATA sucessfully sorted.PRESS 5 to display\n");
}
	

void first()
{
	printf("BASIC OPERATIONS IN SINGLE LINKED LIST");
	printf("\nNOTE: Press the following indicated NUMBERS to automatically perform action:");
	printf("\n\n[1]INSERT\n[2]ADD DATA IN SPECIFIC NODE\n[3]DELETE\n[4]FIND\n[5]DISPLAY\n[6]SORT\n[7]QUIT\n\n");

}
int main()
{
	int loc=0;
	int ch,val,len;
	int f=0;
	first_menu:
	first();
	tryagain:

	while(ch != 7) // quit value is == 7
	{
		switch(getch(ch))
		{
			case '1':
				append();
				break;
			case '2':
				printf("Enter Location:");
				scanf("%d",&loc);
				connector(loc);
				printf("\n");
				printf("\n");
			case '3':
				printf("Enter location you want to delete:");
				scanf("%d",&loc);
				len=length();
				if(loc>len || len==0)
					printf(" invalid location\n list only contain %d nodes",len);
				else
					deletenode(loc);
				printf("\n");
				printf("\n");
				break;
			case '4':
				printf("Enter the value you want to find:");
				scanf("%d",&val);
				f=find(val);
				if(f == 0)
					printf("Element is not yet entered");
				else
					printf("%d is present",val);
				printf("\n");
				printf("\n");
				break;
			case '5':
				display();
				printf("\n");
				printf("\n");
				break;
			case '6':
				sort();
				printf("\n");
				printf("\n");
				break;
			
			case '7':
				exit(0);	
			default:
				printf("Invalid input,Try again.\n");	
				goto tryagain;	
		}
	}
}


