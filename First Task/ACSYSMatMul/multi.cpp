#include "multi.h"
#include <thread>
#include <vector>

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

void Multi::transmul(int** m1, int**m2, int** ret, int n, int startrow, int endrow, int startcol, int endcol) {
    for (int r = startrow; r < endrow; r++) {
        for (int c = startcol; c < endcol; c++) {
            for (int i = 0; i < n; i++) {
                ret[r][c] += m1[r][i] * m2[c][i];
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
// mat mul transpose

void Multi::matmul1T(int**m1, int**m2, int**ret, int n) { // 0   0
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        } 
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, 0, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul2T(int**m1, int**m2, int**ret, int n) { // 0   1    
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, n/2, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul3T(int**m1, int**m2, int**ret, int n) { // 0   2 
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n, n*3/4, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul4T(int**m1, int**m2, int**ret, int n) { // 1   0
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, 0, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, 0, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul5T(int**m1, int**m2, int**ret, int n) { // 1   1
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, n/2, n);

        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul6T(int**m1, int**m2, int**ret, int n) { // 1   2
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/2, n*3/4, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n, n*3/4, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul7T(int**m1, int**m2, int**ret, int n) { // 2   0
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, 0, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, 0, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, 0, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n, 0, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul8T(int**m1, int**m2, int**ret, int n) { // 2   1
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n, 0, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, n/2, n);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n, n/2, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}

void Multi::matmul9T(int**m1, int**m2, int**ret, int n) { // 2   2   
    try {
        int** m3 = new int*[n];
        for (int i = 0 ;i < n; i++) {
            m3[i] = new int[n];
            for (int  j= 0; j < n; j++) {
                m3[i][j] = m2[j][i];
            }
        }
        vector<thread> threads;
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, 0, n/4, n*3/4, n);
        
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/4, n/2, n*3/4, n);
        
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, 0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n/2, n*3/4, n*3/4, n);
        
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n,  0, n/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n, n/4, n/2);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n, n/2, n*3/4);
        threads.emplace_back(Multi::multiply, m1, m3, ret, n, n*3/4, n, n*3/4, n);
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        return;
    }
    catch (exception ex) {
        throw ex;
    }
}