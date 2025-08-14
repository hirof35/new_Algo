#ifndef __NEW_ALGO__H__
#define __NEW_ALGO__H__
#include <stdio.h>  
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N2 8
extern int board[N2][N2];
extern int num;
void ComputeLPSArray(char*, int, int*);
void KMP(char*, char*);
void BruteForce(char*, char*);
bool IsSafe(int, int);
bool SolveNqueens(int);
void ConventCase(char*);
double CalculateMedian(int*, int);
int FindMax(int*, int);
int FindMinimun(int*, int);
void Algo_disp(void);
void Algo_disp2(void);

#endif // !__NEW_ALGO__H__
