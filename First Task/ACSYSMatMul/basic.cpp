#include "basic.h"

using namespace std;

int** Basic::makeMAT(int n) {
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

int** Basic::makeIdentity(int n) {
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

int** Basic::makeZero(int n) {
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

bool Basic::isSameResult(int** m1, int** m2, int n) {
	bool ret = true;
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!(m1[i][j] == m2[i][j])) {
				ret = false;
			}
		}
	}
	return ret;
}