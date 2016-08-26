#include <stdio.h>

void bubbleSort(int a[],int n);
void printArray(const int a[],int n);
void readArray(int a[],int n);
void swap(int *pa,int *pb);

int main()
{
        int n;
        printf("\n ENTER THE NO. OF ELEMENTS : ");
        scanf(" %d",&n);

        int a[n];
        printf("\n ENTER THE ELEMENTS OF ARRAY (%d) ",n);
        readArray(a,n);
        printf("\n THE ARRAY ELEMENTS ARE \n");
        printArray(a , n);

        bubbleSort(a , n);

        printf("\n The list after sorting \n");
        printArray(a , n);

        return 0;
}

void bubbleSort(int a[],int n)
{
    for(int pass = 1 ; pass < n ; pass++) {
        for(int cmp = 0 ; cmp < n - pass ; cmp++) {
            if(a[cmp] > a[cmp+1]) {
                swap(&a[cmp] , &a[cmp+1]);
            }
        }
        #ifdef PASS
                printf("\nThe elements after %d pass are\n",pass);
                printArray(a,n);
        #endif
    }
}

void swap(int *pa,int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void readArray(int a[],int n)
{
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&a[i]);
    }
}
void printArray(const int a[],int n)
{
    for(int i = 0 ; i < n ; i++) {
        printf("%d ",a[i]);
    }
}
