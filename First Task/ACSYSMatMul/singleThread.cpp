#include <iostream>
#include <time.h>

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
	return mat;
}

int** makeZero(int n) {
	int** mat = new int*[n];
	for (int i = 0; i < n ;i++) {
		mat[i] = new int[n];
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n ; c++) {
			mat[r][c] = 0;
		}
	}
	return mat;
}

int** matmul1(int** m1, int** m2, int n) {
	int** ret = makeZero(n);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			for (int i = 0; i < n ; i++) {
				ret[r][c] += m1[r][i] * m2[i][c];
			}
		}
	}
	cout << "done\n";
	return ret;
}

int main() {
	// initiallize
	clock_t start, end;
	int** mat1 = makeMAT(2048);
	int** mat2 = makeMAT(2048);
	start = clock();
	int** mat3 = matmul1(mat1, mat2, 2048);
	end = clock();
	cout << "Time : " << (double)(end - start) << " ms. \n";
}