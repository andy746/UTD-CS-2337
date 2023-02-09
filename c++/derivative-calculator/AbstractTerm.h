#ifndef ABSTRACTTERM_H
#define ABSTRACTTERM_H

#include <iostream>

using namespace std;

class AbstractTerm {
  public:
  AbstractTerm(){}
  ~AbstractTerm(){}
  virtual AbstractTerm* derivative() = 0;
  virtual double evaluate(double num) = 0;
  virtual string toString() const = 0;
};

#endif
