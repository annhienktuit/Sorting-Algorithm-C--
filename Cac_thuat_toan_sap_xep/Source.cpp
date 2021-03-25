#include <bits/stdc++.h>
using namespace std;

void input(int A[], int n)
{
	cout << "Input array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
}
void output(int A[], int n)
{
	cout << "The sorted array is: ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i]<<" ";
	}
}
void selectionsort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
				
			}
		swap(arr[min_idx], arr[i]);
	}
}
void bubblesort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void insertionsort(int A[], int n)
{
	int key;
	for (int i = 0; i < n; i++)
	{
		key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;

	}
}
void shellSort(int a[], int n) {
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2) {
		for (i = interval; i < n; i++) {
			temp = a[i];
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main() {
	int* A = new int[100];
	int n,k;
	cout << "Input the size of array: \n";
	cin >> n;
	input(A, n);
	cout << "Choose the sorting algorithm:" << endl << "1.Bubble Sort" << endl << "2.Selection Sort"<<endl<<"3.Insertion Sort"<<endl<<"4.Shell Sort"<<endl<<"5.Quick Sort"<<endl;
	cin >> k;
	switch (k) {
	case 1:
		bubblesort(A, n); break;
	case 2:
		selectionsort(A, n); break;
	case 3:
		insertionsort(A, n); break;
	case 4:
		shellSort(A, n); break;
	case 5:
		quickSort(A, 0, n - 1); break;
	}
	
	output(A, n);
	delete[] A;
}
