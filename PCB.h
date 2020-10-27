#ifndef PCB_HEAD
#define PCB_HEAD

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

  PCB() {
    pid = 0;
    arrival = 0;
    burst = 0;
    priority = 0;
  }

  PCB(int pid; int arrival; int burst; int priority) {
    this->pid = pid;
    this->arrival = arrival;
    this->burst = burst;
    this->priority = priority;
  }


}


#endif
