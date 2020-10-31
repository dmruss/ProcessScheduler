#ifndef PCB_HEAD
#define PCB_HEAD

#include <iostream>

struct PCB {
  int pid;
  int arrival;
  int burst;
  int priority;
  float finish;
  float wait;
  float turnaround;
  float response;
  int contextSwitches;
  float runTime;

  PCB() {
    pid = 0;
    arrival = 0;
    burst = 0;
    priority = 0;
    wait = 0;
    turnaround = 0;
    response = 0;
    contextSwitches = 0;
    runTime = 0;
  }

  PCB(int pid, int arrival, int burst, int priority) {
    this->pid = pid;
    this->arrival = arrival;
    this->burst = burst;
    this->priority = priority;
    finish = 0;
    wait = 0;
    turnaround = 0;
    response = 0;
    contextSwitches = 0;
    runTime = 0;
  }

  void print() {
    std::cout << pid << ' ' << arrival << ' ' << burst << ' ' << priority << '\n';
  }


};


#endif
