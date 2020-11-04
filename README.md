# ProcessScheduler
Simulation to compare different process scheduling algorithms.  The algorithms implemented
are first come first serve, shortest job first, preemptive priority, and round robin.  Two
input files are included, input10.txt and input100.txt, which include 10 and 100 processes respectively.  Each process has a process id, an arrival time, a burst time, and a priority number.

## How it works
This program will read the input file and create a process control block for each process.  These PCBs will hold all information for each process including finish time, waiting time, turnaround time, response time, and the number of context switches.  The PCBs will then be stored in a queue.  The queue has been implemented using a linked list.  A priority queue has also been implemented using a linked list for use in the shortest job first and preemptive priority algorithms.


This scheduling algorithm will then begin its event loop, tracking time in 0.5 ms increments.  As the processes 'arrive', meaning the time matches their arrival time, they will be popped from the new process queue and added to the ready queue.  From the ready queue they may 1) be added to the running state queue if it is empty 2) sit in the ready queue until the running state queue is free 3) if preemptive priority, take the place of a running process with a lower priority.


The first come first serve algorithm runs processes until completion, sequentially as they arrive.  The shortest job first algorithm expands on this and uses a priority queue for the ready queue, organized by shortest burst time.  The preemptive priority algorithm also uses a priority queue as the ready queue, but organizes by priority number.  If a high priority process arrives, it will displace the current running process which will return to the ready queue.  The round robin algorithm does not use a priority queue for the ready queue, but rotates processes into the running state using a time quantum.  The time quantum is passed as an argument.  Both preemptive priority and round robin add in 0.5 ms of context switching overhead time when a process moves from the running state back to the ready state.  


In all four algorithms, when a process finishes it is stored in the done queue.  The processes are organized in the done queue by finish time.  When the algorithm finishes, it will print the average cpu burst time, average waiting time, average turnaround time, average response time, and the total number of context switches.




## How to run
  1) Navigate to root folder in a Unix CLI environment
  2) Build with makefile

      unixcommand>make


  3) Run scheduler from command line with arguments

      Arguments:

      unixcommand> ./myscheduler 'input_file' 'scheduling algorithm' 'quantum size'

      scheduling algorithm args: 0 = FCFS, 1 = SJF, 2 = PP, 3 = RR


      Example:

      unixcommand> ./myscheduler input10.txt 0

      unixcommand> ./myscheduler input100.txt 3 22
