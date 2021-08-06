#include "multi.h"
#include "single.h"
#include "basic.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
    double times[11];
    int** matA, matB, matI, matBT;
    int** ret11, ret12, ret13, ret14, ret21, ret22, 
        ret23, ret24, ret25, ret26, ret27, ret28, ret29;
    int size = 2048;
    
    matA = Basic::makeMAT(size);
    matB = Basic::makeMAT(size);
    
    matI = Basic::makeIdentity(size);

    ret11 = Basic::makeZero(size);
    ret12 = Basic::makeZero(size);
    ret13 = Basic::makeZero(size);
    ret14 = Basic::makeZero(size);
    ret21 = Basic::makeZero(size);
    ret22 = Basic::makeZero(size);
    ret23 = Basic::makeZero(size);
    ret24 = Basic::makeZero(size);
    ret25 = Basic::makeZero(size);
    ret26 = Basic::makeZero(size);
    ret27 = Basic::makeZero(size);
    ret28 = Basic::makeZero(size);
    ret29 = Basic::makeZero(size);



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