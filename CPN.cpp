#include <iostream>
#include <fstream>

using namespace std;

class CentralPolygonalNumbers{
  public:
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int nMax);
    ~CentralPolygonalNumbers();
    void display();
    void save(string strFilename);
  private:
    int m_nMax;
    int* mp_iNumbers;
};
//default constructor
CentralPolygonalNumbers::CentralPolygonalNumbers(): m_nMax(0){
  m_nMax = 0;
  mp_iNumbers = new int[1];
  mp_iNumbers[0] = 0;
}
//overloaded constructor
CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax): m_nMax(nMax){
  m_nMax = nMax;
  mp_iNumbers = new int[m_nMax+1];
  for(int i = 0; i <= m_nMax; i++){
    mp_iNumbers[i] = ((i *i) +i+2) / 2;
  }
}
//class destructor
CentralPolygonalNumbers::~CentralPolygonalNumbers(){
  delete[] mp_iNumbers;
  cout<<"~CentralPolygonalNumbers called"<<endl;
}
void CentralPolygonalNumbers::display(){
  for(int i = 0; i <= m_nMax; i++){
    cout<<"n: "<<i<<", "<<"maximum number of pieces: "<<mp_iNumbers[i]<<endl;
  }
  cout<<endl;
}
void CentralPolygonalNumbers::save(string strFilename){
  ofstream ofsNumbers(strFilename);
  for(int i = 0; i <= m_nMax; i++){
      ofsNumbers<<mp_iNumbers[i]<<endl;
    
  }
  ofsNumbers<<"~";
  ofsNumbers.close();
}
int main() {
  CentralPolygonalNumbers cpn(10);
  cpn.display();
  cpn.save("CPN");
  return 0;
}
