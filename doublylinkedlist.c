#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node 	*llink;//pointer to previous node(left side)
	int 		 data;
	struct Node 	*rlink;//pointer to next node(right side)
}Node_t;

Node_t * createNode(int ele);
void attachFront(Node_t *newNode);

void insertFront(int ele);
void insertRear(int ele);
void insertOrder(int ele);

void deleteFront(void);
void deleteRear();
void deleteKey(int key);
void display(void);

Node_t *first = NULL;

Node_t * createNode(int ele)
{
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));

    if(newNode == NULL)
    {
        printf("Unable to Allocate Memory");
        return NULL;
    }
    newNode->data = ele;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    return newNode;
}
void attachFront(Node_t *newNode)
{
    if(first == NULL)
        first = newNode;
    else{
        first->llink = newNode;
        newNode->rlink = first;

        first = newNode;
    }
}
void insertFront(int ele)
{
    Node_t *newNode = createNode(ele);

    attachFront(newNode);
}

void deleteKey(int key)
{
    if(first == NULL)
    {
        printf("List is Empty...\n"); return ;
    }
    if(first->data == key)
        deleteFront();
    else
    {
        Node_t  *cur = first;
        while(cur != NULL && cur->data != key)
        {
            cur = cur->rlink;
        }
        if(cur == NULL)
            printf("Key element NOT found");
        else
        {
            printf("Key element found");
            Node_t  *prev = cur->llink;
            Node_t  *next = cur->rlink;

            prev->rlink = next;
            if(next != NULL)
                next->llink = prev;

            free(cur);
        }
    }
}

void insertOrder(int ele)
{
    Node_t *newNode = createNode(ele);

    //Attach node to list.
    if(first == NULL || ele < first->data){
        attachFront(newNode);
    }
    else{
        struct Node *cur = first;

        while(cur->rlink != NULL && cur->data < ele)
        {
            cur = cur->rlink;
        }

        if(cur->data < ele)
        {
            newNode->llink = cur;
            cur->rlink = newNode;
        }
        else{
            Node_t *prev = cur->llink;

            prev->rlink = newNode;
            newNode->llink = prev;

            newNode->rlink = cur;
            cur->llink = newNode;
        }

        //
    }
}

void insertRear(int ele)
{
    Node_t *newNode = createNode(ele);

    //Attach node to list.
    if(first == NULL)
        first = newNode;
    else{
        //Traverse to last Node.
        Node_t *last = first;
        while(last->rlink != NULL)
        {
            last = last->rlink;
        }
        last->rlink = newNode;
        newNode->llink = last;
    }
}
void deleteFront(void)
{
    if(first == NULL)
    {
        printf("List is Empty");
        return;
    }
    Node_t *delNode = first;

    first = first->rlink;
    if(first != NULL)
        first->llink = NULL;

    free(delNode);
}

void deleteRear()
{
	if(first == NULL)
		printf("LIST IS EMPTY ");
	else if(first->rlink == NULL) //if there is only one node
        deleteFront();
    else
	{
		Node_t *last = first;

		while(last->rlink != NULL)
		{
			last = last->rlink;
		}
		Node_t *prev = last->llink;

		prev->rlink = NULL;
		free(last);
	}
}
void display(void)
{
    Node_t *temp = first;
    while(temp != NULL)
    {
        printf(" %d-->" , temp->data);
        temp = temp->rlink;
    }
}
int main( )
{
    insertRear(20);
    insertRear(26);
    insertRear(34);

    insertOrder(38);

    printf("List of elements after deleting first element \n");
    display();

    insertOrder(30);
    printf("\n List of elements after deleting first element \n");
    display();
}
