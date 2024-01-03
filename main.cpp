#include <iostream>
#include <string>
#include "bigNum.h"

using namespace std;

int main()
{
  bigNum a = 25232345;
  bigNum b = "285293475283945729834502394823452345923";
  //cout << "enter a big num : ";
  //cin >> a;
  //cout << "enter another big num : ";
  //cin >> b;
  cout << "a = ";
  a.printDelimiter();
  cout << "b = ";
  b.printDelimiter();

  cout << "a + b = " << a + b << endl;//+ - * for two big nums
  cout << "a - b = " << a - b << endl;
  cout << "a * b = " << a * b << endl;
  cout << endl;
  long c = 21342;
  cout << "long c = " << c << endl;//+ - * for a big num and a long
  cout << "a + c = " << a + c << endl;
  cout << "a - c = " << a - c << endl;
  cout << "a * c = " << a * c << endl;
  cout << endl;
  if(a > b) cout << a << " > " << b << endl;//comparison between two big nums
  if(a < b) cout << a << " < " << b << endl;
  if(a >= b) cout << a << " >= " << b << endl;
  if(a <= b) cout << a << " <= " << b << endl;
  if(a == b) cout << a << " == " << b << endl;
  if(a != b) cout << a << " != " << b << endl;
  cout << endl;
  if(a > c) cout << a << " > " << c << endl;//comparison between a big num and a long
  if(a < c) cout << a << " < " << c << endl;
  if(a >= c) cout << a << " >= " << c << endl;
  if(a <= c) cout << a << " <= " << c << endl;
  if(a == c) cout << a << " == " << c << endl;
  if(a != c) cout << a << " != " << c << endl;
  cout << endl;
  a += b;
  cout << "a += b -> a =  " << a << endl;
  b *= 2;
  cout << "b *= 2 -> b = " << b << endl;
  
  cout << "\n\n";

  cout << "enter an index: ";
  int index;
  cin >> index;
  try{
    int digit = a[index];
    cout << "a = " << a << endl;
    cout << "a[" << index << "] = " << digit << endl;
  }
  catch(out_of_range &err){
    cout << err.what();
  }
}
