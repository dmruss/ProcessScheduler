#include <iostream>
#include <string>
#include <fstream>
#include "PCB.h"
#include "Queue.h"

void ReadInput(std::string filename);


int main() {
  ReadInput("input10.txt");

  return 0;
}



void ReadInput(std::string filename){
  std::ifstream infile(filename);
  int pid, arrival, burst, priority;
  while (infile >> pid >> arrival >> burst >> priority){
    PCB* temp = new PCB(pid, arrival, burst, priority);
    temp->print();
  }
}
