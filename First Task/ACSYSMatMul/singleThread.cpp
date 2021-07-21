#include <iostream>
#include <array>

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

int** matmul1(int** m1, int** m2) {
	int n = sizeof(m1);
	int** ret = makeZero(n);
	for (int r = 0; r < n; r++) {
		
	}





	return ret;
}

int main() {
	// initiallize
	int** mat1 = makeMAT(2048);
	int** mat2 = makeMAT(2048);
	int** mat3 = makeZero(2048);


}