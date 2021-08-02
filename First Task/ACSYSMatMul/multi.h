#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Multi {
public:
	void multiply(int** m1,int** m2, int** ret, int n, int startrow, int endrow, int startcol, int endcol);
	void matmul1(int** m1, int** m2, int** m3, int n);
};