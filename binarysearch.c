#include <stdio.h>
#include <stdbool.h>

int binarySearch(int arr[], int start, int end, int findingElement);

int main()
{
	int arr[] =  {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
	int findingElement = 18;
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, size, findingElement);
	if(result != -1)
	{
		printf("Found: %d", result);
	}
	else
	{
		printf("Not found");
	}
}

int binarySearch(int arr[], int start, int end, int findingElement)
{
	if(end >= 1){
	int mid = start + (end - start) / 2;
	if(arr[mid] == findingElement)
		return mid;
	else if(arr[mid] > findingElement)
		return binarySearch(arr, 0, mid - 1, findingElement);
	else
		return binarySearch(arr, mid+1, end, findingElement);
	}
	else
	{
		return -1;
	}
}
