#include <iostream>
using namespace std;

#include "StringHash.h"

bool StringHash::contains(string data) {
   //Hash functions
    int h_1 = hash1(data);
    int h_2 = hash2(data);
    
    int index = 0;
    int bucket = 0;
    cout << "Searching \"" << data << "\"";
    while (index < trueSize) {
      bucket = (h_1 + (index * h_2))  % tableSize;
      if(table[bucket] == data) {
        cout << " -> " << bucket << endl;
        cout << "TRUE " << endl;
        return true;
      }
      else if (table[bucket] == "<EMPTY>") {
        cout << " -> " << bucket;
        break;
      }
      else {
        cout << " -> " << bucket;
      }
      index++;
    }

    cout << " -> FAILED " << endl;
    cout << "FALSE " << endl;
    return false;
}

bool StringHash::add(string data) {
   //Hash functions
    int h_1 = hash1(data);
    int h_2 = hash2(data);
    
    int index = 0;
    int bucket = 0;
    cout << "Adding \"" << data << "\"";
    while (index < tableSize) {
      bucket = (h_1 + (index * h_2))  % tableSize;
      if(table[bucket] == "<EMPTY>") {
        cout << " -> " << bucket << endl;
        table[bucket] = data;
        trueSize++;
        return true;
      }
      else {
        cout << " -> " << bucket;
      }
      index++;
    }
    cout << " -> FAILED " << endl;
    return false;
}

bool StringHash::remove(string data) {
   //Hash functions
    int h_1 = hash1(data);
    int h_2 = hash2(data);
    
    int index = 0;
    int bucket = 0;
    cout << "Removing \"" << data << "\"";
    while (index < trueSize) {
      bucket = (h_1 + (index * h_2))  % tableSize;
      if(table[bucket] == data) {
        cout << " -> " << bucket << endl;
        table[bucket] = "<REMOVED>";
        trueSize--;
        return true;
      }
      else if (table[bucket] == "<EMPTY>") {
        cout << " -> " << bucket;
        break;
      }
      else {
        cout << " -> " << bucket;
      }
      index++;
    }
    cout << " -> FAILED " << endl;
    return false;
}
void StringHash::resize() {
    string* temp = new string[tableSize];
    for (int i = 0; i < tableSize; i++) {
      temp[i] = table[i];
    }
    tableSize*=2;
    table = new string[tableSize];
    for (int i = 0; i < (tableSize); i++) {
      table[i] = "<EMPTY>";
    }

    int h_1 = 0;
    int h_2 = 0;
    int index = 0;
    
    int bucket = 0;
    while (bucket < tableSize / 2) {
      if (temp[bucket] != "<EMPTY>" && temp[bucket] != "<REMOVED>") {
        h_1 = hash1(temp[bucket]);
        h_2 = hash2(temp[bucket]);
        cout << "Rehashing \"" << temp[bucket] << "\"";
        for (int i = 0; i < tableSize; i++) {
            index = (h_1 + (i * h_2))  % tableSize;
            if(table[index] == "<EMPTY>") {
               cout << " -> " << index << " " << endl;
               table[index] = temp[bucket];
               break;
            }
            if (i != (tableSize - 1)) {
               cout << " -> " << index;
            }
        }
      }
      bucket = bucket + 1;
    }
  }
