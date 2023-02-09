#ifndef POLYNOMIALTERM_H
#define POLYNOMIALTERM_H

#include <iostream>
#include "LinearTerm.h"

using namespace std;

class PolynomialTerm : public LinearTerm {
  private:
  int exponent;
  public:
  PolynomialTerm(int coefficient, int exponent){
    this-> coefficient = coefficient;
    this-> exponent = exponent;
  }
  ~PolynomialTerm() {}
  AbstractTerm* derivative() override {
    if(exponent == 2) {
      AbstractTerm* d = new LinearTerm(coefficient * exponent);
      return d;
    }
    else {
      AbstractTerm* d = new PolynomialTerm(coefficient * exponent, exponent - 1);
      return d;
    }
  }
  double evaluate(double num) override {
    return coefficient * pow(num, exponent);
  }
  string toString() const override {
    if(coefficient < 0) {
      return "- " + to_string(coefficient * -1) + "x^" + to_string(exponent) + " ";
    }
    return "+ " + to_string(coefficient) + "x^" + to_string(exponent) + " ";
  }
  int getExponent() {
    return exponent;
  }
};

#endif
