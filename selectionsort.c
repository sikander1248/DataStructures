
#include <stdio.h>
typedef     unsigned int     index_t;

void    readArray(int arr[],int n);
void    printArray(const int arr[],int n);
void    selectionSort(int a[],int n);
void    swap(int *pa,int *pb);
index_t findMax(int arr[],int n);


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

    selectionSort(a , n);

    printf("\n The list after sorting \n");
    printArray(a , n);

}

index_t findMax(int arr[],int n)
{
    int maxIndex = 0;
    for(int i = 1 ; i < n ; i++)
        if(arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

void selectionSort(int arr[],int n)
{
     for(int i = n ; i > 1 ; i--)
    {
        int maxIndex = findMax(arr , i );
        swap(arr[i - 1] , arr[maxIndex]);

        #ifdef PASS
        printf("\nThe elements after %d pass are\n",n - i + 1);
        printArray(arr , n);
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
