#include <iostream>
#include <time.h>

using namespace std;

// 더 빠르게 하는 방법.
// 월요일 온라인 1시반

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

int** makeIdentity(int n) {
	int** mat = new int*[n];
	for (int i = 0; i< n; i++) {
		mat[i] = new int[n];
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			mat[r][c] = 0;
		}		
		mat[r][r] = 1;
	}
	return mat;
}

int** matmul1(int** m1, int** m2,int** ret, int n) { // n -> original size, m-> parted size
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			for (int i = 0; i < n ; i++) {
				ret[r][c] += m1[r][i] * m2[i][c];
			}
		}
	}
	return ret;
}

int main() {
	// initiallize
	struct timespec begin, end ;
	int** mat1 = makeMAT(2048);
	int** mat2 = makeMAT(2048);
	int** mat3 = makeZero(2048);
	int** matI = makeIdentity(2048);
	int** test1 = makeZero(2048);
	int** test2 = makeZero(2048);
	clock_gettime(CLOCK_MONOTONIC, &begin);
	matmul1(mat1, mat2, mat3, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
	cout << (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0 << endl;

	matmul1(mat1, matI, test1, 2048);
	matmul1(matI, mat1, test2, 2048);
	for (int r = 0; r < 2048; r++) {
		for (int c = 0; c < 2048; c++) {
			if (!(mat1[r][c] == test1[r][c] && mat1[r][c] == test2[r][c] && test1[r][c] == test2[r][c])) {
				cout << r << ", " << c << " takes wrong value [ mat ] vs [ test1 ] vs [ test2 ] : [ " << mat1[r][c] << " ] vs [ " <<
				test1[r][c] << " ] vs [ " << test2[r][c] << " ]\n";
			}
		}
	}
	cout << "TEST DONE\n";
	for (int i = 0; i < 2048; i++) delete[] mat1[i];
	for (int i = 0; i < 2048; i++) delete[] mat2[i];
	for (int i = 0; i < 2048; i++) delete[] mat3[i];
	for (int i = 0; i < 2048; i++) delete[] matI[i];
	for (int i = 0; i < 2048; i++) delete[] test1[i];
	for (int i = 0; i < 2048; i++) delete[] test2[i];
	delete[] mat1;
	delete[] mat2;
	delete[] mat3;
	delete[] matI;
	delete[] test1;
	delete[] test2;
}