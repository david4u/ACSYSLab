#include "single.h"

using namespace std;

void Single::matmul(int** m1, int** m2, int** ret, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0 ;i < n; i++) {
                ret[r][c] += m1[r][i] * m2[i][c];
            }
        }
    }
}

void Single::transmatmul(int** m1, int** m2, int** ret, int n) {
    int** m3 = new int*[n];
    for (int i = 0 ;i < n; i++) {
        m3[i] = new int[n];
        for (int  j= 0; j < n; j++) {
            m3[i][j] = m2[j][i]
        }
    }
    for (int r = 0; r < n ; r++) {
        for (int c =0; c < n; c++) {
            for (int i = 0; i < n; i++) {
                ret[r][c] += m1[r][i] * m3[c][i];
            }
        }
    }
}