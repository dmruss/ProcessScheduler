#ifndef SCHEDULING_H
#define SCHEDULING_H

Queue* Fcfs(Queue* newProcessQueue) {
  float time = 0.0;
  int numProcesses = newProcessQueue->size;
  Queue* readyQueue = new Queue();
  Queue* runningQueue = new Queue();
  Queue* doneQueue = new Queue();

  bool processesRemaining = (doneQueue->size != numProcesses);
  bool runningQueueEmpty = (runningQueue->front == NULL);
  bool processArrives = (newProcessQueue->front->data->arrival == time);
  bool processFinished = false;

  while (processesRemaining) {
    if (newProcessQueue->size > 0) {
      processArrives = (newProcessQueue->front->data->arrival == time);
    }else {
      processArrives = false;
    }
    runningQueueEmpty = (runningQueue->front == NULL);
    if (!runningQueueEmpty) {
      processFinished = (time == (runningQueue->front->data->response + runningQueue->front->data->arrival + runningQueue->front->data->burst));
    }else {
      processFinished = false;
    }

    if (processArrives) {
      readyQueue->Enqueue(newProcessQueue->front->data);
      newProcessQueue->deQueue();
    }
    if (processFinished) {
      doneQueue->Enqueue(runningQueue->front->data);
      runningQueue->deQueue();
      doneQueue->rear->data->finish = time;
      doneQueue->rear->data->turnaround = time - doneQueue->rear->data->arrival;
      runningQueueEmpty = true;
    }
    if (runningQueueEmpty && readyQueue->size > 0) {
      runningQueue->Enqueue(readyQueue->front->data);
      readyQueue->deQueue();
      runningQueue->front->data->response = (time - runningQueue->front->data->arrival);
      runningQueueEmpty = false;
    }


    Node* addWaitTime = readyQueue->front;
    while (addWaitTime != NULL) {
      addWaitTime->data->wait += 0.5;
      addWaitTime = addWaitTime->next;
    }

    time += 0.5;

    processesRemaining = (doneQueue->size != numProcesses);
  }
  return doneQueue;

}


Queue* SJF(Queue* newProcessQueue) {
  float time = 0.0;
  int numProcesses = newProcessQueue->size;
  BurstPQueue* readyQueue = new BurstPQueue();
  Queue* runningQueue = new Queue();
  Queue* doneQueue = new Queue();

  bool processesRemaining = (doneQueue->size != numProcesses);
  bool runningQueueEmpty = (runningQueue->front == NULL);
  bool processArrives = false;
  bool processFinished = false;

  while (processesRemaining) {
    std::cout << "time: " << time << '\n';
    if (newProcessQueue->size > 0) {
      processArrives = (newProcessQueue->front->data->arrival == time);
    }else {
      processArrives = false;
    }
    std::cout << "check 1\n";
    runningQueueEmpty = (runningQueue->front == NULL);
    if (!runningQueueEmpty) {
      processFinished = (time == (runningQueue->front->data->response + runningQueue->front->data->arrival + runningQueue->front->data->burst));
    }else {
      processFinished = false;
    }
    std::cout << "check 2\n";
    if (processArrives) {
      readyQueue->Enqueue(newProcessQueue->front->data);
      newProcessQueue->deQueue();

    }
    std::cout << "check 3\n";
    if (processFinished) {
      doneQueue->Enqueue(runningQueue->front->data);
      runningQueue->deQueue();
      doneQueue->rear->data->finish = time;
      doneQueue->rear->data->turnaround = time - doneQueue->rear->data->arrival;
      runningQueueEmpty = true;
    }
    std::cout << "check 4\n";
    if (runningQueueEmpty && readyQueue->size > 0) {
      runningQueue->Enqueue(readyQueue->front->data);
      readyQueue->deQueue();
      runningQueue->front->data->response = (time - runningQueue->front->data->arrival);
      runningQueueEmpty = false;
    }
    std::cout << "check 5\n";

    Node* addWaitTime = readyQueue->front;
    std::cout << "ready queue size: " << readyQueue->size << "\n";
    std::cout << "newprocess queue size: " << newProcessQueue->size << '\n';
    /*while (addWaitTime != NULL) {
      std::cout << addWaitTime->data->pid << std::endl;
      addWaitTime->data->wait += 0.5;
      addWaitTime = addWaitTime->next;
    }*/
    std::cout << "check 7\n";
    time += 0.5;

    processesRemaining = (doneQueue->size != numProcesses);

    std::cout << "Ready Queue\n";
    readyQueue->print();
    std::cout << "check 7\n";
    std::cout << "Running Queue\n";
    runningQueue->print();
    std::cout << "Done Queue\n";
    doneQueue->print();
    std::cout << '\n';
  }
  return doneQueue;

}

Queue* PP(Queue* newProcessQueue) {
  float time = 0.0;
  int numProcesses = newProcessQueue->size;
  PriorityPQueue* readyQueue = new PriorityPQueue();
  Queue* runningQueue = new Queue();
  Queue* doneQueue = new Queue();

  bool processesRemaining = (doneQueue->size != numProcesses);
  bool runningQueueEmpty = (runningQueue->front == NULL);
  bool processArrives = false;
  bool processFinished = false;
  bool higherPriorityArrived = false;

  while (processesRemaining) {
    if (newProcessQueue->size > 0) {
      processArrives = (newProcessQueue->front->data->arrival == time);
    }else {
      processArrives = false;
    }
    runningQueueEmpty = (runningQueue->front == NULL);
    if (!runningQueueEmpty) {
      processFinished = (time == (runningQueue->front->data->response + runningQueue->front->data->arrival + runningQueue->front->data->burst));
    }else {
      processFinished = false;
    }
    if (readyQueue->size > 0 && !runningQueueEmpty) {
      if (readyQueue->front->data->priority != runningQueue->front->data->priority) {
        higherPriorityArrived = (readyQueue->front->data->priority < runningQueue->front->data->priority);
      }else {
        higherPriorityArrived = false;
      }
    }else {
      higherPriorityArrived = false;
    }


    if (processArrives) {
      readyQueue->Enqueue(newProcessQueue->front->data);
      newProcessQueue->deQueue();

    }
    if (processFinished) {
      doneQueue->Enqueue(runningQueue->front->data);
      runningQueue->deQueue();
      doneQueue->rear->data->finish = time;
      doneQueue->rear->data->turnaround = time - doneQueue->rear->data->arrival;
      runningQueueEmpty = true;
    }
    if (higherPriorityArrived) {
      //add in overhead
      runningQueue->front->data->contextSwitches += 1;
      readyQueue->Enqueue(runningQueue->front->data);
      runningQueue->deQueue();
      runningQueue->Enqueue(readyQueue->front->data);
      readyQueue->deQueue();
    }
    if (runningQueueEmpty && readyQueue->size > 0) {
      runningQueue->Enqueue(readyQueue->front->data);
      readyQueue->deQueue();
      runningQueue->front->data->response = (time - runningQueue->front->data->arrival);
      runningQueueEmpty = false;
    }


    Node* addWaitTime = readyQueue->front;
    while (addWaitTime != NULL) {
      addWaitTime->data->wait += 0.5;
      addWaitTime = addWaitTime->next;
    }

    time += 0.5;

    processesRemaining = (doneQueue->size != numProcesses);

    std::cout << "Ready Queue\n";
    readyQueue->print();
    std::cout << "Running Queue\n";
    runningQueue->print();
    std::cout << "Done Queue\n";
    doneQueue->print();
    std::cout << '\n';
  }
  return doneQueue;

}


#endif
