#include <iostream>

using namespace std;

class Single {
public:
    Single();
    void matmul(int** m1, int**m2, int** ret, int n);
    void transmatmul(int** m1, int**m2, int** ret, int n);
};