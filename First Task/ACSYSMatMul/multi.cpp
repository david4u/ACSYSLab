#include "multi.h"
#include <thread>
#include <vector>
/*

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

*/
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
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, 0, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul2(int**m1, int**m2, int**ret, int n) { // 0   1    
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, n/2, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul3(int**m1, int**m2, int**ret, int n) { // 0   2 
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n, n*3/4, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul4(int**m1, int**m2, int**ret, int n) { // 1   0
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, 0, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, 0, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul5(int**m1, int**m2, int**ret, int n) { // 1   1
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, n/2, n);

        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul6(int**m1, int**m2, int**ret, int n) { // 1   2
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/2, n*3/4, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n, n*3/4, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul7(int**m1, int**m2, int**ret, int n) { // 2   0
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, 0, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, 0, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, 0, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n, 0, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul8(int**m1, int**m2, int**ret, int n) { // 2   1
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n, n/2, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul9(int**m1, int**m2, int**ret, int n) { // 2   2   
    try {
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, 0, n/4, n*3/4, n);
        
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/4, n/2, n*3/4, n);
        
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n/2, n*3/4, n*3/4, n);
        
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n,  0, n/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m2, ret, n, n*3/4, n, n*3/4, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}