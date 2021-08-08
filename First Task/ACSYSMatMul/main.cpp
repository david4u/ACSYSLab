#include "multi.h"
#include "single.h"
#include "basic.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
    // times[] -> single, single^T, multi~
    double times[11];
    int** matA, matB, matI, matBT;
    int** ret11, ret12, ret13, ret14, ret21, ret22, 
        ret23, ret24, ret25, ret26, ret27, ret28, ret29;
    int size = 2048;
    Basic* basic;
    Single* single;
    Multi* multi;

    // Make Matrices

    // Random elements matrix
    matA = basic->makeMAT(size);
    matB = basic->makeMAT(size);

    // Identity Matrix
    matI = basic->makeIdentity(size);

    // Empty (Zero) Matrix
    ret11 = basic->makeZero(size);
    ret12 = basic->makeZero(size);
    ret13 = basic->makeZero(size);
    ret14 = basic->makeZero(size);
    ret21 = basic->makeZero(size);
    ret22 = basic->makeZero(size);
    ret23 = basic->makeZero(size);
    ret24 = basic->makeZero(size);
    ret25 = basic->makeZero(size);
    ret26 = basic->makeZero(size);
    ret27 = basic->makeZero(size);
    ret28 = basic->makeZero(size);
    ret29 = basic->makeZero(size);

    //single thread A x B = ret11
	clock_gettime(CLOCK_MONOTONIC, &begin);
	single->matmul(matA, matB, ret11, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
	times[0] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    // single thread A x I = ret12
	single->matmul(matA, matI, ret12, 2048);

    // single thread I x A = ret13
	single->matmul(matI, matA, ret13, 2048);

    // For validatoin ret12 == ret13 == matA
    bool valid = true;
    for (int i = 0; i < n ;i++) {
        for int j = 0 ; j < n; j++) {
            if ( !( (ret12[i][j] == ret13[i][j]) && (ret12[i][j] == matA[i][j]) ) ) {
                valid = false;
            }
        }
    }
    if (valid) {
        cout << "Single Thread is correct!\nNow ret11 is standard\n";
    } else {
        cout << "Single Thread is incorrect\nT_T\n";
    }

    // single thread transpose A x B = ret14
	clock_gettime(CLOCK_MONOTONIC, &begin);
    single->transmatmul(matA, matB, ret14, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
	times[1] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret14, 2048)) {
        cout << "Transpose matmul is correct\n";
    } else {
        cout << "Transpose matmul is incorrect\n";
    }

    // multi matmul. But ret21 is same with single
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul1(matA, matB, ret21, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
	times[2] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret21, 2048)) {
        cout << "Multi Thread matmul1 is correct\n";
    } else {
        cout << "Multi Thread matmul1 is incorrect\n";
    }
    
    // multi matmul. Ret22 is 1x2
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul2(matA, matB, ret22, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
	times[3] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret22, 2048)) {
        cout << "Multi Thread matmul2 is correct\n";
    } else {
        cout << "Multi Thread matmul2 is incorrect\n";
    }




    // Delete Matrices
    for (int i = 0; i < 2048; i++) delete[] matA[i];
	for (int i = 0; i < 2048; i++) delete[] matB[i];
	for (int i = 0; i < 2048; i++) delete[] matI[i];
	for (int i = 0; i < 2048; i++) delete[] matBT[i];
	for (int i = 0; i < 2048; i++) delete[] ret11[i];
	for (int i = 0; i < 2048; i++) delete[] ret12[i];
    for (int i = 0; i < 2048; i++) delete[] ret13[i];
	for (int i = 0; i < 2048; i++) delete[] ret14[i];
	for (int i = 0; i < 2048; i++) delete[] ret21[i];
	for (int i = 0; i < 2048; i++) delete[] ret22[i];
    for (int i = 0; i < 2048; i++) delete[] ret23[i];
	for (int i = 0; i < 2048; i++) delete[] ret24[i];
    for (int i = 0; i < 2048; i++) delete[] ret25[i];
	for (int i = 0; i < 2048; i++) delete[] ret26[i];
	for (int i = 0; i < 2048; i++) delete[] ret27[i];
    for (int i = 0; i < 2048; i++) delete[] ret28[i];
	for (int i = 0; i < 2048; i++) delete[] ret29[i];

    delete[] matA[i];
    delete[] matB[i];
    delete[] matI[i];
    delete[] matBT[i];
    delete[] ret11[i];
    delete[] ret12[i];
    delete[] ret13[i];
    delete[] ret14[i];
    delete[] ret21[i];
    delete[] ret22[i];
    delete[] ret23[i];
    delete[] ret24[i];
    delete[] ret25[i];
    delete[] ret26[i];
    delete[] ret27[i];
    delete[] ret28[i];
    delete[] ret29[i];
    return 0;
}