#include"new_algo.h"

void main(void) {
	// Initialize the algorithm
	do
	{
		printf("1:アルゴリズム1\n2:アルゴリズム2\n0:終了\n");
		do
		{
			scanf_s("%d", &num);
		} while (num<0);
	
		switch (num)
		{
		case 1:
			Algo_disp();
			break;
		case 2:
			Algo_disp2();
			break;
		default:
			if (num == 0) {
				printf("終了します。\n");
			}
			else {
				printf("1以上の数値を入力してください。\n");
			}
			return;
			break;
		}
		if (num == 0)
			break;
	} while (1);
	
	
}
