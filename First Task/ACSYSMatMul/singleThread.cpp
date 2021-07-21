#include <iostream>
#include <array>
#include <algorithm>
#define MATSIZE 2048

using namespace std;

int** makeMAT(int n) {
	int** mat = new int*[n];
	for (int i = 0 ;i < n; i++) {
		mat[i] = new int[n];
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			mat[r][c] = rand() % 10 - 4;
		}
	}
}

int main() {
	// initiallize
	int** mat1 = new int*[MATSIZE];
	int** mat2 = new int*[MATSIZE];
	int** mat3 = new int*[MATSIZE];
	for (int i = 0 ; i < MATSIZE; i++) {
		mat1[i] = new int[MATSIZE];
		mat2[i] = new int[MATSIZE];
		mat3[i] = new int[MATSIZE];
	}
	for (int r = 0; r < MATSIZE; r++) {
		for (int c = 0; c < MATSIZE; c++) {
			mat1[r][c] = rand() % 10 - 4;
			mat2[r][c] = rand() % 10 - 4;
			mat3[r][c] = 0;
		}
	}
}