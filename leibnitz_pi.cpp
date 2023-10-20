#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double approximatePi(int n);

int main() {
  int n;
  cout<<"Enter n: ";
  cin>>n;
  double pi = approximatePi(n);
  cout << pi << endl;
  cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
  cout << "PI (actual): "
       << "3.141592653589793" << endl;
  cout << "Decimal digits of precision: " << DBL_DIG << endl;
  cout << "Number of base 2 mantissa digits of double precision floating point "
          "value: "
       << DBL_MANT_DIG << endl;
  cout << "Next representable number from 3.141592653589793: "
       << nextafter(3.141592653589793, 3.14) << endl;
}

double approximatePi(int n) {
  double pi = 0.0;
  for (int k = 0; k <= n; k++) {
    pi += (4.0 * (pow(-1.0L, k))) / (2.0 * k + 1);
  }
  return pi;
}
