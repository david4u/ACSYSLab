#include "multi.h"
#include "single.h"
#include "basic.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

int main() {
    vector<double> times[11];
    struct timespec begin, end;
    int** mat1 = Basic::makeMAT(2048);
    int** mat2 = Basic::makeMAT(2048);
    
}