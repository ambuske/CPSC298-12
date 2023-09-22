#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double ref = 16.35;
  double dtwR2 = pow(2, 12);
  double speedofSound = 345;
  double freqNote = 0;
  double wavelength = 0;
  long iRaisedToPowerN =0;
  cout << "Ref Freq: " << ref <<endl;
  cout << "Speed of Sound: " << speedofSound <<endl;
//C0
  freqNote = ref*pow(2, iRaisedToPowerN+(0/12.0));
  wavelength = speedofSound/freqNote;
  wavelength *= 100;
  cout << "Note: C0; nu: 0; k:0; frequency: "<< ref << " Hz; wavelength: "<< wavelength << " cm" <<endl;
//C#
  freqNote = ref*pow(2, iRaisedToPowerN+(1/12.0));
  wavelength = speedofSound/freqNote;
  wavelength *= 100;
  cout << "Note: C#; nu: 0; k:1; frequency: "<< freqNote << " Hz; wavelength: "<< wavelength << " cm" <<endl;
//D0
  freqNote = ref*pow(2, iRaisedToPowerN+(2/12.0));
  wavelength = speedofSound/freqNote;
  wavelength *= 100;
  cout << "Note: D0; nu: 0; k:1; frequency: "<< freqNote << " Hz; wavelength: "<< wavelength << " cm" <<endl;

  
//C4
  freqNote = ref*pow(2, 4+(0/12.0));
  wavelength = speedofSound/freqNote;
  wavelength *= 100;
  cout << "Note: C4; nu: 4; k:0; frequency: "<< freqNote << " Hz; wavelength: "<< wavelength << " cm" <<endl;

//D#7
  freqNote = ref*pow(2, 7+(3/12.0));
  wavelength = speedofSound/freqNote;
  wavelength *= 100;
  cout << "Note: D#7; nu: 7; k:3; frequency: "<< freqNote << " Hz; wavelength: "<< wavelength << " cm" <<endl;

//C8
  freqNote = ref*pow(2, 8+(0/12.0));
  wavelength = speedofSound/freqNote;
  wavelength *= 100;
  cout << "Note: C8; nu: 8; k:0; frequency: "<< freqNote << " Hz; wavelength: "<< wavelength << " cm" <<endl;
  
}
