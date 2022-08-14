#include<stdio.h>
#include<malloc.h>

void bubble_sort(int*,int);
void selection_sort(int*,int);
void insertion_sort(int*,int);
void swap(int*, int*);
//quastion
void DinamicSort(int*,int);
void sortEvenOdd(int*,int);
int ValueEquIndex(int*,int);
int ValueEquIndex2(int*,int);
int indexKey(int,int*,int);


void main() {
	int a[8]={ 9, 7, 7, 5, 3, 3, 3, 1 };
	int b[8] = { 9, 7, 7, 5, 3, 3, 3, 1 };
	printf("%d\n", indexKey(3, &a, 8));
	printf("%d\n", indexKey(4, &b, 8));
}


void bubble_sort(int* a, int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}
void selection_sort(int* a, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[n - i - 1]) {
				swap(&a[j], &a[n - i - 1]);
			}
		}
	}
}
void insertion_sort(int* a, int n) {
	int i,j, tmp;
	for (j = 1; j < n; j++) {
		i = j - 1;
		tmp = a[j];
		while ((i >= 0) && (tmp < a[i])) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = tmp;
	}
}
void swap(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}
/////////////q1////////////////
void DinamicSort(int* arr, int size) {
	int j = 0,i=0;
	int count[10] = {0};
	for (int i = 0; i < size; i++) {
		count[arr[i]++];
		while(count[i]) {
			arr[j++] = i;
			count[i]--;
		}
	}
}
//////////////////q2//////////////
void sortEvenOdd(int* a, int n)
{
	int i, last =n -1;

	for (i = 0; i < n; i++)
		if (a[i] % 2 == 0) //even
			swap(a + (last++), a + i);
}
////////////////q3///////////////
//get a sorted array and size, find if there 
//is a vlaue that equls to his index
//O n and logn
int ValueEquIndex(int* a,int n){
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == i) {
			return 1;
		}
	}
	return -1;
}
int ValueEquIndex2(int* a, int n) {
	int high=n-1, low=0, mid=n/2;
while(low<high){
		if (a[mid] == mid) {
			return 1;
		}
		if (a[mid] > mid) {
			high=mid;
			mid = (high + low) / 2;
		}
		if (a[mid] < mid) {
			low = mid+1;
			mid = (high + low) / 2;
		}
	}
	return -1;
}
//find the index of key in array, the array sorted by big-->small
int indexKey(int key, int* a, int n) {
	int i, low = 0, high = n - 1;
	int mid = (high + low) / 2;
	while (low < high) {
		if (a[mid] == key) {
			return mid;
		}
		if (a[mid] > key) {
			low = mid + 1;
			mid= (high + low) / 2;
		}
		if (a[mid] < key) {
			high = mid - 1;
			mid = (high + low) / 2;
		}
	}
	return -1;
}
