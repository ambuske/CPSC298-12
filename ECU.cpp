#include <iostream>
using namespace std;

class ElectronicControlUnit {
public:
  void handleCommand(char cCommand);

private:
  bool m_bActivatedHydraulicJacks;
  bool m_bActivatedBeltTires;
  bool m_bActivatedIRIllumination;

  void actuateHydraulicJacks() {
    m_bActivatedHydraulicJacks = !m_bActivatedHydraulicJacks;
    cout << "Hydraulic Jacks " << (m_bActivatedHydraulicJacks ? "Activated" : "Deactivated") << endl;
  }

  void actuateBeltTires() {
    m_bActivatedBeltTires = !m_bActivatedBeltTires;
    cout << "Belt Tires " << (m_bActivatedBeltTires ? "Activated" : "Deactivated") << endl;
  }

  void actuateIRIllumination() {
    m_bActivatedIRIllumination = !m_bActivatedIRIllumination;
    cout << "IR Illumination " << (m_bActivatedIRIllumination ? "Activated" : "Deactivated") << endl;
  }
};

void ElectronicControlUnit::handleCommand(char cCommand) {
  switch (cCommand) {
    case 'A':
    case 'a':
      actuateHydraulicJacks();
      break;
    case 'B':
    case 'b':
      actuateBeltTires();
      break;
    case 'E':
    case 'e':
      actuateIRIllumination();
      break;
    default:
      cout << "Invalid command" << endl;
  }
}
int main() {
    ElectronicControlUnit ecu;

    char userInput;
    do {
      cout << "Press X to turn off ignition or enter a steering wheel button (A, B or E)"<<endl;
      cout<<"  (A)"<<endl;
      cout<<"(F)(G)(B)"<<endl;
      cout<<"(E) (C)"<<endl;
      cout<<"  (D)"<<endl;
        cin >> userInput;
        ecu.handleCommand(userInput);
    } while (toupper(userInput) != 'X');

    cout << "Ignition turned off. Program ended." << endl;
    return 0;
}
