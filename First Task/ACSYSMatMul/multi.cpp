#include "multi.h"

using namespace std;

void Multi::multiply(int** m1,int** m2, int** ret, int n, int startrow, int endrow, int startcol, int endcol) {
    for (int r = startrow; r < endrow; r++) {
        for (int c = startcol; c < endcol; c++) {
            for (int i = 0; i < n; i++) {
                ret[r][c] += m1[r][i] * m2[i][c];
            }
        }
    }
}
//                                                          i   j
void Multi::matmul1(int**m1, int**m2, int**ret, int n) { // 0   0

}

void Multi::matmul2(int**m1, int**m2, int**ret, int n) { // 0   1    
    
}

void Multi::matmul3(int**m1, int**m2, int**ret, int n) { // 0   2 
    
}

void Multi::matmul4(int**m1, int**m2, int**ret, int n) { // 1   0
    
}

void Multi::matmul5(int**m1, int**m2, int**ret, int n) { // 1   1
    
}

void Multi::matmul6(int**m1, int**m2, int**ret, int n) { // 1   2
    
}

void Multi::matmul7(int**m1, int**m2, int**ret, int n) { // 2   0
    
}

void Multi::matmul8(int**m1, int**m2, int**ret, int n) { // 2   1
    
}

void Multi::matmul9(int**m1, int**m2, int**ret, int n) { // 2   2   
    
}