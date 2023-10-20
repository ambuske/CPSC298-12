#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double approximatePi(int n);

int main() {
  int n = 1048576;
  double pi = approximatePi(1048576);
  for (int i=2; i<=1048576; i*=2){
    double pi = approximatePi(i);
    cout<<"PI: "<<pi<<" n: "<<i<<endl;
  }
}

double approximatePi(int n) {
  double pi = 0.0;
  for (int k = 0; k <= n; k++) {
    pi += (4.0 * (pow(-1.0L, k))) / (2.0 * k + 1);
  }
  return pi;
}
