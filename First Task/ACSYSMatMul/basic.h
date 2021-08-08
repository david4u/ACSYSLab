#include <random>

using namespace std;

class Basic {
public:
    int** makeMAT(int n);
    int** makeIdentity(int n);
    int** makeZero(int n);
    bool isSameResult(int** m1, int** m2, int n);
};