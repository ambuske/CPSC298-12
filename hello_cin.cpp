/// @file <hello.cpp>
/// @brief <project hello>
/// @author <ambuske@chapman.edu>

#include <iostream>
#include <string>
using namespace std;
int main(){
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}