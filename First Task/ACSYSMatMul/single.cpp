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