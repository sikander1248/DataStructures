/* GIVEN TWO SORTED ARRAYS A & B, FIND  A - B(DIFFERENCE OF TWO ARRAYS). */ 
 
#include <vector>
#include <iostream>

using namespace std;
 
void readArray(int arr[],int n)
{    
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
}

void printArray(int arr[],int n)
{    
	for(int i = 0 ; i < n ; i++)
		cout << arr[i] <<" ";
}

void remove(int arr[],int n)
{
	for(int i = 0 ; i < n ; i++)
		arr[i] = arr[i + 1];
}

void findDifference_1(int a[],int n,const int b[],int m)
{
	int i = 0 ; 
	int j = 0;
	
	while(i < n && j < m)
	{
		if(a[i] == b[j]){
			remove(a + i, n - i );
			n--;
		}
		if(a[i] < b[j])
			i++;
		else if(a[i] > b[j])
			j++;
	}
	printArray(a , n);
}

void findDifference_2(const int a[],int n,const int b[],int m)
{
	int i = 0 ; 
	int j = 0;
	vector<int>	 result;
	while(i < n && j < m)
	{
		if(a[i] == b[j]){
			i++;
			j++;
		}
		if(a[i] < b[j])
		{	
			result.push_back(a[i]);
			i++;
		}
		else if(a[i] > b[j])
			j++;
	}
	while(i < n)
		result.push_back(a[i++]);

	for(int ele : result)
		cout << ele << " ";
}

int main( )
{
  int n , m;
  cout <<"Enter the number of elements in first set (sorted) " ;
  cin >> n;
	int  a[n] ;
  
  cout <<"Enter the number of elements in second set (sorted) " ;
  cin >> m;
  int b[m];
	 
	cout <<"Enter the elements of Set A ";
	readArray(a , n);
	
	cout <<"Enter the elements of Set B ";
	readArray(b , m);

	findDifference_2(a , n ,  b , m);
}
