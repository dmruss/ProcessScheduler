# ProcessScheduler
Simulation to compare different process scheduling algorithms.  The algorithms implemented
are first come first serve, shortest job first, preemptive priority, and round robin.  Two
input files are included, input10.txt and input100.txt, which include 10 and 100 processes respectively.  Each process has a process id, an arrival time, a burst time, and a priority number.

This program will read the input file and create a process control block for each process.  These PCBs will hold all information for each process including finish time, waiting time, turnaround time, response time, and the number of context switches.  The PCBs will then be stored in a queue.  

## How to run
  1) Navigate to root folder in a Unix CLI environment
  2) Build with makefile
  
      unixcommand>make
  3) Run scheduler from command line with arguments

      unixcommand> ./myscheduler 'input_file' 'scheduling algorithm' 'quantum size'
      scheduling algorithm args: 0 = FCFS, 1 = SJF, 2 = PP, 3 = RR

      Example:
      unixcommand> ./myscheduler input10.txt 0
      unixcommand> ./myscheduler input100.txt 3 22
