#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Multi {
public:
	static void multiply(int** m1, int** m2, int** ret, int n, int startrow, int endrow, int startcol, int endcol);
	static void transmul(int** m1, int** m2, int** ret, int n, int startrow, int endrow, int startcol, int endcol);
	//														i	j
	void matmul1(int** m1, int** m2, int** m3, int n);	//	0	0
	void matmul2(int** m1, int** m2, int** m3, int n);	//	0	1
	void matmul3(int** m1, int** m2, int** m3, int n);	//	0	2
	void matmul4(int** m1, int** m2, int** m3, int n);	//	1	0
	void matmul5(int** m1, int** m2, int** m3, int n);	//	1	1
	void matmul6(int** m1, int** m2, int** m3, int n);	//	1	2
	void matmul7(int** m1, int** m2, int** m3, int n);	//	2	0
	void matmul8(int** m1, int** m2, int** m3, int n);	//	2	1
	void matmul9(int** m1, int** m2, int** m3, int n);	//	2	2

	void matmul1T(int** m1, int** m2, int** m3, int n);	//	0	0
	void matmul2T(int** m1, int** m2, int** m3, int n);	//	0	1
	void matmul3T(int** m1, int** m2, int** m3, int n);	//	0	2
	void matmul4T(int** m1, int** m2, int** m3, int n);	//	1	0
	void matmul5T(int** m1, int** m2, int** m3, int n);	//	1	1
	void matmul6T(int** m1, int** m2, int** m3, int n);	//	1	2
	void matmul7T(int** m1, int** m2, int** m3, int n);	//	2	0
	void matmul8T(int** m1, int** m2, int** m3, int n);	//	2	1
	void matmul9T(int** m1, int** m2, int** m3, int n);	//	2	2
};