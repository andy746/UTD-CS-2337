#include <iostream>

#include "Expression.h"

using namespace std;

int main() {
  AbstractTerm* t1 = new LinearTerm(5);
  AbstractTerm* t2 = new PolynomialTerm(-4,3);
  AbstractTerm* t3 = new TrigTerm(-6,TrigType::COSINE);
  cout << t1->toString() << endl; // + 5x
  cout << t1->evaluate(5) << endl; // 25
  cout << t2->toString() << endl; // - 4x^3
  cout << t2->evaluate(2) << endl; // -32
  cout << t3->toString() << endl; // - 6cos(x)
  cout << t3->evaluate(45) << endl; // -4.24
  Expression* e1 = new Expression();
  (*e1) += t1;
  (*e1) += t2;
  (*e1) += t3;
  Expression* e2 = e1->getDerivative(); 
  cout << e1->toString() << endl; // - 4x^3 + 5x - 6cos(x)
  cout << e2->toString() << endl; // - 12x^2 + 5 + 6sin(x)
  cout << e1->getEvaluation(0) << endl; // -6
  cout << e2->getEvaluation(0) << endl; // 5
  delete e2;
  delete e1;
}
