#include <iostream>
#include <string>
#include <fstream>
#include "PCB.h"
#include "Queue.h"
#include "Scheduling.h"

Queue* ReadInput(std::string filename);


int main() {
  Queue* newProcessQueue = ReadInput("input100.txt");
  std::cout << "Input Processes\n";
  //newProcessQueue->print();

  std::cout << "FCFS\n";
  Queue* finishedFCFS = Fcfs(newProcessQueue);
  //finishedFCFS->print();
  finishedFCFS->printStats();
  std::cout << '\n';

  std::cout << "SJF\n";
  newProcessQueue = ReadInput("input100.txt");
  Queue* finishedSJF = SJF(newProcessQueue);
  //finishedSJF->print();
  finishedSJF->printStats();

  std::cout << "PP\n";
  newProcessQueue = ReadInput("input100.txt");
  Queue* finishedPP = PP(newProcessQueue);
  //finishedPP->print();
  finishedPP->printStats();

  std::cout << "RR\n";
  newProcessQueue = ReadInput("input100.txt");
  Queue* finishedRR = RR(newProcessQueue, 22);
  //finishedRR->print();
  finishedRR->printStats();


  return 0;
}



Queue* ReadInput(std::string filename){
  std::ifstream infile(filename);
  int pid, arrival, burst, priority;
  Queue* newProcessQueue = new Queue();

  while (infile >> pid >> arrival >> burst >> priority){
    PCB* temp = new PCB(pid, arrival, burst, priority);
    newProcessQueue->Enqueue(temp);

    //temp->print();
  }
  //newProcessQueue->print();
  return newProcessQueue;
}
