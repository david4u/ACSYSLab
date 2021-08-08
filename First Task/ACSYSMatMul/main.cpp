#include "multi.h"
#include "single.h"
#include "basic.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
    // times[] -> single, single^T, multi~
    double times[11];
    int** matA;
    int** matB;
    int** matI;
    int** ret11;
    int** ret12;
    int** ret13;
    int** ret14;
    int** ret21;
    int** ret22;
    int** ret23;
    int** ret24;
    int** ret25;
    int** ret26;
    int** ret27;
    int** ret28;
    int** ret29;
    
    int size = 2048;
    Basic* basic;
    Single* single;
    Multi* multi;
    struct timespec begin, end;

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
    cout << "A x B in single thread start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
	single->matmul(matA, matB, ret11, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
	cout << "A x B in single thread end\n";
    times[0] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    // single thread A x I = ret12
    cout << "A x I in single thread start\n";
	single->matmul(matA, matI, ret12, 2048);
    cout << "A x I in single thread end\n";

    // single thread I x A = ret13
    cout << "I x A in single thread start\n";
	single->matmul(matI, matA, ret13, 2048);
    cout << "I x A in single thread end\n";
    // For validatoin ret12 == ret13 == matA
    cout << "Single thread validation check start\n";
    bool valid = true;
    for (int i = 0; i < 2048 ;i++) {
        for (int j = 0 ; j < 2048; j++) {
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
    cout << "Single thread transpose version start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    single->transmatmul(matA, matB, ret14, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Single thread transpose version end\n";
	times[1] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    cout << "Single thread transpose version validation check start\n";
    if (basic->isSameResult(ret11, ret14, 2048)) {
        cout << "Transpose matmul is correct\n";
    } else {
        cout << "Transpose matmul is incorrect\n";
    }

    // multi matmul. But ret21 is same with single
    cout << "Multi thread version 1 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul1(matA, matB, ret21, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 1 end\n";
	times[2] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret21, 2048)) {
        cout << "Multi Thread matmul1 is correct\n";
    } else {
        cout << "Multi Thread matmul1 is incorrect\n";
    }
    
    // multi matmul. Ret22 is 1x2
    cout << "Multi thread version 2 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul2(matA, matB, ret22, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 2 end\n";
	times[3] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret22, 2048)) {
        cout << "Multi Thread matmul2 is correct\n";
    } else {
        cout << "Multi Thread matmul2 is incorrect\n";
    }

    // multi matmul. Ret23 is 1x4
    cout << "Multi thread version 3 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul3(matA, matB, ret23, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 3 end\n";
	times[4] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret23, 2048)) {
        cout << "Multi Thread matmul3 is correct\n";
    } else {
        cout << "Multi Thread matmul3 is incorrect\n";
    }

    // multi matmul. Ret24 is 2x1
    cout << "Multi thread version 4 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul4(matA, matB, ret24, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 4 end\n";
	times[5] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret24, 2048)) {
        cout << "Multi Thread matmul4 is correct\n";
    } else {
        cout << "Multi Thread matmul4 is incorrect\n";
    }

    // multi matmul. Ret25 is 2x2
    cout << "Multi thread version 5 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul5(matA, matB, ret25, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 5 end\n";
	times[6] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret25, 2048)) {
        cout << "Multi Thread matmul5 is correct\n";
    } else {
        cout << "Multi Thread matmul5 is incorrect\n";
    }

    // multi matmul. Ret26 is 2x4
    cout << "Multi thread version 6 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul6(matA, matB, ret26, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 6 end\n";
	times[7] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret26, 2048)) {
        cout << "Multi Thread matmul6 is correct\n";
    } else {
        cout << "Multi Thread matmul6 is incorrect\n";
    }

    // multi matmul. Ret27 is 4x1
    cout << "Multi thread version 7 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul7(matA, matB, ret27, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 7 end\n";
	times[8] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret27, 2048)) {
        cout << "Multi Thread matmul7 is correct\n";
    } else {
        cout << "Multi Thread matmul7 is incorrect\n";
    }

    // multi matmul. Ret28 is 4x2
    cout << "Multi thread version 8 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul8(matA, matB, ret28, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 8 end\n";
	times[9] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret28, 2048)) {
        cout << "Multi Thread matmul8 is correct\n";
    } else {
        cout << "Multi Thread matmul8 is incorrect\n";
    }

    // multi matmul. Ret29 is 4x4
    cout << "Multi thread version 9 start\n";
	clock_gettime(CLOCK_MONOTONIC, &begin);
    multi->matmul9(matA, matB, ret29, 2048);
	clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "Multi thread version 9 end\n";
	times[10] = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    if (basic->isSameResult(ret11, ret29, 2048)) {
        cout << "Multi Thread matmul9 is correct\n";
    } else {
        cout << "Multi Thread matmul9 is incorrect\n";
    }
    string muls[11];
    muls[0] = "Single 1 x 1";
    muls[1] = "SIngle 1 x 1 Transpose";
    muls[2] = "Multi 1 x 1";
    muls[3] = "Multi 1 x 2";
    muls[4] = "Multi 1 x 4";
    muls[5] = "Multi 2 x 1";
    muls[6] = "Multi 2 x 2";
    muls[7] = "Multi 2 x 4";
    muls[8] = "Multi 4 x 1";
    muls[9] = "Multi 4 x 2";
    muls[10] = "Multi 4 x 4";
    for (int i = 0; i < 11; i++) {
        cout << muls[i] << " time is : " << times[i] << '\n';
    }
    // Delete Matrices
    for (int i = 0; i < 2048; i++) delete[] matA[i];
	for (int i = 0; i < 2048; i++) delete[] matB[i];
	for (int i = 0; i < 2048; i++) delete[] matI[i];
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

    delete[] matA;
    delete[] matB;
    delete[] matI;
    delete[] ret11;
    delete[] ret12;
    delete[] ret13;
    delete[] ret14;
    delete[] ret21;
    delete[] ret22;
    delete[] ret23;
    delete[] ret24;
    delete[] ret25;
    delete[] ret26;
    delete[] ret27;
    delete[] ret28;
    delete[] ret29;
    return 0;
}