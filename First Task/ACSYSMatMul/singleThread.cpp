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
	cout << "a\n";
	int** mat1 = makeMAT(2048);
	cout << "b\n";
	int** mat2 = makeMAT(2048);
	cout << "c\n";
	int** mat3 = matmul1(mat1, mat2, 2048);
	cout << "d\n";

	int** test1 = makeMAT(15);
	int** test2 = makeMAT(15);
	int** test3 = matmul1(test1, test2, 15);

	for(int i = 0 ;i < 15; i++) {
		for (int j = 0 ;j < 15; j++) {
			cout << test1[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "=====================================\n";
	for(int i = 0 ;i < 15; i++) {
		for (int j = 0 ;j < 15; j++) {
			cout << test2[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "=====================================\n";
	for(int i = 0 ;i < 15; i++) {
		for (int j = 0 ;j < 15; j++) {
			cout << test3[i][j] << " ";
		}
		cout << '\n';
	}

}