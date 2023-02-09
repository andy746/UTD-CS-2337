#ifndef TRIGTERM_H
#define TRIGTERM_H

#include <iostream>
#include "LinearTerm.h"

using namespace std;

enum TrigType {COSINE, SINE};

class TrigTerm : public LinearTerm {
  private:
  TrigType trig;
  public:
  TrigTerm(int coefficient, TrigType trig) {
    this-> coefficient = coefficient;
    this-> trig = trig;
  }
  ~TrigTerm() {}
  AbstractTerm* derivative() override {
    if(trig == COSINE) {
      AbstractTerm* d = new TrigTerm(coefficient * -1, SINE);
      return d;
    }
    else {
      AbstractTerm* d = new TrigTerm(coefficient, COSINE);
      return d;
    }
  }
  double evaluate(double num) override {
    if(trig == COSINE) {
      return coefficient * cos(num * M_PI / 180.0);
    }
    return coefficient * sin(num * M_PI / 180.0);
  }
  string toString() const override {
    if(trig == COSINE) { 
      if(coefficient < 0) {
        return "- " + to_string(coefficient * -1) + "cos(x) ";
      }
      return "+ " + to_string(coefficient) + "cos(x) ";
    }
    if(coefficient < 0) {
        return "- " + to_string(coefficient * -1) + "sin(x) ";
    }
    return "+ " + to_string(coefficient) + "sin(x) ";
  }
};

#endif
