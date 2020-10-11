#include <stdio.h>
#include <stdbool.h>

#define SIZE    5

int buffer[ SIZE ] = {0};
int topIndex = -1;

bool isFull()
{
    return topIndex == SIZE - 1;
}
void push(int ele)
{
    if(isFull() == false)
    {
        topIndex = topIndex + 1;
        buffer[topIndex] = ele;
        printf("Element Inserted successfully \n");
    }
    else
        printf("Stack Full\n");
}
bool isEmpty()
{
    return topIndex == -1;
}
int pop( )
{
    int ele = buffer[topIndex];
    buffer[topIndex] = 0;
    topIndex = topIndex - 1;
    return ele;
}
int top( )
{
    int ele = buffer[topIndex];
    return ele;
}

void display()
{
    printf("Elements of Stack \n");
    for(int i = topIndex ; i >= 0 ; i--)
        printf(" %d \n",buffer[i]);

}
int main()
{
    int ch,ele;
    for(;;)
    {
        printf("1.Push 2. Pop 3. Get Top of Stack 4. Display 5. Exit \n");
        printf("Enter  the choice : ");
        scanf(" %d" , &ch);
        switch(ch)
        {
        case 1 : printf("Enter the element to insert : ");
                 scanf(" %d", &ele);
                 push(ele);
                 break;
        case 2 : if(isEmpty() == true)
                    printf("Stack Empty \n");
                else
                    printf("Deleted element is %d \n", pop() );
                break;
        case 3 : if(isEmpty() == true)
                    printf("Stack Empty \n");
                else
                    printf("Top element is %d \n", top() );
                break;
        case 4 : display(); break;
        default : exit(0);
        }
    }
    return 0;
}
