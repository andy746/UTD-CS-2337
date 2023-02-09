#ifndef CONSTANTTERM_H
#define CONSTANTTERM_H

#include <iostream>
#include <cmath>
#include "AbstractTerm.h"

using namespace std;

class ConstantTerm : public AbstractTerm {
  protected:
  int coefficient;
  public:
  ConstantTerm(){}
  ConstantTerm(int constant){
    this-> coefficient = constant;
  }
  ~ConstantTerm() {}
  AbstractTerm* derivative() override {
    AbstractTerm* d = new ConstantTerm(0);
    return d;
  }
  double evaluate(double num) override {
    return coefficient;
  }
  string toString() const override {
    if(coefficient > -1)
      return "+ " + to_string(coefficient) + " ";
    return "- " + to_string(coefficient * -1) + " ";
  }
  int getCoefficient() {
    return coefficient;
  }
};

#endif
