#ifndef STRINGHASH_H
#define STRINGHASH_H

#include <iostream>

using namespace std;

class StringHash {
  public:
  StringHash(int size, int initialValue, int hashMultiplier, int relativePrime) {
    tableSize = size;
    table = new string[tableSize];
    this->initialValue = initialValue;
    this->hashMultiplier = hashMultiplier;
    this->relativePrime = relativePrime;
    for (int i = 0; i < tableSize; i++) {
      table[i] = "<EMPTY>";
    }
    trueSize = 0;
  }
  bool contains(string data);
  bool add(string data);
  bool remove(string data);
  void displayTable() {
    for(int i = 0; i < tableSize; i++) {
      cout << " " << i << " : " << table[i] << endl;
    }
  }
  void resize();
  int hash1(string key) {
    int stringHash = initialValue;
    for (unsigned int i = 0; i < key.length(); i++) {
       stringHash = (stringHash * hashMultiplier) + key.at(i);
    }
    if(stringHash < 0) {
       stringHash*=-1;
    }
    return stringHash % tableSize;
  }
  int hash2(string key) {
    int result = hash1(key);
    return relativePrime - (result % relativePrime);
  }
  private:
  string* table;
  int tableSize;
  int trueSize;
  int initialValue;
  int hashMultiplier; 
  int relativePrime;
};
//*(table + i) = table[i]
#endif
