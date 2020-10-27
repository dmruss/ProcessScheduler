#ifndef QUEUE_HEAD
#define QUEUE_HEAD

struct Node {
  PCB* data;
  PCB* next;

  Node() {
    data = NULL;
    next = NULL;
  }

  Node(PCB* temp){
    data = NULL;
    next = NULL;
  }
};





#endif
