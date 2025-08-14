#include"new_algo.h"
int num=0;
double CalculateMedian(int* arr, int size) {
	double median;
	int mid = size / 2;
	if(size % 2 == 0) {
		median = (arr[mid - 1] + arr[mid]) / 2.0;
	} else {
		median = arr[mid];
	}
	return median;
}
int FindMax(int* arr, int size) {
	int max = arr[0];
	for(int i = 1; i < size; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
int FindMinimun(int* arr, int size) {
	int min = arr[0];
	for(int i = 1; i < size; i++) {
		if(arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void Algo_disp2(void) {
	do
	{
		printf("1.CalculateMedian\n2.findMax\n3,findMin\n0.exit\n");
		do
		{
			scanf_s("%d", &num);
		} while (num<0);
	
		switch (num)
		{
			case 1:
				printf("CalculateMedian number:\n");
				int n[] = { 4,7,2,6,5 };
				int size = sizeof(n) / sizeof(n[0]);
				double num = CalculateMedian(n, size);
				printf("CalculateMedian number: %lf\n", num);
				break;
			case 2:
				printf("FindMax number:\n");
				int arr[] = { 4,7,2,6,5 };
				int max = FindMax(arr, sizeof(arr) / sizeof(arr[0]));
				printf("Max number: %d\n", max);
				break;
			case 3:
				printf("FindMin number:\n");
				int arr2[] = { 4,7,2,6,5 };
				int min = FindMinimun(arr2, sizeof(arr2) / sizeof(arr2[0]));
				printf("Min number: %d\n", min);
				break;
			default:
				if (num == 0) {
					printf("Exiting...\n");
					printf("終了します。\n");
					// Exit the function if 0 is entered
					// 関数を終了します。
				}
				else {
					printf("1以上の数値をにゅうりょくしてください。\n");
					printf("Please input a number greater than 1.\n");
				}
				break;
				if (num == 0)
					break;
				return;
		}
	} while (1);
}
