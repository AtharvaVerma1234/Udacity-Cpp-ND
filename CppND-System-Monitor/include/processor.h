#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>
#include "linux_parser.h"
#include <string>
#include <vector>
class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  long TJiffies{0};
  long IJiffies{0};
  double usage{0.0};
};
#endif