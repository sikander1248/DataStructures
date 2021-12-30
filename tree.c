#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef  int nodedata_t;

typedef struct node
{
	struct node *llink;
	nodedata_t	data;
	struct node *rlink;
}NODE_t;

NODE_t *root = NULL;

void insert(nodedata_t ele);
void inorder(NODE_t *root);
void preorder(NODE_t *root);
void postorder(NODE_t *root);
void deleteNode(int key);
int countLeaf(NODE_t *root);
int height(NODE_t *root);
void displayDescending(NODE_t *root);

static bool isleaf(NODE_t *node);
static bool hasOnlyRight(NODE_t *root);
static bool hasOnlyLeft(NODE_t *root);

void insert(nodedata_t ele)
{
	NODE_t *pnewnode = (NODE_t *)calloc(sizeof(NODE_t) , 1);
	pnewnode->data = ele;

	if(root == NULL)
		root = pnewnode;
	else
	{
		NODE_t *ptrav = root;
		while(1)
		{
			if(ele > ptrav->data)
			{
				if(ptrav->rlink == NULL)
				{
					ptrav->rlink = pnewnode;
					break;
				}
				else
					ptrav = ptrav->rlink;
			}
			else
			{
				if(ptrav->llink == NULL)
				{
					ptrav->llink = pnewnode;
					break;
				}
				else
					ptrav = ptrav->llink;
			}
		}
	}
}

void inorder(NODE_t *root)
{
	if(root)
	{
		inorder(root->llink);
		printf(" %d " , root->data);
		inorder(root->rlink);
	}
}

void preorder(NODE_t *root)
{
	if(root)	{
		printf(" %d " , root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}
void postorder(NODE_t *root)
{
	if(root)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf(" %d " , root->data);
	}
}

int height(NODE_t *root)
{
	if(root == NULL)
		return 0;
	if(root->rlink == NULL && root->llink == NULL)
		return 1;
	else
	{
		int x = height(root->llink);
		int y = height(root->rlink);
		return 1 + ((x > y) ? x : y);
	}
}

int countLeaf(NODE_t *root)
{
	if(root == NULL)
		return 0;
	if(root->rlink == NULL && root->llink == NULL)
		return 1;
	else
	{
		return countLeaf(root->llink) + countLeaf(root->rlink);
	}
}

void displayDescending(NODE_t *root)
{
    if(root == NULL)
        return;
    displayDescending(root->rlink);
    printf(" %d" , root->data);
    displayDescending(root->llink);
}

bool hasOnlyLeft(NODE_t *root){
    return root->llink != NULL && root->rlink == NULL;
}
bool hasOnlyRight(NODE_t *root){
    return root->llink == NULL && root->rlink != NULL;
}
bool isleaf(NODE_t *root)
{
    if(root->rlink == NULL && root->llink == NULL)
        return true;
    else
        return false;
}

void deleteNode(nodedata_t key){
    if(root == NULL){
        printf("Tree is empty");
        return ;
    }

    if(root->data == key){
        printf("Trying to delete root...Not implemented");
        return;
    }
    /* Search for the key node also keep track of its parent node */
    NODE_t *parent = NULL;
    NODE_t *current = root;

    while(current != NULL){
        if(current->data == key)
        {
            break;
        }
        else if(key > current->data)
        {
            parent = current;
            current = current->rlink;
        }
        else if(key < current->data)
        {
            parent = current;
            current = current->llink;
        }
    }

    if(current != NULL){
        if(isleaf(current) == true){
            if(parent->llink == current){
                parent->llink = NULL;
            }
            else{
                parent->rlink = NULL;
            }
        }
        else if(hasOnlyLeft(current))   //contains left child
        {
            if(parent->llink == current){
                parent->llink = current->llink;
            }
            else{
                parent->rlink = current->llink;
            }
        }
        else if(hasOnlyRight(current)){
            if(parent->llink == current)
            {
                parent->llink = current->rlink;
            }
            else{
                parent->rlink = current->rlink;
            }
        }
        else{
            printf("Has both left and right child Not yet \
                   implemented");
        }
    }
}
#if 1
int findMax(NODE_t *root)
{
    if(root->rlink == NULL)
        return root->data;
    findMax(root->rlink);
}
#else
int findMax(NODE_t *root)
{
    printf("Findmax using loop \n");
    while(root->rlink != NULL)
        root = root->rlink;
    return root->data;
}
#endif
#if 1
int findMin(NODE_t *root)
{
    if(root->llink == NULL)
        return root->data;
    findMax(root->llink);
}
#else
int findMin(NODE_t *root)
{
    printf("Findmin using loop \n");
    while(root->llink != NULL)
        root = root->llink;
    return root->data;
}
#endif
int main()
{
    int arr[] = {23,21,6,38,45,3,9,4,29,25,34};
    int n = sizeof(arr) / sizeof(int);
    for(int i = 0 ; i < n ; i++)
        insert(arr[i]);
    printf("\n Elements of Tree : Inorder Traversal \n ");
    inorder(root);
    printf("\n Elements of Tree : Preorder Traversal \n ");
    preorder(root);
    
    int large = findMax(root);
    printf("\n Largest element of tree :  %d \n", large);
    
}
