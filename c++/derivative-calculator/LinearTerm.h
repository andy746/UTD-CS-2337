#ifndef LINEARTERM_H
#define LINEARTERM_H

#include <iostream>
#include "ConstantTerm.h"

using namespace std;

class LinearTerm : public ConstantTerm {
  public:
  LinearTerm(){}
  LinearTerm(int coefficient) {
    this->coefficient = coefficient;
  }
  ~LinearTerm() {}
  AbstractTerm* derivative() override {
    AbstractTerm* d = new ConstantTerm(coefficient);
    return d;
  }
  double evaluate(double num) override {
    return coefficient * num;
  }
  string toString() const override {
    if(coefficient < 0) {
      return "- " + to_string(coefficient * -1) + "x ";
    }
    return "+ " + to_string(coefficient) + "x ";
  }
};

#endif
