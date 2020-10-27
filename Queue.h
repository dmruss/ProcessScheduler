#ifndef QUEUE_HEAD
#define QUEUE_HEAD

struct Node {
  PCB* data;
  Node* next;

  Node() {
    data = NULL;
    next = NULL;
  }

  Node(PCB* temp){
    data = temp;
    next = NULL;
  }


};

struct Queue {
  Node *front, *rear;
  Queue() {
    front = NULL;
    rear = NULL;
  }

  void Enqueue(PCB* aPCB){
    Node* temp = new Node(aPCB);
    if (front == NULL) {
      front = temp;
      rear = temp;
      front->next = NULL;
    }
    else {
      rear->next = temp;
      rear = temp;
      rear->next = NULL;
    }
  }

  void print() {
    Node* current = front;
    while (current != NULL) {
      std::cout << current->data->pid << std::endl;
      current = current->next;
    }
  }
};




#endif
