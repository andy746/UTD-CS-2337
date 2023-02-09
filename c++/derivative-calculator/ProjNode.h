#ifndef PROJNODE_H
#define PROJNODE_H

#include <iostream>
#include "PolynomialTerm.h"
#include "TrigTerm.h"

template<class T> 
class ProjNode
{
  public:
  T data;
  ProjNode* next;

  ProjNode() {
    next = NULL;
  }
  ~ProjNode() {}
};

#endif
