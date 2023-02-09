#include "StringHash.h"

#include <iostream>

using namespace std;

int main() {
  int size, initialValue, hashMultiplier, relativePrime;
  cout << "Enter table size: ";
  cin >> size;
  cout << "Enter initial hash value: ";
  cin >> initialValue;
  cout << "Enter hash multiplier: ";
  cin >> hashMultiplier;
  cout << "Enter relative prime value: ";
  cin >> relativePrime;
  StringHash* hash = new StringHash(size, initialValue, hashMultiplier, relativePrime);
  char letter = ' ';
  while(letter != 'Q') {
    string str = "";
    cout << "1. Search String" << endl;
    cout << "2. Add String" << endl;
    cout << "3. Remove String" << endl;
    cout << "4. Display Table" << endl;
    cout << "5. Resize Table" << endl;
    cout << "Q. Quit" << endl;
    cout << "Choice: ";
    cin >> letter;
    switch(letter) {
      case '1':
      cout << "String to search: ";
      cin >> str;
      hash->contains(str);
      break;
      case '2':
      cout << "String to add: ";
      cin >> str;
      hash->add(str);
      break;
      case '3':
      cout << "String to remove: ";
      cin >> str;
      hash->remove(str);
      break;
      case '4':
      hash->displayTable();
      break;
      case '5':
      hash->resize();
      break;
    }
  }
  return 0;
};
