#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include "ProjLinkedList.h"

class Expression 
{
  private:
  ProjLinkedList<AbstractTerm*> list;
  ProjLinkedList<AbstractTerm*> constantList;
  ProjLinkedList<AbstractTerm*> linearList;
  ProjLinkedList<AbstractTerm*> polyList;
  ProjLinkedList<AbstractTerm*> trigList;
  public:
  Expression(){}
  Expression(const Expression& target) {
    ProjNode<AbstractTerm*>* curNode = target.constantList.head;
    while (curNode != NULL) { 
      constantList.add(curNode->data);
      curNode = curNode->next;
    }

    curNode = target.linearList.head;
    while (curNode != NULL) { 
      linearList.add(curNode->data);
      curNode = curNode->next;
    }

    curNode = target.polyList.head;
    while (curNode != NULL) { 
      polyList.add(curNode->data);
      curNode = curNode->next;
    }

    curNode = target.trigList.head;
    while (curNode != NULL) { 
      trigList.add(curNode->data);
      curNode = curNode->next;
    }
  }
  ~Expression() {}
  Expression* getDerivative() {
    Expression* exp = new Expression;
    ProjNode<AbstractTerm*>* curNode = this->constantList.head;
    while (curNode != NULL) { 
      exp->constantList.add(curNode->data->derivative());
      curNode = curNode->next;
    }

    curNode = this->linearList.head;
    while (curNode != NULL) { 
      exp->constantList.add(curNode->data->derivative());
      curNode = curNode->next;
    }

    curNode = this->polyList.head;
    while (curNode != NULL) { 
      if (dynamic_cast<PolynomialTerm*>(curNode->data)->getExponent() != 2) {
        exp->polyList.add(curNode->data->derivative());
      }
      else {
        exp->linearList.add(curNode->data->derivative());
      }
      curNode = curNode->next;
    }

    curNode = this->trigList.head;
    while (curNode != NULL) { 
      exp->trigList.add(curNode->data->derivative());
      curNode = curNode->next;
    }
    return exp;
  }
  double getEvaluation(double num) {
    double sum = 0;
    
    ProjNode<AbstractTerm*>* curNode = this->constantList.head;
    while (curNode != NULL) { 
      sum += curNode->data->evaluate(num);
      curNode = curNode->next;
    }

    curNode = this->linearList.head;
    while (curNode != NULL) { 
      sum += curNode->data->evaluate(num);
      curNode = curNode->next;
    }

    curNode = this->polyList.head;
    while (curNode != NULL) { 
      sum += curNode->data->evaluate(num);
      curNode = curNode->next;
    }

    curNode = this->trigList.head;
    while (curNode != NULL) { 
      sum += curNode->data->evaluate(num);
      curNode = curNode->next;
    }
    
    return sum;
  }
  string toString() {
    string str = "";

    ProjNode<AbstractTerm*>* curNode = this->polyList.head;
    while (curNode != NULL) { 
      str += curNode->data->toString();
      curNode = curNode->next;
    }

    curNode = this->linearList.head;
    while (curNode != NULL) { 
      str += curNode->data->toString();
      curNode = curNode->next;
    }

    curNode = this->constantList.head;
    while (curNode != NULL) { 
      if (dynamic_cast<ConstantTerm*>(curNode->data)->getCoefficient() != 0) {
        str += curNode->data->toString();
      }
      curNode = curNode->next;
    }
    
    curNode = this->trigList.head;
    while (curNode != NULL) { 
      str += curNode->data->toString();
      curNode = curNode->next;
    }
    
    return str;
  }
  Expression operator+=(AbstractTerm* term) {
    if(dynamic_cast<PolynomialTerm*>(term) != NULL) {
      polyList.add(term);
    }
    else if(dynamic_cast<TrigTerm*>(term) != NULL) {
      trigList.add(term);
    }
    else if(dynamic_cast<LinearTerm*>(term) != NULL) {
      linearList.add(term);
    }
    else if(dynamic_cast<ConstantTerm*>(term) != NULL) {
      constantList.add(term);
    }
    return *this;
  }
};

#endif
