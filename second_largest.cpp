//Program to find second largest Element in an array.
#include <iostream>
using namespace std;
void readArray(int arr[],int n)
{
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
}
// finds the second largest with complexity of O(n)
int findSecondLargest_n(int arr[],int  n)
{
	int secondLargest = arr[0];
	int largest = arr[1];
	if(largest < secondLargest)
		secondLargest = largest;

	for(int i = 2 ; i < n ; i++){
		if(arr[i] > largest){
			secondLargest = largest;
			largest = arr[i];
		}
		else if(arr[i] > secondLargest)
			secondLargest = arr[i];
	}

	return secondLargest;
}

// finds the second largest with complexity of O(2 n )
int findSecondLargest_2n(int arr[],int n)
{
	int maxIndex = 0;
	
	for(int i = 0 ; i < n ; i++)
		if(arr[i] > arr[maxIndex])
			maxIndex = i;
      
	int secMaxIndex;
	if(maxIndex == 0)
		secMaxIndex = 1;
	else
		secMaxIndex = 0;

	for(int i = 0 ; i < n ; i++)
		if(i != maxIndex && arr[i] > arr[secMaxIndex])
			secMaxIndex = i;
	return arr[secMaxIndex];
}

int main( )
{
	int n;
	cout << "Enter number of elements : ";
	cin >> n;

	int *arr = new int[n];
	
	cout <<"Enter the elements of array : ";
	readArray(arr , n);
	 
	cout <<"Second Largest Element is " <<
		     findSecondLargest_n(arr , n) << endl;
	
	delete [] arr;
	return 0;
}
