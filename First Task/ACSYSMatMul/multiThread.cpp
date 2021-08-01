#include <iostream>
#include <thread>
#include <time.h>
#include <vector>

// init, alloc 분리 ok
// 뻔한 data로 singlethread검증 ok --> Identity Matrix로 검증

// 복잡한 data로 multithread검증
// mat 다양하게 자르기


// makefile
//.o * .o -> exe

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

void multiply(int** m1,int** m2, int** ret, int n, int startrow, int endrow, int startcol, int endcol) {
    for (int r = startrow; r < endrow; r++) {
        for (int c = startcol; c < endcol; c++) {
            for (int i = 0; i < n; i++) {
                ret[r][c] += m1[r][i] * m2[i][c];
            }
        }
    }
}

int** matmul2(int** m1, int** m2, int** ret, int n) { // n -> original size
    try {
        vector<thread> threads;
        int r1, r2, r3;
        int c1, c2, c3;
        r1 = n/4; // 512
        r2 = r1*2; // 1024
        r3 = r1*3; // 1536 ,, 2048
        c1 = n/4;
        c2 = c1*2;
        c3 = c1*3;

        threads.emplace_back(multiply, m1, m2, ret, n, 0, r1, 0, c1);
        threads.emplace_back(multiply, m1, m2, ret, n, r1, r2, c1, c2);
        threads.emplace_back(multiply, m1, m2, ret, n, r2, r3, c2, c3);
        threads.emplace_back(multiply, m1, m2, ret, n, r3, n, c3, n);

        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return ret;
    }
    catch (exception ex) {
        throw ex;
    }
	return ret;
}

int main() {
	// initiallize
	struct timespec begin, end ;


	int** mat1 = makeMAT(2048);
	int** mat2 = makeMAT(2048);
	int** mat3 = makeZero(2048);
    // FIXME
	clock_gettime(CLOCK_MONOTONIC, &begin);
	mat3 = matmul2(mat1, mat2, mat3, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    // FIXEND
	cout << (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0 << endl;
	for (int i = 0; i < 2048; i++) delete[] mat1[i];
	for (int i = 0; i < 2048; i++) delete[] mat2[i];
	for (int i = 0; i < 2048; i++) delete[] mat3[i];
	delete[] mat1;
	delete[] mat2;
	delete[] mat3;
}
  