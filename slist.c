#include <stdio.h>
#include <stdlib.h>

typedef  int nodedata_t;

typedef struct Node
{
	nodedata_t		data;
	struct Node		*link;
}NODE_t;

void insertFront(nodedata_t  ele);
void insertRear(nodedata_t  ele);
void insertOrder(nodedata_t ele);
void displayReverse(NODE_t *temp);
void display();

void deleteFront();
void deleteRear();
void deleteKey(int key);
NODE_t * search(int key);

void reverse();
void nlast(int n);
void checkforLoop();
NODE_t * middleNode();

NODE_t *first = NULL;	  // Pointer to first Node

void insertFront(nodedata_t  ele)
{
	//Creation of Node (Allocate Memory to node)
	NODE_t *pnewnode = (NODE_t *)malloc(sizeof(NODE_t));

	/*Initialise the node */
	pnewnode->data = ele;
	pnewnode->link = NULL;

	/*Attach the node to list */
	pnewnode->link = first;
	first = pnewnode;
}

void insertRear(nodedata_t  ele)
{
	//Creation of Node (Allocate Memory to node)
	NODE_t *pnewnode = (NODE_t *)malloc(sizeof(NODE_t));

	/*Initialise the node */
	pnewnode->data = ele;
	pnewnode->link = NULL;
	if(first == NULL)
		first = pnewnode;
	else
	{
		/*Attach the node to the end of list */
		NODE_t *last = first;
		while(last->link != NULL)
		{	
			last = last->link;
		}
		last->link = pnewnode;
	}
}

void sort()
{
	NODE_t *pass = first;

	while(pass->link != NULL)
	{
		NODE_t *cur = first;
		NODE_t *next = first->link;

		while(next != NULL)
		{
			if(cur->data > next->data)
			{
				int temp = cur->data;
				cur->data = next->data;
				next->data = temp;
			}
			cur = cur->link;
			next = next->link;
		}
		pass = pass->link;
	}
}

void insertOrder(nodedata_t ele)
{
        NODE_t *newnode = (NODE_t *)malloc(sizeof(NODE_t));
        
		newnode->data = ele;
		newnode->link = NULL;
		if(first == NULL)
			first = newnode;
		else if(ele < first->data)
		{
			newnode->link = first;
			first = newnode;
		}
		else
		{
			NODE_t *temp = first;
			NODE_t *prev;
			while(temp != NULL && temp->data  < ele)
			{
				prev = temp;
				temp = temp->link;
			}	
			prev->link = newnode;
			newnode->link = temp;			
		}
}

void display()
{
	NODE_t *temp = first;
	//printf("%p-->" , temp);
	while(temp != NULL)
	{
		printf("[%d ]-->", temp->data , temp->link);
		temp = temp->link;
	}
}

void displayReverse(NODE_t *temp)
{
	if(temp != NULL)	
	{				
		displayReverse(temp->link);
		printf("[%d | %p]-->", temp->data , temp->link);
	}
}

void deleteFront()
{
	if(first == NULL)
		printf("LIST IS EMPTY ");
	else
	{
		NODE_t  *delnode = first;
		first = first->link;
		free(delnode);
	}
}

void deleteRear()
{
	if(first == NULL)
		printf("LIST IS EMPTY ");
	else
	{
		NODE_t *last = first;
		NODE_t *prev = first;
		while(last->link != NULL)
		{	
			prev = last;
			last = last->link;
		}
		prev->link = NULL;
		free(last);
	}
}

NODE_t * search(int key)
{
	NODE_t *temp = first;
	while(temp != NULL)
	{
		if(temp->data== key)
			break;
		temp = temp->link;
	}	
	return temp;
}

void deleteKey(int key)
{	
	if(first->data == key)
	{
		deleteFront();
	}
	else 
	{
		NODE_t *prev = first;
		NODE_t *cur = first;

		while(cur != NULL && cur->data != key)
		{
			prev = cur;
			cur = cur->link;
		}	

		if(cur != NULL)
		{
			prev->link = cur->link;
			free(cur);
		}
		else
			printf("Key element not found");
	}
}


void reverse()
{
	NODE_t *prev = first;
	NODE_t *cur = first->link;
	NODE_t *next = NULL;

	first->link = NULL;

	while(cur != NULL)
	{
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;			
	}
	first = prev;
}


void nlast(int n)
{
	NODE_t  *p1 = first;
	NODE_t  *p2 = first;
	int i;
	for(i = 0 ; i < n ; i++)
		p1 = p1->link;
	while(p1 != NULL)
	{
		p1 = p1->link;
		p2 = p2->link;
	}
	printf("nth last node = %d " , p2->data);
}


NODE_t * middleNode()
{
	NODE_t *fast = first;
	NODE_t *slow = first;
	
	do
	{
		slow = slow->link;		
		fast = fast->link;
		if(fast)
			fast = fast->link;
	}while(fast != NULL);

	return slow;
}
void checkforLoop()
{
	NODE_t		n1 = {1} ;
	NODE_t		n2 = {2} ;
	NODE_t		n3 = {3} ;
	NODE_t		n4 = {4} ;
	NODE_t		n5 = {5} ;
	NODE_t		n6 = {6} ;
	NODE_t		n7 = {7} ;
	NODE_t		n8 = {8} ;

	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;
	n5.link = &n6;
	n6.link = &n7;
	n7.link = &n8;
	n8.link = &n3;	//Loop

	NODE_t *fast = &n1;
	NODE_t *slow = &n1;
	
	do
	{
		slow = slow->link;		
		fast = fast->link;
		if(fast)
			fast = fast->link;
	}while(fast != NULL && fast != slow);
	if(fast == NULL)
		printf("NO LOOP \n");
	else
		printf("LOOP ");
}

enum {EXIT, INSERTFRONT = 1, INSERTREAR , INSERTORDER , DELETEFRONT , 
 DELETEREAR , DELETEKEY , DISPLAY , DISP_REV, REVERSE , NLAST , MIDDLENODE };

int main()
{	
	int ch;
	nodedata_t ele;
	for(;;)
	{
		printf("%d. INSERT FRONT \n" , INSERTFRONT );
		printf("%d. INSERT REAR \n" , INSERTREAR);
		printf("%d. INSERT ORDER \n" , INSERTORDER);
		printf("%d. DELETE FRONT \n", DELETEFRONT);
		printf("%d. DELETE REAR \n", DELETEREAR);
		printf("%d. DELETE KEY \n", DELETEKEY);
		printf("%d. DISPLAY \n" , DISPLAY);
		printf("%d. DISP_REV \n" , DISP_REV);

		printf("%d. REVERSE \n" , REVERSE );
		printf("%d. Nth Last Node \n" , NLAST );
		printf("%d. MIDDLE NODE  \n" , MIDDLENODE );
		printf("Enter the choice : ");
		scanf(" %d",&ch);

		switch(ch)
		{
		
		case INSERTFRONT : printf("Enter the element to insert : ");
				 scanf(" %d",&ele);
				 insertFront(ele);
				 break;
		case INSERTREAR :  printf("Enter the element to insert : ");
				 scanf(" %d",&ele);
				 insertRear(ele);
				 break;
		case INSERTORDER :  printf("Enter the element to insert : ");
				 scanf(" %d",&ele);
				 insertOrder(ele);
				 break;
		case DELETEFRONT : deleteFront(); break;
		case DELETEREAR : deleteRear(); break;
		case DELETEKEY : printf("Enter the element to delete : ");
				 scanf(" %d",&ele);
				 deleteKey(ele); break;
		case DISPLAY : display(); break;
		case DISP_REV : displayReverse(first); break;
		case REVERSE : reverse(); break;
		case NLAST: printf("Enter the value of n : "); 
					scanf(" %d",&ele);
					nlast(ele);
					break;
		case MIDDLENODE : printf(" %d " ,middleNode()->data);
		default : return 0;
		}
	}
}
