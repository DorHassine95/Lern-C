#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int* creatArray(int);
void PrintArray(int*);
int swap(int*, int*);
void inputArray(int*, int);
void arrCalc(int*, int, int*, int*, int*, double*, int*);
int ArrayMinMiss(int*, int);
int *Fibonacci(int);
int* IsEven(int*, int,int);
int* Cartesianproduct(int*, int*);
int* MostOfTime(int*,int,int*);
int* EqualsValueTime(int*,int,int);

void main() {
	int arr[6] = { 1,3,2,3,2,2 };
	printf("%d", EqualsValueTime(arr, 6, 3));
}

//creat a new arr
int *creatArray(int size) {
	int* arr = (int*)malloc(size * (sizeof(int)));
	for (int i = 0; i < size; i++) {
		printf("Enter your value #%d:",i+1);
		scanf_s("%d", &arr[i]);
	}
	return arr;
}
//print all the array
void PrintArray(int *arr) {
	printf("%d ,", arr[0]);
	for (int i = 1; i <= sizeof(arr); i++) {
		printf(" %d ", arr[i]);
		printf(" , ");
	}
	printf("%d ", arr[sizeof(arr)+1]);
}
//swap function
int swap(int* a, int* b) {
	int temp = *b; *b = *a;
	*a = temp;
}
//to srarted array
void inputArray(int *arr, int n) {
	printf("Enter your value:\n");
	for (int i = 0; i < n; i++){
		scanf_s(" %d ", &arr[i]);
}
	PrintArray(arr);
}
//The passt the max valus in the array, min, average,sum. 
void arrCalc(int* arr, int n, int* max, int* min, int* sum, double* avg, int* isEven) {
	int	tmin =0;
	int tmax =0;
	int tsum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < tmin) {
			tmin = arr[i];
		}
		if (arr[i] > tmax) {
			tmax = arr[i];
		}
		tsum += arr[i];	
		if ((arr[i] % 2) == 0) {
			*isEven = 1;
		}
	}
	*max = tmax;
	*min = tmin;
	*sum = tsum;
	*avg = (double)tsum / n;
}
//if the series Absolutely rising return 1 and pass 1,
//if the series rising or equal return 1 and pass 0
//if the series not rising or equals return 0 and pass 0

int UpSer(int* arr, int n, int* res) {
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[i + 1]) {
			*res = 0;
			return 0;
		}
		if (arr[i] = arr[i + 1]) {
			*res = 0;
			return 1;
		}
	}
	*res = 1;
	return 1;
}
//Dynamic memory mission
//int DynamicM(int size) {

//}
//--function that get a array and his size and return the min missing value 
//in array---
//selution: 
	//we get n of value, so with the missing vlaue
	//we have n+1
int ArrayMinMiss(int* arr, int size) {
	int i;
	int* arrtemp = (int*)calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++) {
		arrtemp[arr[i]]++;
	}
	for (i = 0; i <= size; i++) {
		if (arrtemp[i] == 0) {
			free(arrtemp);
			return i;
		}
	}
}
//The function return a array with all fibonacci value untill n///
int* Fibonacci(int n) {
	int* arr = (int*)malloc(n + 1 * sizeof(int));
	if (n >= 0) {
		arr[0] = 0;
	}
	if (n >= 1) {
		arr[1] = 1;
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr;
	}
}
// the function get array and value 1 or 0, if "isEvan" (variable) ==1:
//return new array with just the even number of arr, and passt the leght of him/
//isEven==0 : new array with odd numbers and passt the leght.

int* IsEven(int* arr, int n, int isEven) {
	int counter = 0;
	if (isEven == 1) {
		for (int i = 0; i < n; i++) {
			if ((arr[i] % 2) == 0) {
				counter++;
			}
			int* newarr = (int*)malloc(counter * sizeof(int));
			for (int j = 0; j < counter; j++) {
				if ((arr[i] % 2) == 0)
					newarr[j] = arr[i];
			}
		}


	}
}
int* Cartesianproduct(int* a, int* b) {
	if (sizeof(a) != sizeof(b)) {
		return 0;
	}
	int size = sizeof(a) / 4;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

		}
	}
}
	//function that riturn the most value apperent and the number of time show
	//0--->9
	int* MostOfTime(int* arr, int size, int* a) {
		int i, max=0, counter;
		int* count = (int*)calloc(10, sizeof(int));
		for (i = 0; i < size; i++) {
			count[arr[i]]++;
		}
	*a = count[0];
		for (i = 1; i < 10; i++) {
			if (count[max] < count[i]) {
				max=i;
				*a = count[max];
			}
		}
		free(count);
		return max;
	}
	//function that return 1 if the number of time show number equals to his value
	int* EqualsValueTime(int* arr, int n,int k) {
		int i;
		int* count = (int*)calloc((k+1), sizeof(int));
		for (i = 0; i < n; i++) {
			count[arr[i]]++;
	}
		for (i = 0; i < k + 1; i++) {
			if (count[i] != i) {
				free(count);
				return 0;
			}
	}
		free(count);
		return 1;
	}
