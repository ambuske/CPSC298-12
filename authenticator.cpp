#include <iostream>
using namespace std;
#include <string>



int main() {
  string message = "";
  string auth = "";
  char u_char1;
  char u_char2;
  char u_char3;
  char a_char1 = 'E';
  char a_char2 = 'C';
  char a_char3 = 'A';
  int total;
  auth += a_char1;
  auth+=a_char2;
  auth+=a_char3;
  
  cout << "Enter the 1st char"<<endl;
  cin >> u_char1;
  message+=u_char1;
  cout << "Enter the 2nd char"<<endl;
  cin >> u_char2;
  message+=u_char2;
  cout << "Enter the 3rd char"<<endl;
  cin >> u_char3;
  message+=u_char3;
  cout<<"Authenticator Code: "<<auth<<endl;
  cout<<"Message Code: "<<message<<endl;
  
  if(u_char1==a_char1 && u_char2==a_char2 && u_char3==a_char3){
    cout<<"Message is Authentic."<<endl;
  }else{
    cout<<"Message is invalid."<<endl;
  }
  if(message == auth){
    cout<<"concurrence: Message is Authentic."<<endl;
  }else{
    cout<<"concurrence: Message is invalid."<<endl;
  }
  cout<<"\nCharacterization of Message Code\n-----------------------------------------------"<<endl;

  int checksum = (int(u_char1)+int(u_char2)+int(u_char3))%7;
  const int validchecksum = 5;
  
  int ascicc1 = int(u_char1);
  int ascicc2 = int(u_char2);
  int ascicc3 = int(u_char3);
  int ascicc4 = int(a_char1);
  int ascicc5 = int(a_char2);
  int ascicc6 = int(a_char3);
  cout<<"ASCII Values of Message Code Characters: "<< ascicc1<<", "<< ascicc2<<", "<< ascicc3<<endl;
  total= ascicc1 + ascicc2 + ascicc3;
  int totala= ascicc4 + ascicc5 + ascicc6;
  cout<<"Sum of ASCII values for Message Code Characters: "<<total<<endl;
  if(checksum == validchecksum){
      cout<<"Message code Checksum is valid: 5"<<endl;
  }else{
    cout<<"Message code Checksum is invalid: "<<checksum<<"; expected: 5"<<endl;
  }
  if(u_char1!=a_char1){
    cout<<"First characters do not match: Message: "<<u_char1<<"; Authenticator: E"<<endl;
  }
  if(u_char2!=a_char2){
    cout<<"Second characters do not match: Message: "<<u_char2<<"; Authenticator: C"<<endl;
  }
  if(u_char3!=a_char3){
    cout<<"Third characters do not match: Message: "<<u_char3<<"; Authenticator: A"<<endl;
  }
  if(total<totala){
    cout<<"Message code (NSA) is lexicographically greater than Authenticator code (ECA)"<<endl;
  }else if (total>totala){
    cout<<"Message code (NSA) is lexicographically less than Authenticator code (ECA)"<<endl;
  }

}
