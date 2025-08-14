 
#include "new_algo.h"  
int board[N2][N2] = { 0 };

void ComputeLPSArray(char* pattern, int M, int* Ips) {  
    int len = 0; // Initialize len  
    Ips[0] = 0; // LPS[0] is always 0  
    int i = 1;  
    while (i < M) {  
        if (pattern[i] == pattern[len]) {  
            len++;  
            Ips[i] = len;  
            i++;  
        } else {  
            if (len != 0) {  
                len = Ips[len - 1];  
            } else {  
                Ips[i] = 0;  
                i++;  
            }  
        }  
    }  
}  

void KMP(char* text, char* pattern) {  
    int M = strlen(pattern);  
    int N = strlen(text);  
    int* Ips = (int*)malloc(M * sizeof(int)); // Dynamically allocate memory for LPS array  
    if (Ips == NULL) {  
        printf("Memory allocation failed\n");  
        return;  
    }  
    ComputeLPSArray(pattern, M, Ips);
	int i = 0; // Index for text
	int j = 0; // Index for pattern
    while (i < N) {  
        if (pattern[j] == text[i]) {  
            i++;  
            j++;  
        }  
        if (j == M) {  
            printf("Found pattern at index %d\n", i - j);  
            j = Ips[j - 1]; // Reset j using LPS array  
        } else if (i < N && pattern[j] != text[i]) {  
            if (j != 0) {  
                j = Ips[j - 1]; // Use LPS to skip characters in pattern  
            } else {  
                i++; // Move to next character in text  
            }  
        }  
	}
    free(Ips); // Free allocated memory  
}
void BruteForce(char* text, char* pattern) {
	int textLength = strlen(text);
	int patternLength = strlen(pattern);
    for (int i = 0; i <= textLength - patternLength + 1; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, break inner loop
            }
        }
        if (j == patternLength) { // If we reached the end of the pattern
            printf("Found pattern at index %d\n", i);
        }
    }
}
bool IsSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) {
        if(board[row][i])
			return false; // Check row
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j])
            return false; // Check upper diagonal
    }
	for (i = row, j = col; j >= 0 && i < N2; i++, j--) {
        if (board[i][j])
            return false; // Check lower diagonal
    }
	return true; // Safe to place queen
}
bool SolveNqueens(int col) {
    if(col>=N2)
      return true; // All queens placed successfully
    for (int i = 0; i < N2; i++) {
        if (IsSafe(i, col)) {
            board[i][col] = true; // Place queen
            if (SolveNqueens(col + 1)) // Recur to place next queen
                return true;
            board[i][col] = false; // Backtrack if placing queen doesn't lead to a solution
        }
    }
}
void ConventCase(char* str) {
    while (*str) {
        if (islower(*str)) {
            printf("%c",toupper(*str)); // Convert to uppercase
        }
        else if (isupper(*str)) {
            printf("%c", tolower(*str)); // Convert to lowercase
        }
        else {
			printf("%c", *str); // Print non-alphabetic characters unchanged
        }
		str++; // Move to the next character
    }
}
void Algo_disp(void) {
	char text[] = "ABABDABACDABABCABAB";
	char pattern[] = "ABABCABAB";
    do
    {
		printf("Select algorithm:\n1. KMP\n2. Brute Force\n3, SloveNQueens \n4.ConventCase\n0 or. Exit\n");
        do
        {
            scanf_s("%d", &num);
        } while (num<0);
        switch (num)
        {
        case 1:
            printf("Using KMP algorithm:\n");
            KMP(text, pattern);
			break;
        case 2:
            printf("Using Brute Force algorithm:\n");
			BruteForce(text, pattern);
            break;
		case 3:
            printf("Solving N-Queens problem:\n");
            if (SolveNqueens(0)) {
                printf("Solution found:\n");
                for (int i = 0; i < N2; i++) {
                    for (int j = 0; j < N2; j++) {
                        if (board[i][j])
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            } else {
                printf("No solution exists.\n");
            }
			break;
        case 4:
            printf("Converting case:\n");
            char str[] = "Hello World!"; // Example string
            ConventCase(str);
            printf("\n");
			break;
        default:
            printf("Exiting...\n");
            return;
            break;
        }
    } while (1);
	
}
