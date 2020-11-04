#include <iostream>
#include <string>
#include <fstream>
#include "PCB.h"
#include "Queue.h"
#include "Scheduling.h"

Queue* ReadInput(std::string filename);


int main(int argc, char* argv[]) {
  Queue* newProcessQueue = new Queue();

  if (argc == 3)
  {
    if (atoi(argv[2]) == 0) {
      Queue* newProcessQueue = ReadInput(argv[1]);
      std::cout << "FCFS\n";
      Queue* finishedFCFS = Fcfs(newProcessQueue);
      finishedFCFS->print();
      finishedFCFS->printStats();
      std::cout << '\n';
    }
    else if (atoi(argv[2]) == 1) {
      std::cout << "SJF\n";
      newProcessQueue = ReadInput(argv[1]);
      Queue* finishedSJF = SJF(newProcessQueue);
      finishedSJF->print();
      finishedSJF->printStats();
      std::cout << '\n';

    }
    else if (atoi(argv[2]) == 2) {
      std::cout << "PP\n";
      newProcessQueue = ReadInput(argv[1]);
      Queue* finishedPP = PP(newProcessQueue);
      finishedPP->print();
      finishedPP->printStats();
      std::cout << '\n';
    }else {
      std::cout << "Unrecognized command\n";
    }

  }else {


    std::cout << "RR, Time Quantum: " << argv[3] << "\n";
    newProcessQueue = ReadInput(argv[1]);
    Queue* finishedRR12 = RR(newProcessQueue, atoi(argv[3]));
    finishedRR12->print();
    finishedRR12->printStats();
    std::cout << '\n';


}


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
