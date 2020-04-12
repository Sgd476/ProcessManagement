Haodong Ma  
200376168 


This project is about CPU scheduling. The major task of this project is processes scheduling.

1.When nothing is running in the system(the ready queue is empty), the system runs idle processes. Otherwise the system runs other process.(state change from READY to RUNNING)




2.While running the RUNNING process(include idle processes), it is possible to have state changes(RUNNING to BLOCK), which means running process may insert to the block queue. Other new processes may create PCB(Process Control Block), the state may change from BLOCK to READY, which means removing from block queue and inserting to ready queue.




3.At the end, if the cumulative time for a process occupies cpu is less than the time the process needs, then change the state from RUNNING to READY, which means the running process will be inserted into ready queue.


The challenge in this project is that I need to have a really clear and deep understanding of CPU scheduling, and it's algorithm.
